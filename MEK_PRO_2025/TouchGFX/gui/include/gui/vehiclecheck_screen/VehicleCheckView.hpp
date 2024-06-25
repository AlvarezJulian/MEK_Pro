#ifndef VEHICLECHECKVIEW_HPP
#define VEHICLECHECKVIEW_HPP

#include <gui_generated/vehiclecheck_screen/VehicleCheckViewBase.hpp>
#include <gui/vehiclecheck_screen/VehicleCheckPresenter.hpp>

class VehicleCheckView: public VehicleCheckViewBase {
public:
	VehicleCheckView();
	virtual ~VehicleCheckView() {
	}
	virtual void setupScreen();
	virtual void tearDownScreen();

#ifndef SIMULATOR
//	void ModelCanToView(uint8_t *data);
	/*
	 * #################SIGNASL################
	 */
	virtual void btn_Good_Clicked();
	virtual void btn_Ok_Clicked();
	virtual void btn_Bad_Clicked();
	virtual void btn_Next_Clicked();
	virtual void btn_Pre_Clicked();
	virtual void changeLanguage();

#endif // Simu
protected:
//	 CANBUS_TX_ID ID_btnPressed;
};

#endif // VEHICLECHECKVIEW_HPP

