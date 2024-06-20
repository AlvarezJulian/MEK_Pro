#include <gui/graphscreen_screen/GraphScreenView.hpp>
#include <gui/graphscreen_screen/GraphScreenPresenter.hpp>

GraphScreenPresenter::GraphScreenPresenter(GraphScreenView& v)
	: view(v)
{

}

void GraphScreenPresenter::activate()
{

}

void GraphScreenPresenter::deactivate()
{

}

void GraphScreenPresenter::setTemperature(int32_t temp)
{
	// Wert an die View weiterleiten
	view.updateTemperature(temp);
}

void GraphScreenPresenter::setHumidity(int32_t humid)
{
	// Wert an die View weiterleiten
	view.updateHumidity(humid);
}

void GraphScreenPresenter::updateSensorState()
{
	model->getCurrentSensorState();
}
