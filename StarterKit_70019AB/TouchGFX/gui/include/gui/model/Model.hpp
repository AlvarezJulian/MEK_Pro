#ifndef MODEL_HPP
#define MODEL_HPP

#include <stdint.h>

class ModelListener;

class Model
{
public:

	// Definition des Sensor-Verbindungsstatus
	enum class SensorConnectionStates : uint8_t {
		SENSOR_DISCONNECTED,
		SENSOR_CONNECTED
	};


	Model();

	void bind(ModelListener* listener)
	{
		modelListener = listener;
	}

	void tick();

	// Schnittstelle GUI -> System
	void setBacklight(uint8_t pwm_val);
	void getCurrentSensorState();

protected:
	ModelListener* modelListener;

	// Z?hler-Variable
	uint32_t counter = 0u;
	// Periode f?r den Z?hler
	const uint32_t COUNTER_PERIOD = 300u;

	// Aktueller Verbindungsstatus
	SensorConnectionStates current_sensorState = SensorConnectionStates::SENSOR_DISCONNECTED;
};

#endif // MODEL_HPP
