#ifndef LOGINVIEW_HPP
#define LOGINVIEW_HPP

#include <gui_generated/login_screen/LoginViewBase.hpp>
#include <gui/login_screen/LoginPresenter.hpp>

class LoginView : public LoginViewBase
{
public:
    LoginView();
    virtual ~LoginView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

#ifndef SIMULATOR
    virtual void Slot_User_ID_Received(char* data);
    virtual void Slot_status_LogginOut_Changed(bool state);
#endif
protected:
	char* _UserID;
	bool _log_Status;
};

#endif // LOGINVIEW_HPP
