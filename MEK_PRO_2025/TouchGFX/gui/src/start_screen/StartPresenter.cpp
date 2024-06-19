#include <gui/start_screen/StartView.hpp>
#include <gui/start_screen/StartPresenter.hpp>

StartPresenter::StartPresenter(StartView &v) :
		view(v) {

}

void StartPresenter::activate() {

}

void StartPresenter::deactivate() {

}
#ifndef SIMULATOR

//void StartPresenter::CANReceived(uint8_t *data) {
//
//	view.ModelCanToView(data);
//
//}

void StartPresenter::Start_User_ID_Received(uint8_t *data) {
	view.Slot_User_ID_Received(data);
}

void StartPresenter::Start_Status_LOGIN_Received() {
	view.Slot_status_LogIN();
}
void StartPresenter::Start_Status_LOGOUT_Received() {
	view.Slot_status_LogOUT();
}
void StartPresenter::Start_Change_Language_Received(uint8_t index) {
	view.Slot_change_Language(index);
}
#endif
