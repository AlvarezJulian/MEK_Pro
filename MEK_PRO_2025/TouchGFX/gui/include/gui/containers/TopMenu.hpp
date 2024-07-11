#ifndef TOPMENU_HPP
#define TOPMENU_HPP

#include <gui_generated/containers/TopMenuBase.hpp>
#include <touchgfx/containers/Container.hpp>


enum wifiSignal {
	SIGNAL_LEVEL_1 = 1, SIGNAL_LEVEL_2, SIGNAL_LEVEL_3,
};

class TopMenu: public TopMenuBase {
public:
	TopMenu();
	virtual ~TopMenu() {
	}

	virtual void initialize();
#ifndef SIMULATOR
	virtual void Slot_Wifi_Signal_Changed(uint8_t val);
	virtual void Slot_Bluetooth_Status_Changed(bool status);
	virtual void Slot_logInOut_Status_Changed(bool status);
	virtual void Slot_logIn_Time_Changed(int hour, int min, int sec);


#endif // SIMULATOR

protected:
private:
};

#endif // TOPMENU_HPP
