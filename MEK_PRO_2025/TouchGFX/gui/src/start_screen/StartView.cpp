#include <gui/start_screen/StartView.hpp>

StartView::StartView() {

}

void StartView::setupScreen() {
	StartViewBase::setupScreen();

}

void StartView::tearDownScreen() {
	StartViewBase::tearDownScreen();

}

#ifndef SIMULATOR

void StartView::Slot_User_ID_Received(uint8_t *data) {
	memset(User_ID_StartBuffer, 0, sizeof(User_ID_StartBuffer));
	Unicode::strncpy(User_ID_StartBuffer, (char*) data, 8);
	User_ID_Start.invalidate();
}

void StartView::Slot_status_LogIN() {
	logInOut_Status.setTypedText(touchgfx::TypedText(T_STATUS_EIN));
	logInOut_Status.invalidate();
}

void StartView::Slot_status_LogOUT() {
	logInOut_Status.setTypedText(touchgfx::TypedText(T_STATUS_AUS));
	logInOut_Status.invalidate();
//	application().gotoWellcomeScreenSlideTransitionEast();
}

void StartView::Slot_changeLanguage() {
	int idLanguage = Texts::getLanguage() + 1;
	if (idLanguage == NUMBER_OF_LANGUAGES) {
		idLanguage = 0;
	}
	Texts::setLanguage(idLanguage);
	StartView::invalidate();
}

void StartView::Slot_change_Language(uint8_t index) {

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
	StartView::invalidate();
}

#endif
