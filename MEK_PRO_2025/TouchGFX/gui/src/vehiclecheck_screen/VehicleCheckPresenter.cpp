#include <gui/vehiclecheck_screen/VehicleCheckView.hpp>
#include <gui/vehiclecheck_screen/VehicleCheckPresenter.hpp>

VehicleCheckPresenter::VehicleCheckPresenter(VehicleCheckView &v) :
		view(v) {

}

void VehicleCheckPresenter::activate() {
#ifndef SIMULATOR
	view.Slot_status_LogginOut_Changed(model->getLogStatus());
#endif // Simu
}

void VehicleCheckPresenter::deactivate() {

}
#ifndef SIMULATOR

void VehicleCheckPresenter::btn_Good_Clicked(CANBUS_TX_ID CAN_ID) {
	model->Interface_Can_send(CAN_ID);
}
void VehicleCheckPresenter::btn_Ok_Clicked(CANBUS_TX_ID CAN_ID) {
	model->Interface_Can_send(CAN_ID);
}
void VehicleCheckPresenter::btn_Bad_Clicked(CANBUS_TX_ID CAN_ID) {
	model->Interface_Can_send(CAN_ID);
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

void VehicleCheckPresenter::Vehicle_Status_LOGIN_OUT_Received(bool state){
	view.Slot_status_LogginOut_Changed(state);
}
 void VehicleCheckPresenter::Vehicle_LogIn_Time_Changed(int hour, int min, int sec){
	 view.Slot_LogIn_Time_Changed(hour, min, sec);
 }

#endif
