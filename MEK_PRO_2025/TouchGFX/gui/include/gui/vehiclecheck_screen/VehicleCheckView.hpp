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

	/*
	 * #################SIGNASL################
	 */
	virtual void btn_Good_Clicked();
	virtual void btn_Ok_Clicked();
	virtual void btn_Bad_Clicked();


#endif // Simu
protected:

};

#endif // VEHICLECHECKVIEW_HPP

