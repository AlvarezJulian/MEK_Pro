#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
//#include <gui/containers/TopMenu.hpp>

class ModelListener {
public:
	ModelListener() :
			model(0) {
	}

	virtual ~ModelListener() {
	}

	/*
	 * SIGNALS LOGIN
	 *
	 */
	virtual void Login_User_ID_Changed(char *data) {
	}
	virtual void Login_LogIn_Time_Changed(int hour, int min, int sec) {
	}
	virtual void Login_Status_LOGIN_OUT_Changed(bool state) {
	}
	/*
	 * SIGNALS WELLCOME
	 */
	virtual void Wellcome_LogIn_Time_Changed(int hour, int min, int sec) {
	}
	virtual void Wellcome_Status_LOGIN_OUT_Changed(bool state) {
	}
	/*
	 * SIGNALS VEHICLECHECK
	 */

	virtual void Vehicle_LogIn_Time_Changed(int hour, int min, int sec) {
	}
	virtual void Vehicle_Status_LOGIN_OUT_Changed(bool state) {
	}
	/*
	 * SIGNALS START
	 */

	virtual void Start_User_ID_Changed(char *data) {
	}
	virtual void Start_Status_LOGIN_OUT_Changed(bool state) {
	}
	virtual void Start_wifi_Signal_Changed(uint8_t val) {
	}
	virtual void Start_Bluetooth_Status_Changed(bool state) {
	}
	virtual void Start_LogIn_Time_Changed(int hour, int min, int sec) {
	}

	/*
	 * SIGNALS STATUS SCREEN
	 */
	virtual void Status_Status_LOGIN_OUT_Changed(bool state) {
	}

	//***********************CRASH********************


	//#####################WORKSHOP###################


	//++++++++++++++++++++++++ELS+++++++++++++++++++++


	void bind(Model *m) {
		model = m;
	}
protected:
	Model *model;
//	TopMenu topMenu;

};

#endif // MODELLISTENER_HPP
