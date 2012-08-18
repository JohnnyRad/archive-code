<?xml?>
<!--
    Copyright (c) 1996-2009 iMatix Corporation

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at
    your option) any later version.

    This program is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    For information on alternative licensing for OEMs, please contact
    iMatix Corporation.
 -->
<class
    name      = "ipr_log"
    comment   = "Log file management"
    version   = "1.0"
    script    = "icl_gen"
    >

<inherit class = "icl_base" />
<import class = "icl_shortstr" />
<import class = "ipr_file" />
<import class = "ipr_process" />

<method name = "cycle" return = "rc">
    <doc>
    Cycles an application log file:
     - the file must exist
     - if required we move the file to some directory
     - we generate a unique archive name for the file
     - we rename the file to the archive name
     - if required we run a command on the archived file
     - if the file is empty, it is deleted, and not archived
    </doc>
    <argument name = "filename"  type = "char *">File to examine</argument>
    <argument name = "directory" type = "char *">Archive directory, or NULL</argument>
    <argument name = "command"   type = "char *">Command to run</argument>
    <declare name = "rc" type = "int" default = "0" />
    //
    <local>
    icl_shortstr_t
        stamped_name,                   //  File name, time-stamped
        destination;                    //  New name of file
    ipr_process_t
        *process;                       //  Cycler process
    </local>
    //
    assert (filename);
    if (ipr_file_exists (filename)) {
        if (ipr_file_size (filename)) {
            icl_shortstr_cpy (destination, filename);
            if (directory) {
                ipr_file_set_path (destination, directory);
                ipr_file_rename (destination, filename);
            }
            s_timestamp_filename (stamped_name, destination);
            rc = ipr_file_rename (stamped_name, destination);
            if (command && *command) {
                icl_shortstr_fmt (destination, "%s %s", command, stamped_name);
                process = ipr_process_new (destination, NULL, NULL, NULL);
                ipr_process_start (process, ".");
                ipr_process_wait  (process, TRUE);
                rc = process->exitcode;
                ipr_process_destroy (&process);
            }
        }
        else
            //  To cycle an empty file, we delete it
            ipr_file_delete (filename);
    }
    else
        rc = -1;
</method>

<private name = "header">
static void
    s_timestamp_filename (char *stamped_name, char *filename);
</private>

<private name = "footer">
//  Add current date and time to filename, before extension
static void
s_timestamp_filename (char *stamped_name, char *filename)
{
    char
        *extension,
        *end_of_name;
    icl_shortstr_t
        suffix;
    apr_time_t
        time_now;
    apr_time_exp_t
        time_exp;
    int
        instance = 0;

    //  Get base filename up to extension
    extension = strchr (filename, '.');
    if (extension)
        icl_shortstr_ncpy (stamped_name, filename, extension - filename);
    else
        icl_shortstr_cpy (stamped_name, filename);

    time_now = apr_time_now ();
    assert (apr_time_exp_lt (&time_exp, time_now) == APR_SUCCESS);
    icl_shortstr_fmt (suffix, "-%04d%02d%02d-%02d%02d%02d", 
        time_exp.tm_year + 1900, time_exp.tm_mon  + 1, 
        time_exp.tm_mday, time_exp.tm_hour, 
        time_exp.tm_min, time_exp.tm_sec);

    //  Append time stamp to base filename
    icl_shortstr_cat (stamped_name, suffix);

    //  Append extension, if any
    if (extension)
        icl_shortstr_cat (stamped_name, extension);

    end_of_name = stamped_name + strlen (stamped_name);
    while (ipr_file_exists (stamped_name)) {
        *end_of_name = 0;               //  Remove any prior instance
        icl_shortstr_fmt (suffix, "#%d", ++instance);
        icl_shortstr_cat (stamped_name, suffix);
    }
}
</private>

<method name = "selftest">
    <local>
    </local>
    //
    //ipr_log_cycle ("logs/normal.log", "archive", "zip -m packed");
    //ipr_log_cycle ("empty.log", "archive", "zip -m packed");
</method>

</class>
