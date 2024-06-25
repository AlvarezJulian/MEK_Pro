#ifndef VEHICLECHECKPRESENTER_HPP
#define VEHICLECHECKPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class VehicleCheckView;

class VehicleCheckPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    VehicleCheckPresenter(VehicleCheckView& v);

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

    virtual ~VehicleCheckPresenter() {}
#ifndef SIMULATOR


	virtual void btn_Good_Clicked(CANBUS_TX_ID CAN_ID);
	virtual void btn_Ok_Clicked(CANBUS_TX_ID CAN_ID);
	virtual void btn_Bad_Clicked(CANBUS_TX_ID CAN_ID);
	virtual void SW_LED_green_ON_Clicked();
	virtual void SW_LED_orange_ON_Clicked();
	virtual void SW_LED_red_ON_Clicked();


#endif // SIMLUATOR

private:
    VehicleCheckPresenter();

    VehicleCheckView& view;
};

#endif // VEHICLECHECKPRESENTER_HPP
