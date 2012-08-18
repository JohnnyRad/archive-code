#include "IsPassLeaked.h"
#include "IndexView.h"

using namespace Wt;
namespace dbo = Wt::Dbo;


IndexView::IndexView(IsPassLeakedSession &session)
	: session_(session)
{
	init();
}

void IndexView::init() {
	WApplication *app = wApp;

	app->setTitle("Leaked Password Query Kit");

	render();
}

void IndexView::render() {
	clear();
	WTable *queryTable = new WTable(this);

	WLabel *label;
	int row = 0;

	// Title
	queryTable->elementAt(row, 0)->setColumnSpan(3);
	queryTable->elementAt(row, 0)->setContentAlignment(AlignTop | AlignCenter);
	queryTable->elementAt(row, 0)->setPadding(10);
	WText *title = new WText(("Leaked Password Query Kit"), queryTable->elementAt(row, 0));
	title->decorationStyle().font().setSize(WFont::XLarge);

	// error messages
	++row;
	queryTable->elementAt(row, 0)->setColumnSpan(3);
	feedbackMessages_ = queryTable->elementAt(row, 0);
	feedbackMessages_->setPadding(5);

	WCssDecorationStyle& errorStyle = feedbackMessages_->decorationStyle();
	errorStyle.setForegroundColor(Wt::red);
	errorStyle.font().setSize(WFont::Smaller);
	errorStyle.font().setWeight(WFont::Bold);
	errorStyle.font().setStyle(WFont::Italic);

	// User
	++row;
	keywordEdit_ = new WLineEdit(queryTable->elementAt(row, 2));
	label = new WLabel("Keyword:", queryTable->elementAt(row, 0));
	label->setBuddy(keywordEdit_);
	keywordEdit_->setValidator(new WValidator(true));
	keywordEdit_->enterPressed().connect(this, &IndexView::query);

	// Search Area
	++row;
	areaOption_ = new WSelectionBox(queryTable->elementAt(row, 2));
	areaOption_->addItem("Username");
	areaOption_->addItem("Password");
	areaOption_->setCurrentIndex(0);
	label = new WLabel("Keyword Type:", queryTable->elementAt(row,0));
	label->setBuddy(areaOption_);

	// DB to Search
	++row;
	dbOption_ = new WSelectionBox(queryTable->elementAt(row, 2));
	dbOption_->addItem("CSDN (6M)");
	dbOption_->addItem("RenRen (5M)");
	dbOption_->addItem("178 (10M)");
	dbOption_->addItem("7k7k (20M)");
	dbOption_->addItem("duduniu (10M)");
	dbOption_->addItem("duowan (10M)");
	dbOption_->addItem("MOP (10M)");
	dbOption_->addItem("Tianya (40M)");
	dbOption_->setCurrentIndex(0);
	label = new WLabel("Database:", queryTable->elementAt(row,0));
	label->setBuddy(dbOption_);

	// Search Method
	++row;
	methodOption_ = new WSelectionBox(queryTable->elementAt(row, 2));
	methodOption_->addItem("Header Match");
	methodOption_->addItem("Full-Text (1 Quota Per Minute Per IP)");
	methodOption_->setCurrentIndex(0);
	label = new WLabel("Search Method:", queryTable->elementAt(row,0));
	label->setBuddy(methodOption_);

	// Query
	++row;
	WPushButton *query = new WPushButton("Query",
		queryTable->elementAt(row, 0));
	query->clicked().connect(this, &IndexView::query);
	query->setMargin(15, Top);
	queryTable->elementAt(row, 0)->setColumnSpan(3);
	queryTable->elementAt(row, 0)->setContentAlignment(AlignTop | AlignCenter);

	// Set column widths for label and validation icon
	queryTable->elementAt(2, 0)->resize(WLength(30, WLength::FontEx), WLength::Auto);
	queryTable->elementAt(2, 1)->resize(20, WLength::Auto);

	// Result
	result_ = new WTable(this);
	result_->clear();
}

//void IndexView::login() {
//	WLineEdit *name = login_->resolve<WLineEdit *>("name");
//	WLineEdit *passwd = login_->resolve<WLineEdit *>("passwd");
//	WCheckBox *rememberMe = login_->resolve<WCheckBox *>("rememberMe");
//
//	dbo::Transaction t(session_);
//
//	dbo::ptr<User> user
//		= session_.find<User>().where("user_name like ?").bind(name->text());
//
//	if (user) {
//		if (user->authenticate(passwd->text().toUTF8())) {
//			WApplication *app = wApp;
//			User *m = user.modify();
//			std::string token = m->generateToken();
//			m->lastLoginIP = user->loginIP;
//			m->loginIP = app->environment().clientAddress();
//			t.commit();
//
//			if (rememberMe->isChecked()) 
//				app->setCookie("caesar-logged-in", token, 60*60*24*14);
//			else 
//				app->setCookie("caesar-logged-in", token, -1);
//
//			loginAs(user);
//		} else {
//		name->removeStyleClass("Wt-invalid", true);
//		passwd->addStyleClass("Wt-invalid", true);
//		WMessageBox::show(tr("login-failed"), tr("wrong-password"), Ok);
//		}
//	} else {
//		name->addStyleClass("Wt-invalid", true);
//		WMessageBox::show(tr("login-failed"), tr("user-not-found"), Ok);
//	}
//}

void IndexView::query()
{
	const WString &keyword = keywordEdit_->text();
	int area = areaOption_->currentIndex();
	int db = dbOption_->currentIndex();
	int method = methodOption_->currentIndex();
	std::wstring trimKeyword = boost::algorithm::trim_copy(keyword.value());


	// Validation
	if (trimKeyword.length() == 0)
	{
		feedbackMessages_->addWidget(new WText("Keyword Empty!"));
		keywordEdit_->label()->decorationStyle().setForegroundColor(Wt::red);
		keywordEdit_->setStyleClass("Wt-invalid");
	}

	if (method == 1)
	{
		if (trimKeyword.length() < 4)
		{
			feedbackMessages_->addWidget(new WText("Keyword Cannot be Shorter Than 4 Chars In Full-Text Search!"));
			keywordEdit_->label()->decorationStyle().setForegroundColor(Wt::red);
			keywordEdit_->setStyleClass("Wt-invalid");
		}
		if (!Stat::okToQuery(session_, wApp->environment().clientAddress()))
		{
			feedbackMessages_->addWidget(new WText("Wait up! Query Interval is 60s In Full-Text Search!"));
		}
	}

}