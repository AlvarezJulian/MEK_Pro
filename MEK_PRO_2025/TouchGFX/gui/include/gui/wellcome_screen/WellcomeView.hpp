#ifndef WELLCOMEVIEW_HPP
#define WELLCOMEVIEW_HPP

#include <gui_generated/wellcome_screen/WellcomeViewBase.hpp>
#include <gui/wellcome_screen/WellcomePresenter.hpp>

class WellcomeView : public WellcomeViewBase
{
public:
    WellcomeView();
    virtual ~WellcomeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();


#ifndef SIMULATOR
	virtual void btn_StartControl_clicked();
	virtual void Slot_status_LogginOut_Changed(bool state);
	virtual void Slot_LogIn_Time_Changed(int hour,int min,int sec);

#endif
protected:
	bool _log_Status;
};

#endif // WELLCOMEVIEW_HPP
