#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <gui/common/FrontendApplication.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/Screen.hpp>

Model::Model() :
		modelListener(0) {

}

void Model::tick() {
	// Nachricht empfangen
#ifndef SIMULATOR
	FrontendApplication *const ui =
			static_cast<FrontendApplication*>(Application::getInstance());

	if (CanHandleMsg.CAN_HandleDataEn == true) {
		CanHandleMsg.CAN_HandleDataEn = false;

		switch (msgType) {
		case CANBUS_RX_START:
			break;
		case CANBUS_RX_IDNR2:
			break;
		case CANBUS_RX_IDNR3:
			break;
		case CANBUS_RX_IDNR4:
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
		case CANBUS_RX_USER_ID:
			modelListener->Start_User_ID_Received(RxData);

			break;
		case CANBUS_RX_LOG_IN:
			modelListener->Start_Status_LOGIN_Received();
			break;

		case CANBUS_RX_LOG_OUT:
			modelListener->Start_Status_LOGOUT_Received();
			break;

		case CANBUS_RX_LANGUAGE:

			switch (CanHandleMsg.CAN_HandleDataSize) {
			case DEUTSCH: // Deuscth
				if (RxData[0] == DE) {
					Texts::setLanguage(DE);
				}
				break;
			case ENLGISH: // Englisch
				if (RxData[1] == EN) {
					Texts::setLanguage(EN);
				}
				break;
			default:
				break;
			}
			ui->invalidate();

			break;

		case CANBUS_RX_SCREEN:
			switch (CanHandleMsg.CAN_HandleDataSize) {
			case WELLCOMEWINDOW:
				ui->gotoWellcomeScreenSlideTransitionEast();
				break;
			case STARTWINDOW:
				ui->gotoStartScreenSlideTransitionEast();
				break;
			case WORKSHOPWINDOW:
				ui->gotoVehicleScreenSlideTransitionEast();
				break;
			case VEHICLEWINDOW:
				ui->gotoVehicleScreenSlideTransitionEast();
				break;
			case VEHICLECHECKWINDOW:
				ui->gotoVehicleCheckScreenSlideTransitionEast();
				break;
			case CHRASHWINDOW:
				ui->gotoCrashScreenSlideTransitionEast();
				break;
			default:
				break;
			} // end switch()
			break;
		default:
			break;
		} // end switch()

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
	uint8_t data[8];

	switch (MsgTypeRX) {
	case CANBUS_TX_BTN_ACEPT_CONTROL:
		data[0] = 0x01;
		CAN_Send(CANBUS_TX_BTN_ACEPT_CONTROL, CANBUS_TX_BTN_ACEPT_CONTROL_DLC,
				data);
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
