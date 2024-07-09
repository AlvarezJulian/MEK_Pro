#include <gui/login_screen/LoginView.hpp>
#include <gui/login_screen/LoginPresenter.hpp>

LoginPresenter::LoginPresenter(LoginView &v) : view(v) {

}

void LoginPresenter::activate() {

}

void LoginPresenter::deactivate() {

}
#ifndef SIMULATOR
void LoginPresenter::Login_User_ID_Received(char *data) {
	view.Slot_User_ID_Received(data);
}
#endif
