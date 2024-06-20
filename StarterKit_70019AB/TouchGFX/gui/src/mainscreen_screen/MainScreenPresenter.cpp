#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

MainScreenPresenter::MainScreenPresenter(MainScreenView& v)
	: view(v)
{

}

void MainScreenPresenter::activate()
{

}

void MainScreenPresenter::deactivate()
{

}

void MainScreenPresenter::sensorEvent(Model::SensorConnectionStates connection_state)
{
	// Je nach Zustand die entsprechende View-Funktion aufrufen
	if (connection_state == Model::SensorConnectionStates::SENSOR_CONNECTED) {
		view.sensorConnected();
	}
	else {
		view.sensorDisconnected();
	}
}

void MainScreenPresenter::setTemperature(int32_t temp)
{
	// Wert an die View weiterleiten
	view.updateTemperature(temp);
}

void MainScreenPresenter::setHumidity(int32_t humid)
{
	// Wert an die View weiterleiten
	view.updateHumidity(humid);
}

void MainScreenPresenter::updateBacklight(uint8_t pwm_val)
{
	// Wert an die Model-Instanz weiterleiten
	model->setBacklight(pwm_val);
}

void MainScreenPresenter::updateSensorState()
{
	model->getCurrentSensorState();
}
