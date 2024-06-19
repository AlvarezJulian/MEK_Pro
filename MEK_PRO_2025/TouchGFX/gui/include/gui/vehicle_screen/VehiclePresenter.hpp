#ifndef VEHICLEPRESENTER_HPP
#define VEHICLEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class VehicleView;

class VehiclePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    VehiclePresenter(VehicleView& v);

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
#ifndef SIMULATOR
	virtual void btn_AceptControl_clicked(int CAN_ID);
	virtual void btn_backToMenu_clicked();
	virtual void Can_Send(int CAN_ID);
	virtual void Signal_Change_Language_Received(uint8_t *data);

#endif
    virtual ~VehiclePresenter() {}


private:
    VehiclePresenter();

    VehicleView& view;
};

#endif // VEHICLEPRESENTER_HPP
