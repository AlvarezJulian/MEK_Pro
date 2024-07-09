#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <gui/common/FrontendApplication.hpp>
//#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Texts.hpp>
//#include <touchgfx/Screen.hpp>
//#include <gui/containers/TopMenu.hpp>

Model::Model() :
		modelListener(0),
		current_Wifi_Signal(0),
		current_bluetooth_Status(false),
		current_hour(0),
		current_minute(0),
		current_second(0),
		current_UserID(0),
		current_log_Status(false),
		current_Workshop_Status(false),
		current_Crash_Status(false),
		current_EBZ_hour(0),
		current_EBZ_minute(0),
		current_EBZ_second(0),
		current_ELS_status(false),
		current_log_hour(0),
		current_log_minute(0) {
}

/*
 *
 * muss getestet werden mit HARDWARE- TFT Display
 *
 * -> fehlt ::getInstance(); irgendwo !?
 */

void Model::tick() {
	// Nachricht empfangen
#ifndef SIMULATOR

	FrontendApplication *const ui =
			static_cast<FrontendApplication*>(Application::getInstance());

	if (CanHandleMsg.CAN_HandleDataEn == true) {


		switch (msgType) {
		case CANBUS_RX_USER_ID:
			strncpy(ID_Data, (char*) RxData, CAN_SIZE);
			modelListener->Start_User_ID_Received(ID_Data);
			modelListener->Wellcome_User_ID_Received(ID_Data);
			break;

		case CANBUS_RX_LOG_IN:
			modelListener->Start_Status_LOGIN_OUT_Received(true);
			break;

		case CANBUS_RX_LOG_OUT:
			modelListener->Start_Status_LOGIN_OUT_Received(false);
			break;

		case CANBUS_RX_IDNR4:

/*
 * Test Funktion  um das Top menu zu aktualiersen
 * ohne MPV
 */

			break;
		case CANBUS_RX_IDNR5:
			break;
		case CANBUS_RX_IDNR6:
			break;
		case CANBUS_RX_IDNR7:
			break;
		case CANBUS_RX_IDNR8:
			break;
		case CANBUS_RX_IDNR9:
			break;
		case CANBUS_RX_IDNR10:
			break;
		case CANBUS_RX_IDNR11:
			break;
		case CANBUS_RX_IDNR12:
			break;
		case CANBUS_RX_IDNR13:
			break;
		case CANBUS_RX_IDNR14:
			break;
		case CANBUS_RX_IDNR15:
			break;
		case CANBUS_RX_LANGUAGE:

			switch (RxData[0]) { // Select the langguage and update the Screen
			case GERMAN: // Deuscth
				Texts::setLanguage(DE);
				break;
			case ENGLISH: // Englisch
				Texts::setLanguage(EN);
				break;
			default:
				break;
			} // end Switch

			break;
		case CANBUS_RX_SCREEN_CHANGE:
			switch (RxData[0]) {
			case LOGINWINDOW:
				ui->gotoLoginScreenSlideTransitionWest();
				break;
			case WELLCOMEWINDOW:
				ui->gotoWellcomeScreenSlideTransitionEast();
				break;
			case VEHICLECHECKWINDOW:
				ui->gotoVehicleCheckScreenSlideTransitionEast();
				break;
			case STARTWINDOW:
				ui->gotoStartScreenSlideTransitionEast();
				break;
			case STATUSWINDOW:
				ui->gotoStatusScreenScreenSlideTransitionNorth();
				break;
			default:
				break;
			} // end switch()

		case CANBUS_RX_CURRENT_TIME:

			break;
		case CANBUS_RX_WIFI_SIGNAL:
			modelListener->Start_wifi_Signal_Changed(RxData[0]);
			break;
		case CANBUS_RX_BLUETOOTH_ACTIVE:
			modelListener->Start_Bluetooth_Status_Changed(RxData[0]);
			break;
		default:
			break;
		} // end switch()
		CanHandleMsg.CAN_HandleDataEn = false;
		ui->invalidate();
	} // end if
#endif // SIMULATOR
} // end Model::tick()

#ifndef SIMULATOR
void Model::HW_LED_green_ON() {
	Led_green_On();
}
void Model::HW_LED_orange_ON() {
	Led_orange_On();
}
void Model::HW_LED_red_ON() {
	Led_red_On();
}
void Model::HW_LED_OFF() {
	Led_Off();
}

void Model::Interface_Can_send(CANBUS_TX_ID MsgTypeRX) {
	uint8_t data[CAN_SIZE];

	switch (MsgTypeRX) {
	case CANBUS_TX_BTN_START_CONTROL:
		data[0] = 0x01;
		CAN_Send(CANBUS_TX_BTN_START_CONTROL, CANBUS_TX_BTN_START_CONTROL_DLC, data);
		break;
	case CANBUS_TX_BTN_GOOD:
		data[0] = 0x01;
		CAN_Send(CANBUS_TX_BTN_GOOD, CANBUS_TX_BTN_GOOD_DLC, data);
		break;
	case CANBUS_TX_BTN_OK:
		data[0] = 0x01;
		CAN_Send(CANBUS_TX_BTN_OK, CANBUS_TX_BTN_OK_DLC, data);
		break;
	case CANBUS_TX_BTN_BAD:
		data[0] = 0x01;
		CAN_Send(CANBUS_TX_BTN_BAD, CANBUS_TX_BTN_BAD_DLC, data);
		break;
	default:
		break;
	}
}
#endif // SIMULATOR
