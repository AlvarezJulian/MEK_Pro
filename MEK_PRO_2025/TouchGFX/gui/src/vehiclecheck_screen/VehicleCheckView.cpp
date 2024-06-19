#include <gui/vehiclecheck_screen/VehicleCheckView.hpp>
#include <string>

VehicleCheckView::VehicleCheckView() {

}

void VehicleCheckView::setupScreen() {
	VehicleCheckViewBase::setupScreen();

//	list_btnQuestions.setHeight(0);

}

void VehicleCheckView::tearDownScreen() {
	VehicleCheckViewBase::tearDownScreen();
}

/*
 * SIGNALS IMPLEMENTATION####################
 */
#ifndef SIMULATOR

void VehicleCheckView::btn_Good_Clicked() {
	presenter->SW_LED_green_ON_Clicked();
//	presenter->btn_Good_Clicked(CANBUS_DISPLAY_TX_BTN_GOOD);
}

void VehicleCheckView::btn_Ok_Clicked() {
	presenter->SW_LED_orange_ON_Clicked();
}
void VehicleCheckView::btn_Bad_Clicked() {
	presenter->SW_LED_red_ON_Clicked();
}

void VehicleCheckView::btn_Next_Clicked() {
//	char data;
//std::string data ;
//touchgfx::Unicode::UnicodeChar data[200] ;
//data = "Hallo das ist ein Beispieltext. \n Hier ist ihr Text...";

	value++;

	// snprintf = integer
	Unicode::snprintf(Check_CounBuffer1, CHECK_COUNBUFFER1_SIZE, "%d", value);
	Check_Coun.invalidate();
//	// strncpy = Text
//	Unicode::strncpy(question_TextBuffer,
//			"Hallo das ist ein Beispieltext. \n Hier ist ihr Text...", QUESTION_TEXT_SIZE);
//
//	question_TextBuffer.invalidate();

//	btn_bad.setY(300);
//	add(btn_bad);
//	btn_bad.invalidate();
}
void VehicleCheckView::btn_Pre_Clicked() {
	value--;
	Unicode::snprintf(Check_CounBuffer1, CHECK_COUNBUFFER1_SIZE, "%d", value);
	Check_Coun.invalidate();

}

void VehicleCheckView::changeLanguage() {
	int idLanguage = Texts::getLanguage() + 1;
	if (idLanguage == NUMBER_OF_LANGUAGES) {
		idLanguage = 0;
	}
	Texts::setLanguage(idLanguage);
	VehicleCheckView::invalidate();
}
#endif
