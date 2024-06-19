#include <gui/wellcome_screen/WellcomeView.hpp>
#include <gui/wellcome_screen/WellcomePresenter.hpp>

WellcomePresenter::WellcomePresenter(WellcomeView& v)
    : view(v)
{

}

void WellcomePresenter::activate()
{

}

void WellcomePresenter::deactivate()
{

}


#ifndef SIMULATOR

void WellcomePresenter::Wellcome_ChangeWindow_Received(uint8_t index) {

	view.Slot_ChangeWindow_Received();

}
void WellcomePresenter::Wellcome_Change_Language_Received(uint8_t index){
 view.Slot_change_Language(index);
}
#endif
