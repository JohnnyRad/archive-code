#ifndef DB_STAT_H
#define DB_STAT_H

#include <Wt/Dbo/Types>
#include <Wt/Dbo/WtSqlTraits>

namespace dbo = Wt::Dbo;

class Stat {
public:
	Wt::WString ip;
	Wt::WDateTime lastQuery;
	int numQuery;

	static bool okToQuery(IsPassLeakedSession &session, const std::string& ip);
	static void update(IsPassLeakedSession &session, const std::string& ip);

	template<class Action>
	void persist(Action& a)
	{
		dbo::field(a, ip, "ip");
		dbo::field(a, lastQuery, "last_query_time");
		dbo::field(a, numQuery, "query_num");
	}
};

DBO_EXTERN_TEMPLATES(Stat);

#endif		//DB_STAT_H
