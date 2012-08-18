#include "IsPassLeaked.h"
#include "IsPassLeakedSession.h"
#include "IndexView.h"

using namespace Wt;

IsPassLeakedApplication::IsPassLeakedApplication( const WEnvironment& env )
: WApplication(env),session_(DbConn)
{
	//setCssTheme("polished");
	root()->clear();
	root()->addWidget(new IndexView(session_));
}

WApplication *createApplication(const WEnvironment& env)
{
	return new IsPassLeakedApplication(env);
}

int main(int argc, char **argv)
{
	return WRun(argc, argv, &createApplication);
}