#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
//#include <gui/containers/TopMenu.hpp>

class ModelListener {
public:
	ModelListener() : model(0) {
	}

	virtual ~ModelListener() {
	}

	/*
	 * SIGNALS TOP Menu
	 *
	 */
//	virtual void TopMenu_Wifi_Signal_Chaneged(uint8_t val);
	/*
	 * SIGNALS Wellcome
	 */
	virtual void Wellcome_User_ID_Received(char *data) {
	}
	/*
	 * SIGNALS Start
	 */

	virtual void Start_User_ID_Received(char *data) {
	}
//	virtual void Start_Status_LOGIN_Received() {}
//	virtual void Start_Status_LOGOUT_Received() {}
	virtual void Start_Status_LOGIN_OUT_Received(bool state) {
	}
	virtual void Start_wifi_Signal_Changed(uint8_t val){
	}
	virtual void Start_Bluetooth_Status_Changed(bool state){

	}
	/*
	 * SIGNALS Vehicle
	 */

	/*
	 * SIGNALS VehicleCheck
	 */

	/*
	 * SIGNALS Crash
	 */

	/*
	 * SIGNALS Workshop-Modus
	 */

	void bind(Model *m) {
		model = m;
	}
protected:
	Model *model;
//	TopMenu topMenu;

};

#endif // MODELLISTENER_HPP
