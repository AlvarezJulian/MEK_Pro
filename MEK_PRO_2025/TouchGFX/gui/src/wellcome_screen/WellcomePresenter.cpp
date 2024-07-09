#include <gui/wellcome_screen/WellcomeView.hpp>
#include <gui/wellcome_screen/WellcomePresenter.hpp>

WellcomePresenter::WellcomePresenter(WellcomeView &v) : view(v) {

}

void WellcomePresenter::activate() {

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
#endif
