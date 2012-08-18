#include "IsPassLeaked.h"
#include "DbStat.h"

DBO_INSTANTIATE_TEMPLATES(Stat);

bool Stat::okToQuery(IsPassLeakedSession &session, const std::string& ip)
{
	try
	{
		dbo::ptr<Stat> stat
			= session.find<Stat>().where("ip = ?").bind(ip);

		if (stat)
		{
			return stat->lastQuery.secsTo(Wt::WDateTime::currentDateTime()) > IntervalFullText ? true : false;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return false;
}

void Stat::update(IsPassLeakedSession &session, const std::string& ip)
{
	try
	{
		dbo::Transaction t(session);
		dbo::ptr<Stat> stat
			= session.find<Stat>().where("ip = ?").bind(ip);

		if (stat)
		{
			Stat *s = stat.modify();
			s->lastQuery = Wt::WDateTime::currentDateTime();
			s->numQuery++;
		} else {
			Stat *s = new Stat();
			s->lastQuery = Wt::WDateTime::currentDateTime();			
			s->numQuery = 1;
			session.add(s);
		}

		t.commit();

	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}