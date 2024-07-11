#include <gui/containers/TopMenu.hpp>

TopMenu::TopMenu() {

}

void TopMenu::initialize() {
	TopMenuBase::initialize();
}

#ifndef SIMULATOR

void TopMenu::Slot_Wifi_Signal_Changed(uint8_t val) {
	// wifi_sig_0 is always visible

	wifi_sig_1.setVisible(false);
	wifi_sig_2.setVisible(false);
	wifi_sig_3.setVisible(false);

	switch (val) {
	case SIGNAL_LEVEL_1:
		wifi_sig_1.setVisible(true);
		break;
	case SIGNAL_LEVEL_2:
		wifi_sig_2.setVisible(true);
		break;
	case SIGNAL_LEVEL_3:
		wifi_sig_3.setVisible(true);
		break;
	default:
		break;
	}

}

void TopMenu::Slot_Bluetooth_Status_Changed(bool status) {
//	bluetooth_0 is always visible

	bluetooth_Active.setVisible(false);
	if (status) {
		bluetooth_Active.setVisible(true);
	}

}

void TopMenu::Slot_logInOut_Status_Changed(bool status) {

	logIn_Led.setVisible(false);
	if (status) {
		logIn_Led.setVisible(true);
	}
//	TopMenu::invalidate();
}

void TopMenu::Slot_logIn_Time_Changed(int hour, int min, int sec){
	LoginClock.setTime24Hour(hour, min, sec);
}

#endif // SIMULATOR

