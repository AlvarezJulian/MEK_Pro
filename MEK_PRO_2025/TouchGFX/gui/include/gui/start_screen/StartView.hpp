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

#ifndef SIMULATOR

	virtual void Slot_User_ID_Received(char *data);
	virtual void Slot_status_LogginOut_Changed(bool state);
	virtual void Slot_wifi_Signal_Changed(uint8_t val);
	virtual void Slot_Bluetooth_Status_Changed(bool state);
	virtual void Slot_LogIn_Time_Changed(int hour, int min, int sec);


#endif
protected:
	//Start Screen save Data:
	char *_UserID;
	bool _log_Status;
	uint8_t _vehicle_Status;
	uint16_t _EZB_hour;
	uint16_t _EZB_minute;
	uint16_t _ELS_status;

};

#endif // STARTVIEW_HPP
