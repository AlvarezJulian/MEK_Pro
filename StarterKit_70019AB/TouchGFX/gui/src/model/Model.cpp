#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
// Einbinden der Schnittstellen zum Hardware-Task
extern "C" {
#include "HardwareTask.h"
}
// Instanzen der Kommunikations-Strukturen erzeugen
struct Data_Package received_package;
#else
// Für dem Simulator binden wir math.h ein um Zugriff auf sin/cos zu erhalten
#include <math.h>
// Falls nicht vorhanden, definieren wir Pi
#ifndef PI
#define PI 3.14159265 
#endif
// Grenzen der Messwerte definieren
#define TEMP_AMPLITUDE	100
#define TEMP_OFFSET		250
#define HUMID_AMPLITUDE	50
#define HUMID_OFFSET	50
#endif

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR
	// Queue abfragen, ob neue Daten von dem System vorliegen
	while (uxQueueMessagesWaiting(dataQueue)) {
		// Queue ohne Wartezeit auslesen, da auf jedenfall Daten vorliegen
		xQueueReceive(dataQueue, &received_package, 0);
		// Je nach Nachrichten-Typ weiterverarbeiten
		switch (received_package.type) {
		case TEMPERATURE_VALUE:
			modelListener->setTemperature(received_package.data);
			break;
		case HUMIDITY_VALUE:
			modelListener->setHumidity(received_package.data);
			break;
		case SENSOR_CONNECTED:
			current_sensorState = SensorConnectionStates::SENSOR_CONNECTED;
			modelListener->sensorEvent(current_sensorState);
			break;
		case SENSOR_DISCONNECTED:
			current_sensorState = SensorConnectionStates::SENSOR_DISCONNECTED;
			modelListener->sensorEvent(current_sensorState);
			break;
		default:
			// Fehlerfall -> unbekannter Nachrichtentyp
			break;
		}
	}
#else
	// Variablen fuer die simulierten Messwerte
	static int32_t current_temp = 0;
	static uint32_t current_humid = 0;
	// Temperatur mit dem Sinus skalieren
	current_temp = (int32_t)(TEMP_AMPLITUDE * sin((2.0 * PI * (double)counter) / (double)COUNTER_PERIOD)) + TEMP_OFFSET;
	// Luftfeuchtigkeit mit dem Cosinus skalieren
	current_humid = (int32_t)(HUMID_AMPLITUDE * cos((2.0 * PI * (double)counter) / (double)COUNTER_PERIOD)) + HUMID_OFFSET;
	// Werte an die View schicken
	modelListener->setTemperature(current_temp);
	modelListener->setHumidity(current_humid);
	counter++;
	if (counter == COUNTER_PERIOD) {
		counter = 0;
		// Nach einer Periode schalten wir den 'Sensor frei' um die GUI-Verarbeitung zu ueberpruefen
		if (current_sensorState == SensorConnectionStates::SENSOR_DISCONNECTED) {
			current_sensorState = SensorConnectionStates::SENSOR_CONNECTED;
			modelListener->sensorEvent(current_sensorState);
		}
	}
#endif
}

void Model::setBacklight(uint8_t pwm_val)
{
#ifndef SIMULATOR
	/*
	 * Die Weiterleitung des Wertes könnte auch über das OS erfolgen.
	 * In dem hier gezeigten Beispiel wird der Hardware-Task jedoch nur alle 200 ms ausgeführt.
	 * Somit würde er die Änderungen der PWM nicht schnell genug erfassen können.
	 * Da der Zugriff auf die PWM jedoch relativ schnell erfolgt, kann die API direkt vom GUI-Task
	 * aufgerufen werden, ohne sichtbare Leistungseinbrüche.
	 */
	setPWMDuty(pwm_val);
#endif
}

void Model::getCurrentSensorState() {
	// SensorEvent-Funktion aufrufen
	modelListener->sensorEvent(current_sensorState);
}
