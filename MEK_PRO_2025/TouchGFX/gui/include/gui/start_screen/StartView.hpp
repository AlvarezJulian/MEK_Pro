#ifndef STARTVIEW_HPP
#define STARTVIEW_HPP

#include <gui_generated/start_screen/StartViewBase.hpp>
#include <gui/start_screen/StartPresenter.hpp>
//#include <touchgfx/Texts.hpp>


class StartView: public StartViewBase {
public:
	StartView();
	virtual ~StartView() {
	}
	virtual void setupScreen();
	virtual void tearDownScreen();

#ifndef SIMULATOR

	virtual void Slot_User_ID_Received(uint8_t *data);
	virtual void Slot_status_LogIN();
	virtual void Slot_status_LogOUT();
	virtual void Slot_changeLanguage();
	virtual void Slot_change_Language(uint8_t index);

#endif
protected:
};

#endif // STARTVIEW_HPP
