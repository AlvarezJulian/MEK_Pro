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
	virtual void btn_YES_Clicked();
	virtual void btn_NO_Clicked();


	/*
	 * SLOTS
	 */
	virtual void Slot_status_LogginOut_Changed(bool state);
	virtual void Slot_LogIn_Time_Changed(int hour, int min, int sec);

#endif // Simu
protected:
	bool _log_Status;

};

#endif // VEHICLECHECKVIEW_HPP

