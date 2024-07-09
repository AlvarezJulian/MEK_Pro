#include <gui/start_screen/StartView.hpp>

StartView::StartView() :
		_logHours(0),
		_logMinutes(0),
		_logSeconds(0),
		_UserID(0),
		_log_Status(false),
		_Workshop_Status(false),
		_EZB_hour(0),
		_EZB_minute(0),
		_ELS_status(0) {

}

void StartView::setupScreen() {
	StartViewBase::setupScreen();

	/*
	 * get the Current valus
	 */
//	_UserID = presenter->getUserId();
//	_log_Status = presenter->getLogStatus();
//	_EZB_hour = presenter->getEZBHour();
//	_EZB_minute = presenter->getEZBMinute();
//	_ELS_status = presenter->getELSStatus();
	/*
	 * update the new Values on Screen
	 */
	_logHours = LogTimeClock.getCurrentHour();
	_logMinutes = LogTimeClock.getCurrentMinute();
	_logSeconds = LogTimeClock.getCurrentSecond();
#ifndef SIMULATOR
	_logHours = presenter->getLogHour();
	_logMinutes = presenter->getLogMinute();
	_logSeconds = presenter->getLogSecond();
#endif // SIMULATOR
}

void StartView::tearDownScreen() {
	StartViewBase::tearDownScreen();
#ifndef SIMULATOR
	presenter->saveLogHour(_logHours);
	presenter->saveLogMinute(_logMinutes);
	presenter->saveLogSecond(_logSeconds);
#endif // SIMULATOR
}

#ifndef SIMULATOR

void StartView::Slot_User_ID_Received(char *data) {

	if (data != _UserID) {
		_UserID = data;
		presenter->SaveUserID(_UserID);
	}
	// Show Data
	Unicode::strncpy(User_ID_StartBuffer, _UserID, USER_ID_START_SIZE);
	User_ID_Start.invalidate();
}

void StartView::Slot_wifi_Signal_Changed(uint8_t val) {
	topMenu1.Slot_Wifi_Signal_Changed(val);
}

void StartView::Slot_Bluetooth_Status_Changed(bool state) {
	topMenu1.Slot_Bluetooth_Status_Changed(state);
}

void StartView::Slot_status_LogginOut_Changed(bool state) {

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

	topMenu1.Slot_logInOut_Changed(_log_Status);

}

#endif // SIMULATOR

void StartView::handleTickEvent() {

	if (_log_Status == true) {

		tickCounter++;

		if (tickCounter % 60 == 0) {
			if (++_logSeconds >= 60) {
				_logSeconds = 0;
				if (++_logMinutes >= 60) {
					_logMinutes = 0;
					if (++_logHours >= 24) {
						_logHours = 0;
					}
				}
			}

			// Update the clock
			LogTimeClock.setTime24Hour(_logHours, _logMinutes, _logSeconds);
		}
	}
}
