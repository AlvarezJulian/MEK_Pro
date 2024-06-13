#ifndef HID_PRESENTER_HPP
#define HID_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class HIDView;

class HIDPresenter : public Presenter, public ModelListener
{
public:
    HIDPresenter(HIDView& v);

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

    virtual ~HIDPresenter() {};

private:
    HIDPresenter();

    HIDView& view;
};


#endif // HID_PRESENTER_HPP