#ifndef GPIO_CONTROLPRESENTER_HPP
#define GPIO_CONTROLPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class GPIO_ControlView;

class GPIO_ControlPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    GPIO_ControlPresenter(GPIO_ControlView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~GPIO_ControlPresenter() {}

private:
    GPIO_ControlPresenter();

    GPIO_ControlView& view;
};

#endif // GPIO_CONTROLPRESENTER_HPP
