#include <gui/start_screen/StartView.hpp>
#include <gui/start_screen/StartPresenter.hpp>

StartPresenter::StartPresenter(StartView &v) : view(v) {

}

void StartPresenter::activate() {
#ifndef SIMULATOR
	view.Slot_User_ID_Received(model->getCurrentUserID());
	view.Slot_status_LogginOut_Changed(model->getLogStatus());

// TODO: Aktuelle Uhrzeit einstellen...

//	view.Slot_InitialTimeChanged(model->getCurrentHour(), model->getCurrentMinute(),
//			model->getCurrentSecond());

#endif // Simu

}

void StartPresenter::deactivate() {

}
#ifndef SIMULATOR

void StartPresenter::Start_User_ID_Received(char *data) {
	view.Slot_User_ID_Received(data);
}

void StartPresenter::Start_Status_LOGIN_OUT_Received(bool state) {
	view.Slot_status_LogginOut_Changed(state);
}

void StartPresenter::Start_wifi_Signal_Changed(uint8_t val) {
	view.Slot_wifi_Signal_Changed(val);
}
void StartPresenter::Start_Bluetooth_Status_Changed(bool state) {
	view.Slot_Bluetooth_Status_Changed(state);
}
#endif // Simu
