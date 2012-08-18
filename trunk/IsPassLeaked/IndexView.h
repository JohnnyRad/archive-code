#ifndef IPL_INDEX_VIEW_H
#define  IPL_INDEX_VIEW_H

#include <Wt/WContainerWidget>
#include <Wt/WTemplate>
#include <Wt/Dbo/ptr>

#include "IsPassLeakedSession.h"
#include "DbUser.h"
#include "DbStat.h"

namespace Wt {
	class WContainerWidget;
}

class IndexView : public Wt::WContainerWidget
{
public:
	IndexView(IsPassLeakedSession &session);

private:
	IsPassLeakedSession &session_;
	Wt::WLineEdit *keywordEdit_;
	Wt::WContainerWidget *feedbackMessages_;
	Wt::WSelectionBox *areaOption_;
	Wt::WSelectionBox *dbOption_;
	Wt::WSelectionBox *methodOption_;
	Wt::WTable *result_;

	void init();
	void render();
	void query();
};


#endif		//IPL_INDEX_VIEW_H