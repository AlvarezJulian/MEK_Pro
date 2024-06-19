#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() :modelListener(0) {

}

void Model::tick() {
	// Nachricht empfangen
#ifndef SIMULATOR

	if (CanHandleMsg.CAN_HandleDataEn == true) {
		CanHandleMsg.CAN_HandleDataEn = false;

		switch (RxHeader.StdId) {
		case CANBUS_DISPLAY_RX_USER_ID:
			modelListener->Wellcome_ChangeWindow_Received(0);
			modelListener->Start_User_ID_Received(RxData);

			break;
		case CANBUS_DISPLAY_RX_LOG_IN:
			modelListener->Start_Status_LOGIN_Received();
			break;

		case CANBUS_DISPLAY_RX_LOG_OUT:
			modelListener->Start_Status_LOGOUT_Received();
			break;

		case CANBUS_DISPLAY_RX_LANGUAGE:

			switch (CanHandleMsg.CAN_HandleDataSize) {
			case 1: // Deuscth
				if (RxData[0] == DE) {
					modelListener->Wellcome_Change_Language_Received(DE);
					modelListener->Start_Change_Language_Received(DE);
				}
				break;

			case 2: // Englisch

				if (RxData[1] == EN) {
					modelListener->Wellcome_Change_Language_Received(EN);
					modelListener->Start_Change_Language_Received(EN);
				}
				break;

			default:
				break;
			}

			break;

		case CANBUS_DISPLAY_RX_SCREEN:
			modelListener->Wellcome_ChangeWindow_Received(0);
			break;
		}

		/*
		 switch (msgType) {
		 case CAN_USER_ID:
		 modelListener->Interface_User_ID_Received(RxData);
		 break;
		 case CAN_STATUS_LOGIN:
		 if (RxData[0] == 0x01) {
		 modelListener->Interface_Status_LOGIN_Received();
		 }
		 break;
		 case CAN_STATUS_LOGOUT:
		 if (RxData[0] == 0x01) {
		 modelListener->Interface_Status_LOGOUT_Received();
		 }
		 break;

		 case CAN_LANGAUGE:
		 modelListener->Interface_Change_Language_Received(RxData);
		 break;

		 default:
		 break;
		 } // end switch()
		 */
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
//void Model::Interface_CanSlider_send(int value) {
////	sendCAN(value);
////	sendCAN(CANBUS_DISPLAY_TX_START, 8, &value);
//}
void Model::Interface_Can_send(int CAN_ID) {
	uint8_t data[8];

	switch (CAN_ID) {
	case CANBUS_DISPLAY_TX_BTN_ACEPT_CONTROL:
		data[0] = 0x01;
		CAN_Send(CANBUS_DISPLAY_TX_BTN_ACEPT_CONTROL, 1, data);
		break;
	case CANBUS_DISPLAY_TX_BTN_GOOD:
		data[0] = 0x01;
		CAN_Send(CANBUS_DISPLAY_TX_BTN_GOOD, 1, data);
		break;
	case CANBUS_DISPLAY_TX_BTN_OK:
		data[0] = 0x01;
		CAN_Send(CANBUS_DISPLAY_TX_BTN_OK, 1, data);
		break;
	case CANBUS_DISPLAY_TX_BTN_BAD:
		data[0] = 0x01;
		CAN_Send(CANBUS_DISPLAY_TX_BTN_BAD, 1, data);

		break;
	default:
		break;
	}
}
#endif // SIMULATOR
