#include <gui/vehicle_screen/VehicleView.hpp>
#include <gui/vehicle_screen/VehiclePresenter.hpp>

VehiclePresenter::VehiclePresenter(VehicleView &v) :
		view(v) {

}

void VehiclePresenter::activate() {

}

void VehiclePresenter::deactivate() {

}
#ifndef SIMULATOR
void VehiclePresenter::btn_AceptControl_clicked(CANBUS_TX_ID CAN_ID){
	model->Interface_Can_send(CAN_ID);
}

void VehiclePresenter::btn_backToMenu_clicked(){

}
void VehiclePresenter::Can_Send(int CAN_ID) {

}

void VehiclePresenter::Signal_Change_Language_Received(uint8_t *data){

}

#endif
