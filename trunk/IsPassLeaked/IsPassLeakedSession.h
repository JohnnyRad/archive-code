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

#ifndef IPL_SESSION_H
#define IPL_SESSION_H

#include <Wt/Dbo/Session>
#include <Wt/Dbo/ptr>
#include <Wt/Dbo/backend/Postgres>

namespace dbo = Wt::Dbo;

class User;

class IsPassLeakedSession : public dbo::Session
{
public:
	IsPassLeakedSession(const std::string& sqliteDb);
	dbo::ptr<User> user() const { return user_; }

private:
	dbo::backend::Postgres connection_;
	dbo::ptr<User> user_;
};

#endif IPL_SESSION_H