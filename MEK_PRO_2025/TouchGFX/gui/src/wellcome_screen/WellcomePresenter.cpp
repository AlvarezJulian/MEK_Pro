#include <gui/wellcome_screen/WellcomeView.hpp>
#include <gui/wellcome_screen/WellcomePresenter.hpp>

WellcomePresenter::WellcomePresenter(WellcomeView &v) : view(v) {

}

void WellcomePresenter::activate() {
#ifndef SIMULATOR
	view.Slot_status_LogginOut_Changed(model->getLogStatus());
#endif // Simu
}

void WellcomePresenter::deactivate() {

}

#ifndef SIMULATOR

/*
 * Function HERE
 */


void WellcomePresenter::btn_StartControl_clicked(CANBUS_TX_ID CAN_ID) {
	model->Interface_Can_send(CAN_ID);
}

void WellcomePresenter::Wellcome_LogIn_Time_Changed(int hour, int min, int sec){
	view.Slot_LogIn_Time_Changed(hour, min, sec);
}

void WellcomePresenter::Wellcome_Status_LOGIN_OUT_Changed(bool state){
	view.Slot_status_LogginOut_Changed(state);
}

#endif
