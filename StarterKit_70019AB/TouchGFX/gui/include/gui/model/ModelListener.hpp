#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
	ModelListener() : model(0) {}

	virtual ~ModelListener() {}

	void bind(Model* m)
	{
		model = m;
	}

	// Schnittstellen System -> GUI
	virtual void sensorEvent(Model::SensorConnectionStates connection_state) {}
	virtual void setTemperature(int32_t temp) {}
	virtual void setHumidity(int32_t humid) {}

protected:
	Model* model;
};

#endif // MODELLISTENER_HPP
