#ifndef MAINSCREENPRESENTER_HPP
#define MAINSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MainScreenView;

class MainScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
	MainScreenPresenter(MainScreenView& v);

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

	virtual ~MainScreenPresenter() {};

	// Schnittstellen System -> GUI
	void sensorEvent(Model::SensorConnectionStates connection_state);
	void setTemperature(int32_t temp);
	void setHumidity(int32_t humid);

	// Schnittstelle GUI -> System
	void updateBacklight(uint8_t pwm_val);
	void updateSensorState();

private:
	MainScreenPresenter();

	MainScreenView& view;
};

#endif // MAINSCREENPRESENTER_HPP
