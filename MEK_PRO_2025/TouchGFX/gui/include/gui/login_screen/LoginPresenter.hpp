#ifndef LOGINPRESENTER_HPP
#define LOGINPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LoginView;

class LoginPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LoginPresenter(LoginView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~LoginPresenter() {}
#ifndef SIMULATOR

	virtual void Login_User_ID_Received(char *data);

	void SaveUserID(char *UserID) {
		model->setCurrentUserID(UserID);
	}
	void saveLogStatus(bool state) {
		model->SetLogStatus(state);
	}
#endif
private:
    LoginPresenter();

    LoginView& view;
};

#endif // LOGINPRESENTER_HPP
