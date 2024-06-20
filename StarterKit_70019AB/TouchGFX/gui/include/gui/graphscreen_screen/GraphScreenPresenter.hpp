#ifndef GRAPHSCREENPRESENTER_HPP
#define GRAPHSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class GraphScreenView;

class GraphScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
	GraphScreenPresenter(GraphScreenView& v);

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

	virtual ~GraphScreenPresenter() {};

	// Schnittstellen System -> GUI
	void setTemperature(int32_t temp);
	void setHumidity(int32_t humid);

	// Schnittstelle GUI -> System
	void updateSensorState();

private:
	GraphScreenPresenter();

	GraphScreenView& view;
};

#endif // GRAPHSCREENPRESENTER_HPP
