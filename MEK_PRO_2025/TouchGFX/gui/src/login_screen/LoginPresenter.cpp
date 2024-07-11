#include <gui/login_screen/LoginView.hpp>
#include <gui/login_screen/LoginPresenter.hpp>

LoginPresenter::LoginPresenter(LoginView &v) : view(v) {

}

void LoginPresenter::activate() {
#ifndef SIMULATOR
	view.Slot_status_LogginOut_Changed(model->getLogStatus());
#endif
}

void LoginPresenter::deactivate() {

}
#ifndef SIMULATOR
void LoginPresenter::Login_User_ID_Received(char *data) {
	view.Slot_User_ID_Received(data);
}

void LoginPresenter::Login_Status_LOGIN_OUT_Changed(bool state) {
	view.Slot_status_LogginOut_Changed(state);
}
void LoginPresenter::Login_LogIn_Time_Changed(int hour, int min, int sec){
	view.Slot_LogIn_Time_Changed(hour, min, sec);
}
void LoginPresenter::Login_Status_LOGIN_OUT_changed(bool state){
	view.Slot_status_LogginOut_Changed(state);
}
#endif
