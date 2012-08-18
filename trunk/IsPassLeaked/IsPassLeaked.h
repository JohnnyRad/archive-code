/**
 * IPL
 *
 * Copyright (C) 2011 Fujitsu Nanda Software Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */

#ifndef IPL_H
#define IPL_H

#include <Wt/Dbo/backend/Postgres>
#include <Wt/Dbo/collection>
#include <Wt/Dbo/Impl>
#include <Wt/Dbo/ptr>
#include <Wt/Dbo/Query>
#include <Wt/Dbo/Session>
#include <Wt/Dbo/Transaction>
#include <Wt/Dbo/Types>
#include <Wt/Dbo/WtSqlTraits>

#include <Wt/WApplication>
#include <Wt/WAnchor>
#include <Wt/WAnimation>
#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WButtonGroup>
#include <Wt/WCheckBox>
#include <Wt/WComboBox>
#include <Wt/WContainerWidget>
#include <Wt/WDate>
#include <Wt/WDatePicker>
#include <Wt/WDateTime>
#include <Wt/WDialog>
#include <Wt/WEnvironment>
#include <Wt/WFileUpload>
#include <Wt/WFileResource>
#include <Wt/WGlobal>
#include <Wt/WImage>
#include <Wt/WInPlaceEdit>
#include <Wt/WIntValidator>
#include <Wt/WLabel>
#include <Wt/WLength>
#include <Wt/WLengthValidator>
#include <Wt/WLineEdit>
#include <Wt/WMenu>
#include <Wt/WMenuItem>
#include <Wt/WMessageBox>
#include <Wt/WPanel>
#include <Wt/WPopupMenu>
#include <Wt/WPopupMenuItem>
#include <Wt/WProgressBar>
#include <Wt/WPushButton>
#include <Wt/WRadioButton>
#include <Wt/WRandom>
#include <Wt/WRegExpValidator>
#include <Wt/WSelectionBox>
#include <Wt/WServer>
#include <Wt/WSignal>
#include <Wt/WStackedWidget>
#include <Wt/WSubMenuItem>
#include <Wt/WTable>
#include <Wt/WTableRow>
#include <Wt/WTabWidget>
#include <Wt/WTemplate>
#include <Wt/WText>
#include <Wt/WTextArea>
#include <Wt/WTimer>
#include <Wt/WValidator>
#include <Wt/WValidationStatus>

#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/dynamic_bitset.hpp>
#include <boost/filesystem.hpp>

#include "IsPassLeakedSession.h"
#include "DbUser.h"

static const char *WtHttpConfig = "wthttp.conf";
static const char *DbConn = "dbname=postgres user=V.E.O password=007";
static const char *FaviconUrl = "/css/favicon.png";
static const int IntervalFullText = 60;

class IsPassLeakedApplication : public Wt::WApplication
{
public:
	IsPassLeakedApplication(const Wt::WEnvironment& env);

private:
	IsPassLeakedSession session_;
};
#endif		// IPL_H