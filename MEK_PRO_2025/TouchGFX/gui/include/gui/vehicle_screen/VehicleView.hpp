#ifndef VEHICLEVIEW_HPP
#define VEHICLEVIEW_HPP

#include <gui_generated/vehicle_screen/VehicleViewBase.hpp>
#include <gui/vehicle_screen/VehiclePresenter.hpp>

//#ifndef SIMULATOR
//extern "C" {
//#include <can.h>
//}
//#endif // Simulator

class VehicleView: public VehicleViewBase {
public:
	VehicleView();
	virtual ~VehicleView() {
	}
	virtual void setupScreen();
	virtual void tearDownScreen();

#ifndef SIMULATOR
	/*###############################################
	 * #################SIGNASL######################
	 * #############################################
	 */
	virtual void btn_AceptControl_clicked();
    virtual void btn_backToMenu_clicked();


    /*
     * SLOTS
     */

    virtual void Slot_change_Language(uint8_t *data);
#endif

protected:

};

#endif // VEHICLEVIEW_HPP
