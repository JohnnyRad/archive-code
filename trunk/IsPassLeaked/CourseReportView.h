/**
 * CAESAR
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

#ifndef COURSE_REPORT_VIEW_H
#define COURSE_REPORT_VIEW_H

#include <Wt/WTemplate>
#include "DbCourseOffer.h"

class CaesarSession;

namespace Wt {
	class WTable;
	class WStackedWidget;
	class WPushButton;
	class WAnchor;
}

class CourseReportView : public Wt::WTemplate
{
public:
	CourseReportView(CaesarSession &session);

private:
	CaesarSession &session_;
	Wt::WTable * reportTable;
	Wt::WStackedWidget *result;

	Wt::WPushButton * exportBtn;
	Wt::WAnchor * exportLink;

	void reportCompile(Offers offers);
	void exportReport();

	void processQuery();
};

#endif		//USER_REPORT_VIEW_H
