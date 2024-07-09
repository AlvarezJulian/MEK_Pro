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
#endif
protected:
};

#endif // WELLCOMEVIEW_HPP
