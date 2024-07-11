#include <gui/vehiclecheck_screen/VehicleCheckView.hpp>
#include <string>

VehicleCheckView::VehicleCheckView() :
		_log_Status(false) {

}

void VehicleCheckView::setupScreen() {
	VehicleCheckViewBase::setupScreen();

}

void VehicleCheckView::tearDownScreen() {
	VehicleCheckViewBase::tearDownScreen();
}
/*
 * SIGNALS IMPLEMENTATION####################
 */
#ifndef SIMULATOR
/**
 *
 */
void VehicleCheckView::btn_Good_Clicked() {
//	ID_btnPressed = CANBUS_TX_BTN_GOOD;
//	presenter->btn_Good_Clicked(ID_btnPressed);
	btn_YES_Clicked();

}
/**
 *
 */
void VehicleCheckView::btn_Ok_Clicked() {
	ID_btnPressed = CANBUS_TX_BTN_OK;
	presenter->btn_Good_Clicked(ID_btnPressed);
}
/**
 *
 */
void VehicleCheckView::btn_Bad_Clicked() {
//	ID_btnPressed = CANBUS_TX_BTN_BAD;
//	presenter->btn_Good_Clicked(ID_btnPressed);
	btn_NO_Clicked();
}
/**
 *
 */
void VehicleCheckView::btn_YES_Clicked() {
	ID_btnPressed = CANBUS_TX_BTN_OK;
	presenter->btn_Good_Clicked(ID_btnPressed);
}
void VehicleCheckView::btn_NO_Clicked() {
	ID_btnPressed = CANBUS_TX_BTN_OK;
	presenter->btn_Good_Clicked(ID_btnPressed);
}
/**
 *
 */
void VehicleCheckView::Slot_status_LogginOut_Changed(bool state) {

	if (state != _log_Status) {
		_log_Status = state;
		presenter->saveLogStatus(_log_Status);
	}
	if (_log_Status == true) {
		//		logInOut_Status.setTypedText(touchgfx::TypedText(T_STATUS_IN));
	} else {
		//		logInOut_Status.setTypedText(touchgfx::TypedText(T_STATUS_OUT));

	}
	//	logInOut_Status.invalidate();

	topMenu1.Slot_logInOut_Status_Changed(_log_Status);
}
/**
 *
 */
void VehicleCheckView::Slot_LogIn_Time_Changed(int hour, int min, int sec) {
	topMenu1.Slot_logIn_Time_Changed(hour, min, sec);
}

#endif
