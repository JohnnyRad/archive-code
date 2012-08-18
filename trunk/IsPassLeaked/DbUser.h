#ifndef DB_USER_H
#define DB_USER_H

#include <Wt/Dbo/Types>
#include <Wt/Dbo/WtSqlTraits>

namespace dbo = Wt::Dbo;

class User {
public:
	Wt::WString userName;
	Wt::WString password;
	Wt::WString email;

	template<class Action>
	void persist(Action& a)
	{
		dbo::field(a, userName, "user");
		dbo::field(a, password, "pass");
		dbo::field(a, email, "password");
	}
};

DBO_EXTERN_TEMPLATES(User);

#endif // DB_USER_H
