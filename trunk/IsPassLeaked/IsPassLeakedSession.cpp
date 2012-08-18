#include "IsPassLeaked.h"
#include "IsPassLeakedSession.h"

namespace dbo = Wt::Dbo;

IsPassLeakedSession::IsPassLeakedSession(const std::string& connInfo)
  : connection_(connInfo)
{
	try
	{
		connection_.connect(DbConn);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	setConnection(connection_);

	mapClass<User>("user");
}
