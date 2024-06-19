#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
//#include <gui/common/FrontendApplication.hpp>
//#include <touchgfx/Texts.hpp>

class ModelListener {
public:
	ModelListener() :
			model(0) {
	}

	virtual ~ModelListener() {
	}

	/*
	 * SIGNALS Wellcome
	 */

	virtual void Wellcome_ChangeWindow_Received(uint8_t index) {}
	virtual void Wellcome_Change_Language_Received (uint8_t index){}

	/*
	 * SIGNALS Start
	 */

	virtual void Start_User_ID_Received(uint8_t *data) {}
	virtual void Start_Status_LOGIN_Received() {}
	virtual void Start_Status_LOGOUT_Received() {}
	virtual void Start_Change_Language_Received(uint8_t index) {}
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
//	FrontendApplication& application() {
//		return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
//	}
};

#endif // MODELLISTENER_HPP
