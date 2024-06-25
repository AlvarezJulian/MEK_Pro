#include <gui/wellcome_screen/WellcomeView.hpp>

WellcomeView::WellcomeView() {

}

void WellcomeView::setupScreen() {
	WellcomeViewBase::setupScreen();
}

void WellcomeView::tearDownScreen() {
	WellcomeViewBase::tearDownScreen();
}

#ifndef SIMULATOR
/*
void WellcomeView::Slot_ChangeWindow_Received() {
	application().gotoStartScreenSlideTransitionEast();
}
*/


void WellcomeView::Slot_change_Language(uint8_t index) {

	switch (index) {
	case DE:
		Texts::setLanguage(DE);
		break;
	case EN:
		Texts::setLanguage(EN);
		break;
	default:
		break;
	}

	WellcomeView::invalidate();
}

#endif
