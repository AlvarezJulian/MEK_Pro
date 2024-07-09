#ifndef STARTVIEW_HPP
#define STARTVIEW_HPP

#include <gui_generated/start_screen/StartViewBase.hpp>
#include <gui/start_screen/StartPresenter.hpp>

class StartView: public StartViewBase {
public:
	StartView();
	virtual ~StartView() {
	}
	virtual void setupScreen();
	virtual void tearDownScreen();
	virtual void handleTickEvent();

#ifndef SIMULATOR

	virtual void Slot_User_ID_Received(char *data);
	virtual void Slot_status_LogginOut_Changed(bool state);
	virtual void Slot_wifi_Signal_Changed(uint8_t val);
	virtual void Slot_Bluetooth_Status_Changed(bool state);
	/*
	 * SET
	 */
	void setTickCounter(int val) {
		tickCounter = val;
	}
	void setLogHour(int hour) {
		_logHours = hour;
	}
	void setLogMinute(int minute) {
		_logMinutes = minute;
	}
	void setLogSecond(int second) {
		_logSeconds = second;
	}
	/*
	 * GET
	 */
	int getTickcounter() {
		return tickCounter;
	}
	int getLogHour() {
		return _logHours;
	}
	int getLogMinute() {
		return _logMinutes;
	}
	int getLogSecond() {
		return _logSeconds;
	}

#endif
protected:
	int tickCounter;
	int _logHours;
	int _logMinutes;
	int _logSeconds;
	//Start Screen save Data:
	char *_UserID;
	bool _log_Status;
	bool _Workshop_Status;
	uint16_t _EZB_hour;
	uint16_t _EZB_minute;
	uint16_t _ELS_status;

};

#endif // STARTVIEW_HPP
