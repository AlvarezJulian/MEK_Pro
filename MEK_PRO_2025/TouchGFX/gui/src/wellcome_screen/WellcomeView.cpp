#include <gui/wellcome_screen/WellcomeView.hpp>

WellcomeView::WellcomeView()  {

}

void WellcomeView::setupScreen() {
	WellcomeViewBase::setupScreen();
}

void WellcomeView::tearDownScreen() {
	WellcomeViewBase::tearDownScreen();
}

#ifndef SIMULATOR


void WellcomeView::btn_StartControl_clicked() {
	ID_btnPressed = CANBUS_TX_BTN_START_CONTROL;
	presenter->btn_StartControl_clicked(ID_btnPressed);
}
#endif
