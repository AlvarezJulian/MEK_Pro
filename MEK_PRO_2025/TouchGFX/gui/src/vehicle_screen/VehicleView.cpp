#include <gui/vehicle_screen/VehicleView.hpp>

VehicleView::VehicleView() {

}

void VehicleView::setupScreen() {
	VehicleViewBase::setupScreen();
}

void VehicleView::tearDownScreen() {
	VehicleViewBase::tearDownScreen();
}

#ifndef SIMULATOR
void VehicleView::btn_AceptControl_clicked() {
 ID_btnPressed = CANBUS_DISPLAY_TX_BTN_ACEPT_CONTROL;
	presenter->btn_AceptControl_clicked(ID_btnPressed);
}

void VehicleView::btn_backToMenu_clicked() {

}

void VehicleView::Slot_change_Language(uint8_t *data) {
	if (data[0] == DE) {
		Texts::setLanguage(DE);
	}

	if (data[1] == EN) {
		Texts::setLanguage(EN);
	}
	VehicleView::invalidate();
}

#endif
