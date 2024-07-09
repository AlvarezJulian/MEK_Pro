#include <gui/vehiclecheck_screen/VehicleCheckView.hpp>
#include <string>

VehicleCheckView::VehicleCheckView() {

}

void VehicleCheckView::setupScreen() {
	VehicleCheckViewBase::setupScreen();

}

void VehicleCheckView::tearDownScreen() {
	VehicleCheckViewBase::tearDownScreen();
}

/*
 * SIGNALS IMPLEMENTATION####################
 */
#ifndef SIMULATOR

void VehicleCheckView::btn_Good_Clicked() {
	ID_btnPressed = CANBUS_TX_BTN_GOOD;
	presenter->btn_Good_Clicked(ID_btnPressed);
}

void VehicleCheckView::btn_Ok_Clicked() {
	ID_btnPressed = CANBUS_TX_BTN_OK;
	presenter->btn_Good_Clicked(ID_btnPressed);
}
void VehicleCheckView::btn_Bad_Clicked() {
	ID_btnPressed = CANBUS_TX_BTN_BAD;
	presenter->btn_Good_Clicked(ID_btnPressed);
}


#endif
