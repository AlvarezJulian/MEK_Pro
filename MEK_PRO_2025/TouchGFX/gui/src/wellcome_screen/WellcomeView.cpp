#include <gui/wellcome_screen/WellcomeView.hpp>

WellcomeView::WellcomeView() :
		_log_Status(false) {

}

void WellcomeView::setupScreen() {
	WellcomeViewBase::setupScreen();
}

void WellcomeView::tearDownScreen() {
	WellcomeViewBase::tearDownScreen();
}

#ifndef SIMULATOR

void WellcomeView::btn_StartControl_clicked() {
	ID_btnPressed = CANBUS_TX_BTN_START_CONTROL;
	presenter->btn_StartControl_clicked(ID_btnPressed);
}

void WellcomeView::Slot_status_LogginOut_Changed(bool state) {
	if (state != _log_Status) {
		_log_Status = state;
		presenter->saveLogStatus(_log_Status);
	}
	topMenu1.Slot_logInOut_Status_Changed(_log_Status);
}

void WellcomeView::Slot_LogIn_Time_Changed(int hour, int min, int sec) {
	topMenu1.Slot_logIn_Time_Changed(hour, min, sec);
}

#endif
