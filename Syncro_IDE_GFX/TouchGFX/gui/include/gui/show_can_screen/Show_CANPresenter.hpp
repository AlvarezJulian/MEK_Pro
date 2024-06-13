#ifndef SHOW_CANPRESENTER_HPP
#define SHOW_CANPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Show_CANView;

class Show_CANPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Show_CANPresenter(Show_CANView& v);

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

    virtual ~Show_CANPresenter() {}

private:
    Show_CANPresenter();

    Show_CANView& view;
};

#endif // SHOW_CANPRESENTER_HPP
