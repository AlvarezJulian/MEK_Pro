#ifndef VEHICLECHECKVIEW_HPP
#define VEHICLECHECKVIEW_HPP

#include <gui_generated/vehiclecheck_screen/VehicleCheckViewBase.hpp>
#include <gui/vehiclecheck_screen/VehicleCheckPresenter.hpp>
//#include <gui/containers/RandomBtns.hpp>
#include <texts/TextKeysAndLanguages.hpp>

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
	uint8_t value = 1;
#endif // Simu
protected:
};

#endif // VEHICLECHECKVIEW_HPP

