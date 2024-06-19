#include <gui/vehiclecheck_screen/VehicleCheckView.hpp>
#include <gui/vehiclecheck_screen/VehicleCheckPresenter.hpp>

VehicleCheckPresenter::VehicleCheckPresenter(VehicleCheckView &v) :
		view(v) {

}

void VehicleCheckPresenter::activate() {

}

void VehicleCheckPresenter::deactivate() {

}
#ifndef SIMULATOR

void VehicleCheckPresenter::btn_Good_Clicked(int CAN_ID) {
	model->Interface_Can_send(CAN_ID);
}
void VehicleCheckPresenter::btn_Ok_Clicked(int CAN_ID) {

}
void VehicleCheckPresenter::btn_Bad_Clicked(int CAN_ID) {

}

void VehicleCheckPresenter::SW_LED_green_ON_Clicked() {
	model->HW_LED_green_ON();
}
void VehicleCheckPresenter::SW_LED_orange_ON_Clicked() {
	model->HW_LED_orange_ON();
}
void VehicleCheckPresenter::SW_LED_red_ON_Clicked() {
	model->HW_LED_red_ON();
}

#endif
