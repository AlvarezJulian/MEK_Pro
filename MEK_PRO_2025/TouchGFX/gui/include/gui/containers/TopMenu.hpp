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

	/*
	 * Callback Setters
	 */
//	void setSomethingHappenedCallback(touchgfx::GenericCallback<> &callback) {
//		somethingHappenedCallback = &callback;
//		digitalClock1.setTime24Hour(11, 11, 11);
//	}
	/*
	 * Methods
	 */
//	virtual void doSomething();
	virtual void Slot_Wifi_Signal_Changed(uint8_t val);
	virtual void Slot_Bluetooth_Status_Changed(bool status);
	virtual void Slot_logInOut_Changed(bool status);

#endif // SIMULATOR
protected:

#ifndef SIMULATOR
	/*
	 * Callback Emitters
	 */
//	virtual void emitSomethingHappenedCallback() {
//
//		if (somethingHappenedCallback && somethingHappenedCallback->isValid()) {
//			somethingHappenedCallback->execute();
//		digitalClock1.setTime24Hour(10, 10, 10);
//		}
//
//		if (RxData[1] == 2) {
//			Slot_Wifi_Signal_Changed(2);
//		}
//		if (RxData[1] == 3) {
//			Slot_Wifi_Signal_Changed(3);
//		}
//
//		if (RxData[1] == 4) {
//			Slot_Bluetooth_Status_Changed(true);
//		}
//	}
private:
	/*
	 * Callback Declarations
	 */
//	touchgfx::GenericCallback<> *somethingHappenedCallback;
};
#endif // SIMULATOR
#endif // TOPMENU_HPP
