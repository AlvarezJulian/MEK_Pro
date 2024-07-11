#include <gui/login_screen/LoginView.hpp>

LoginView::LoginView() : _UserID(0), _log_Status(0) {

}

void LoginView::setupScreen() {
	LoginViewBase::setupScreen();
}

void LoginView::tearDownScreen() {
	LoginViewBase::tearDownScreen();
}

#ifndef SIMULATOR

void LoginView::Slot_User_ID_Received(char *data) {
	if (data != _UserID) {
		_UserID = data;
		presenter->SaveUserID(_UserID);
	}
}

void LoginView::Slot_status_LogginOut_Changed(bool state) {

	if (state != _log_Status) {
		_log_Status = state;
		presenter->saveLogStatus(_log_Status);
	}
	topMenu1.Slot_logInOut_Status_Changed(_log_Status);
}

void LoginView::Slot_LogIn_Time_Changed(int hour, int min, int sec) {
	topMenu1.Slot_logIn_Time_Changed(hour, min, sec);
}

#endif
