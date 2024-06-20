/*
 * HardwareTask.c
 *
 *  Created on: 20.10.2020
 *      Author: Rausch_Luca
 */

#include "hardwareTask.h"

#include "SCC30_Interface.h"		// Sensor-Schnittstelle
#include "edt_bsp_backlight.h"		// Zugriff auf die PWM-Funktion von EDT

#define USED_SENSOR_MODE SCC30_MODE_SINGLE_SHOT		// Verwendeter Modus des Sensors
#define USED_SENSOR_REP	 SCC30_REPEATABILITY_MEDIUM  	// Verwendete Wiederholungsgenauigkeit

QueueHandle_t dataQueue;		// Queue zum Austausch mit dem GUI-Task

void hardwareTask(void* param) {
	// Variablen
	struct Data_Package message;		// Struktur zur Kommunikation mit dem GUI-Task
	uint32_t driver_response = 0;		// Statusantwort des Treibers
	uint32_t prev_driver_response = 0;  // Vorherige Status-Meldung
	int32_t current_temperature = 0;	// Aktuelle Temperatur des Sensors
	uint32_t current_humidity = 0;		// Aktuelle Luftfeuchtigkeit des Sensors
	TickType_t previousWakeTime = 0;	// Anzahl der Systemticks beim letzten Aufruf der Funktion -> wird vom OS für die Delay-Funktion genutzt
	const TickType_t delay_ticks = pdMS_TO_TICKS(configHARDWARETASK_PERIOD);	// Umwandlung des Delays in ms zu einer äquivalenten Zahl von Systemticks

	// Sensor Initialisieren
	driver_response = SCC30_init(USED_SENSOR_MODE, USED_SENSOR_REP);
	if(driver_response == SCC30_OK){
		// Erfolg
		message.type = SENSOR_CONNECTED;
		message.data = ERROR_OK;
	}
	else{
		// Fehler -> Sensor nicht verbunden
		message.type = SENSOR_DISCONNECTED;
		message.data = driver_response;
	}
	xQueueSendToBack(dataQueue, &message, portMAX_DELAY);

	// Anzahl der Systemticks zum Einstiegszeitpunkt
	previousWakeTime = xTaskGetTickCount();

	// Letzte Antwort des Treibers abspeichern
	prev_driver_response = driver_response;

	// Hauptschleife
	while (1u) {
		// ---------------------- Sensor Steuerung --------------------------------
		// Wenn der Sensor noch verbunden ist, dann werten wir ihn aus
		if(prev_driver_response == SCC30_OK){
			// Aktuelle Temperatur einlesen und die GUI benachrichtigen
			driver_response = SCC30_getHumidAndTempC(&current_humidity, &current_temperature);
			if (driver_response == SCC30_OK) {
				message.type = TEMPERATURE_VALUE;
				message.data = current_temperature;
				xQueueSendToBack(dataQueue, &message, portMAX_DELAY);
				message.type = HUMIDITY_VALUE;
				message.data = current_humidity;
				xQueueSendToBack(dataQueue, &message, portMAX_DELAY);
			}
		}
		else{
			// Sensor ist nicht mehr richtig verbunden -> neu Initialisieren
			driver_response = SCC30_init(USED_SENSOR_MODE, USED_SENSOR_REP);
		}
		// ----------------------------- Status Update ------------------------------
		if (driver_response != prev_driver_response) {
			// Status-Update bei der Kommunikation -> GUI benachrichtigen
			message.type = (driver_response == SCC30_OK) ? SENSOR_CONNECTED : SENSOR_DISCONNECTED;
			message.data = driver_response;
			xQueueSendToBack(dataQueue, &message, portMAX_DELAY);
		}
		// Aktuellen Status vermerken
		prev_driver_response = driver_response;
		// -------------------------- Task schlafen legen ----------------------------
		// Task periodisch schlafen legen
		vTaskDelayUntil(&previousWakeTime, delay_ticks);
	}
}


// Änderung der Hintergrundbeleuchtung
void setPWMDuty(uint32_t duty) {
	/*
	 *  Hier könnte eine eigene Implementierung der PWM stehen, in diesem Beispiel
	 *  leiten wir den Wert lediglich an die BSP-Funktion von EDT weiter.
	 */
	EDT_LCD_BL_SetPwm(duty);
}

