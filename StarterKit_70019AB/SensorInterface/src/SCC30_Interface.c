/*
 * SCC30_Interface.c
 *
 *  Created on: 15.10.2020
 *      Author: Rausch_Luca
 */

#include "SCC30_HAL.h"
#include "SCC30_Interface.h"

// Kontrolle, ob CRC sowohl im Interface und in der HAL freigeschaltet sind
#ifdef SCC30_USE_CRC
#ifndef SCC30_ENABLE_CRC
#error "Please enable the CRC module in the SCC30 HAL!"
#endif
#endif

// Setzen des Faktors für die Nachkommastellen
#if (SCC30_TEMPERATURE_DEC_PLACE < 0)
#error "Please set the value of SCC30_TEMPERATURE_DEC_PLACE greater than 0"
#elif (SCC30_TEMPERATURE_DEC_PLACE == 0)
#define SCC30_TEMP_DP_FACTOR 1u
#elif (SCC30_TEMPERATURE_DEC_PLACE == 1)
#define SCC30_TEMP_DP_FACTOR 10u
#elif (SCC30_TEMPERATURE_DEC_PLACE == 2)
#define SCC30_TEMP_DP_FACTOR 100u
#elif (SCC30_TEMPERATURE_DEC_PLACE == 3)
#define SCC30_TEMP_DP_FACTOR 1000u
#else
#error "Please set the value of SCC30_TEMPERATURE_DEC_PLACE to 3 or less"
#endif
#if (SCC30_HUMIDITY_DEC_PLACE < 0)
#error "Please set the value of SCC30_HUMIDITY_DEC_PLACE greater than 0"
#elif (SCC30_HUMIDITY_DEC_PLACE == 0)
#define SCC30_HUMID_DP_FACTOR 1u
#elif (SCC30_HUMIDITY_DEC_PLACE == 1)
#define SCC30_HUMID_DP_FACTOR 10u
#elif (SCC30_HUMIDITY_DEC_PLACE == 2)
#define SCC30_HUMID_DP_FACTOR 100u
#elif (SCC30_HUMIDITY_DEC_PLACE == 3)
#define SCC30_HUMID_DP_FACTOR 1000u
#else
#error "Please set the value of SCC30_HUMIDITY_DEC_PLACE to 3 or less"
#endif

// ############# Konfiguration der Übertragung ############
#define SCC30_STD_DELAY					3u
#define SCC30_RESET_DELAY				50u
#define SCC30_TIMEOUT_CYCLES			20u
#ifdef SCC30_USE_CRC
#define SCC30_UNLOCK_CRC				1u
#define SCC30_CRC_TEST_VAL				0xBEEFu
#define SCC30_CRC_EXPECTED_RESULT		0x92u
#endif

// ################### SCC30 Kommandos ####################
#define SCC30_CMD_START_SINGLE_SHOT		0x2400u
#define SCC30_CMD_START_PERIODIC_05		0x2000u
#define SCC30_CMD_START_PERIODIC_1		0x2100u
#define SCC30_CMD_START_PERIODIC_2		0x2200u
#define SCC30_CMD_START_PERIODIC_4		0x2300u
#define SCC30_CMD_START_PERIODIC_10		0x2700u
#define SCC30_CMD_FETCH_DATA			0xE000u
#define SCC30_CMD_ART					0x2B32u
#define SCC30_CMD_BREAK					0x3093u
#define SCC30_CMD_SOFT_RESET			0x30A2u
#define SCC30_CMD_HEATER_ENABLE			0x306Du
#define SCC30_CMD_HEATER_DISABLE		0x3066u
#define SCC30_CMD_STATUS_REG			0xF32Du
#define SCC30_CMD_CLEAR_STATUS			0x3041u

// ############### Wiederholgenauigkeiten #################
static const uint8_t SCC30_REPEATABILITY_VALS[18u] = {
	//   LOW    MED   HIGH
		0x32u, 0x24u, 0x2Fu,	// 0.5 MPS
		0x30u, 0x26u, 0x2Du,	// 1 MPS
		0x36u, 0x20u, 0x2Bu,	// 2 MPS
		0x34u, 0x22u, 0x29u,	// 4 MPS
		0x37u, 0x21u, 0x2Au,	// 10 MPS
		0x00u, 0x0Bu, 0x16u		// Single Shot
};

// ############## aktueller Sensor-Status #################
#define SCC30_INIT_PENDING			0x00u
#define SCC30_INIT_DONE				0x01u
#define SCC30_I2C_INIT_DONE			0x02u
#define SCC30_CRC_INIT_DONE			0x04u
#define SCC30_MEASUREMENT_STOPPED	0x00u
#define SCC30_MEASUREMENT_RUNNING	0x01u
#define SCC30_HEATER_DISABLED		0x00u
#define SCC30_HEATER_ENABLED		0x01u

typedef struct{
	uint8_t init_state : 3;
	uint8_t measurement_state : 1;
	uint8_t heater_state : 1;
	uint8_t acquisition_mode;
	uint16_t measurement_command;
	uint16_t current_temp;
	uint16_t current_humid;
}SensorState;

static SensorState sensor_state = {
		.init_state = SCC30_INIT_PENDING,
		.acquisition_mode = 0xFFu,
		.measurement_command = 0x00u,
		.measurement_state = SCC30_MEASUREMENT_STOPPED,
		.heater_state = SCC30_HEATER_DISABLED,
		.current_temp = 0,
		.current_humid = 0
};

// ############## Private Hilfsfunktionen #################

static uint8_t SCC30_sendCommand(uint16_t cmd){
	uint8_t result = 0;
	uint8_t buffer[2] = {0};
	// Befehl MSB-First an den Sensor senden
	buffer[0] = (cmd >> 8u) & 0xFFu;
	buffer[1] = cmd & 0xFFu;
	result = SCC30_sendI2C(buffer, sizeof(buffer));
	return result;
}


// ################# Nutzer-Funktionen ####################

// --------------------------------------------------------

uint8_t SCC30_init(uint32_t mode, uint32_t repeatability){
	uint8_t result = SCC30_OK;
	uint16_t status_reg = 0x0000u;
	// I2C Initialisieren
	if((sensor_state.init_state & SCC30_I2C_INIT_DONE) == 0x00u){
		result = SCC30_initI2C();
		if(result != SCC30_OK){
			return result;
		}
		sensor_state.init_state |= SCC30_I2C_INIT_DONE;
	}
#ifdef SCC30_USE_CRC
	// CRC Initialisieren
	if((sensor_state.init_state & SCC30_CRC_INIT_DONE) == 0x00u){
		result = SCC30_initCRC8();
		if(result != SCC30_OK){
			return result;
		}
		// Konfiguration testen
		result = SCC30_calcCRC8(SCC30_CRC_TEST_VAL);
		if(result != SCC30_CRC_EXPECTED_RESULT){
			return SCC30_CRC_ERROR;
		}
		sensor_state.init_state |= SCC30_CRC_INIT_DONE;
	}
#endif
	// Sensor zurücksetzen und Status-Register zur Kontrolle auslesen
	result = SCC30_reset();
	if(result != SCC30_OK){
		return result;
	}
//	result = SCC30_clearStatus();
//	if(result != SCC30_OK){
//		return result;
//	}
	status_reg = SCC30_getStatus();
	if((status_reg &= 0x8000u) == 0u){
		return SCC30_ERROR;
	}
	// Modus setzen
	result = SCC30_setMode(mode, repeatability);
	if(result == SCC30_OK){
		// Wenn die Initialisierung angenommen wurde, wird dies im Status vermerkt
		sensor_state.init_state |= SCC30_INIT_DONE;
	}
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_getRawData(uint16_t* temp, uint16_t* humid){
	uint8_t result = SCC30_OK;
	uint8_t timeout_counter = 0;
#ifdef SCC30_USE_CRC
	// CRC-Überprüfung aktiv -> alle 6 Bytes müssen ausgelesen werden
	uint8_t buffer[6] = {0};
	uint8_t crc_val = 0;   // Ergebnis der CRC-Berechnung
#else
	// CRC-Überprüfung inaktiv -> Nach dem 5. Byte kann die Übertragung abgebrochen werden
	uint8_t buffer[5] = {0};
#endif
	// Überprüfen, ob der Sensor richtig konfiguriert wurde
	if((sensor_state.init_state & SCC30_INIT_DONE) == 0x00u){
		return SCC30_NOT_INITIALIZED;
	}
	// Das Aulesen der Messergebnisse unterscheidet sich je nach Sensor-Modus
	if(sensor_state.acquisition_mode == SCC30_MODE_SINGLE_SHOT){
		// Single-Shot -> Messbefehl senden
		result = SCC30_sendCommand(sensor_state.measurement_command);
		if(result != SCC30_OK){
			return result;
		}
		// Messwerte auslesen
		do{
			SCC30_delayMs(SCC30_STD_DELAY);
			result = SCC30_readI2C(buffer, sizeof(buffer));
			timeout_counter++;
			if(timeout_counter == SCC30_TIMEOUT_CYCLES){
				// Kein Antwort in der definierten Zeit -> Abbruch
				return SCC30_ERROR;
			}
		} while(result != SCC30_OK);
		// Messwerte rekonstruieren
		sensor_state.current_temp = (uint16_t)buffer[0] << 8u;
		sensor_state.current_temp |= buffer[1];
		sensor_state.current_humid = (uint16_t)buffer[3] << 8u;
		sensor_state.current_humid |= buffer[4];
#ifdef SCC30_USE_CRC
		// Erfolgreich Daten empfangen -> CRC-Berechnung durchführen
		crc_val = SCC30_UNLOCK_CRC;
#endif
	}
	else{
		// Periodic -> Überprüfen, ob die Messung läuft
		if(sensor_state.measurement_state == SCC30_MEASUREMENT_STOPPED){
			return SCC30_ERROR;
		}
		// Überprüfen, ob neue Werte zum Auslesen bereit liegen
		result = SCC30_sendCommand(SCC30_CMD_FETCH_DATA);
		if(result != SCC30_OK){
			return result;
		}
		SCC30_delayMs(SCC30_STD_DELAY);
		result = SCC30_readI2C(buffer, sizeof(buffer));
		//result = SCC30_sendCommandAndReadI2C(SCC30_CMD_FETCH_DATA, buffer, sizeof(buffer));
		if(result == SCC30_OK){
			// Neue Messwerte vorhanden -> bestehende aktualisieren
			sensor_state.current_temp = (uint16_t)buffer[0] << 8u;
			sensor_state.current_temp |= buffer[1];
			sensor_state.current_humid = (uint16_t)buffer[3] << 8u;
			sensor_state.current_humid |= buffer[4];
#ifdef SCC30_USE_CRC
			// Erfolgreich Daten empfangen -> CRC-Berechnung durchführen
			crc_val = SCC30_UNLOCK_CRC;
#endif
		}
		else{
			/* Im Falle eines NACKs ist kein Übertragungsfehler aufgetreten,
			 * sondern es liegen noch keine neuen Daten bereit -> Fehlerzustand 'korrigieren'
			 */
			result = SCC30_OK;
		}
	}
#ifdef SCC30_USE_CRC
	// CRC Werte überprüfen
	if(crc_val == SCC30_UNLOCK_CRC){
		// Die Ergebnisse werden auch bei einem Fehler noch in die Argumente kopiert!
		crc_val = SCC30_calcCRC8(sensor_state.current_temp);
		if(crc_val != buffer[2]){
			// Fehler in der Temperatur-Checksumme
			result = SCC30_CRC_ERROR;
		}
		crc_val = SCC30_calcCRC8(sensor_state.current_humid);
		if(crc_val != buffer[5]){
			// Fehler in der Feuchtigkeits-Checksumme
			result = SCC30_CRC_ERROR;
		}
	}
#endif
	// Aktuelle Werte kopieren
	if(temp != NULL){
		*temp = sensor_state.current_temp;
	}
	if(humid != NULL){
		*humid = sensor_state.current_humid;
	}
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_getHumidAndTempC(uint32_t* humidity, int32_t* temperatureC){
	uint8_t result = SCC30_OK;
	// Messwerte aktualisieren
	result = SCC30_getRawData(NULL, NULL);
	if(result == SCC30_OK){
		// Aktualisierung erfolgreich -> Werte nach der Formel aus dem Datenblatt berechnen
		*temperatureC = ((175 * sensor_state.current_temp * SCC30_TEMP_DP_FACTOR) / 0xFFFFu) - (45 * SCC30_TEMP_DP_FACTOR);
		*humidity = (100 * sensor_state.current_humid * SCC30_HUMID_DP_FACTOR) / 0xFFFFu;
	}
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_getHumidAndTempF(uint32_t* humidity, int32_t* temperatureF){
	uint8_t result = SCC30_OK;
	// Messwerte aktualisieren
	result = SCC30_getRawData(NULL, NULL);
	if(result == SCC30_OK){
		// Aktualisierung erfolgreich -> Werte nach der Formel aus dem Datenblatt berechnen
		*temperatureF = ((315 * sensor_state.current_temp * SCC30_TEMP_DP_FACTOR) / 0xFFFFu) - (49 * SCC30_TEMP_DP_FACTOR);
		*humidity = (100 * sensor_state.current_humid * SCC30_HUMID_DP_FACTOR) / 0xFFFFu;
	}
	return result;
}

// --------------------------------------------------------

int32_t SCC30_getTemperatureC(){
	int32_t result = SCC30_OK;
	// Messwerte aktualisieren
	result = SCC30_getRawData(NULL, NULL);
	if(result == SCC30_OK){
		// Aktualisierung erfolgreich -> Temperatur nach der Formel aus dem Datenblatt berechnen
		result = ((175 * sensor_state.current_temp * SCC30_TEMP_DP_FACTOR) / 0xFFFFu) - (45 * SCC30_TEMP_DP_FACTOR);
	}
	else{
		result = SCC30_INVALID_DATA;
	}
	return result;
}

// --------------------------------------------------------

int32_t SCC30_getTemperatureF(){
	int32_t result = SCC30_OK;
	// Messwerte aktualisieren
	result = SCC30_getRawData(NULL, NULL);
	if(result == SCC30_OK){
		// Aktualisierung erfolgreich -> Temperatur nach der Formel aus dem Datenblatt berechnen
		result = ((315 * sensor_state.current_temp * SCC30_TEMP_DP_FACTOR) / 0xFFFFu) - (49 * SCC30_TEMP_DP_FACTOR);
	}
	else{
		result = SCC30_INVALID_DATA;
	}
	return result;
}

// --------------------------------------------------------

uint32_t SCC30_getHumidity(){
	uint32_t result = SCC30_OK;
	// Messwerte aktualisieren
	result = SCC30_getRawData(NULL, NULL);
	if(result == SCC30_OK){
		// Aktualisierung erfolgreich -> Luftfeuchtigkeit nach der Formel aus dem Datenblatt berechnen
		result = (100 * sensor_state.current_humid * SCC30_HUMID_DP_FACTOR) / 0xFFFFu;
	}
	else{
		result = SCC30_INVALID_DATA;
	}
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_stopPeriodicMeasurement(){
	uint8_t result = SCC30_OK;
	// Modus überprüfen
	if(sensor_state.acquisition_mode == SCC30_MODE_SINGLE_SHOT){
		return SCC30_ERROR;
	}
	// Nur Befehl senden, wenn die Messung gerade läuft
	if(sensor_state.measurement_state == SCC30_MEASUREMENT_RUNNING){
		// Messung läuft -> Break Kommando senden
		result = SCC30_sendCommand(SCC30_CMD_BREAK);
		if(result == SCC30_OK){
			// Erfolg -> Zustand aktualisieren
			sensor_state.measurement_state = SCC30_MEASUREMENT_STOPPED;
		}
	}
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_resumePeriodicMeasurement(){
	uint8_t result = SCC30_OK;
	// Modus überprüfen
	if(sensor_state.acquisition_mode == SCC30_MODE_SINGLE_SHOT){
		return SCC30_ERROR;
	}
	// Nur Befehl senden, wenn die Messung nicht läuft
	if(sensor_state.measurement_state == SCC30_MEASUREMENT_STOPPED){
		// Messung läuft -> Periodische Messung starten
		result = SCC30_sendCommand(sensor_state.measurement_command);
		if(result == SCC30_OK){
			// Erfolg -> Zustand aktualisieren
			sensor_state.measurement_state = SCC30_MEASUREMENT_RUNNING;
		}
	}
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_setMode(uint32_t mode, uint32_t repeatability){
	uint8_t result = SCC30_OK;
	uint16_t mode_cmd = 0x0000u;
	uint8_t buffer[5] = {0};
	// Argumenten Check
	if(repeatability > SCC30_REPEATABILITY_HIGH){
		return SCC30_INVALID_PARAM;
	}
	// Den Befehl entsprechend der Modi konstruieren
	switch(mode){
	case SCC30_MODE_SINGLE_SHOT:
		mode_cmd = SCC30_CMD_START_SINGLE_SHOT;
		break;
	case SCC30_MODE_PERIODIC_MPS_05:
		mode_cmd = SCC30_CMD_START_PERIODIC_05;
		break;
	case SCC30_MODE_PERIODIC_MPS_1:
		mode_cmd = SCC30_CMD_START_PERIODIC_1;
		break;
	case SCC30_MODE_PERIODIC_MPS_2:
		mode_cmd = SCC30_CMD_START_PERIODIC_2;
		break;
	case SCC30_MODE_PERIODIC_MPS_4:
		mode_cmd = SCC30_CMD_START_PERIODIC_4;
		break;
	case SCC30_MODE_PERIODIC_MPS_10:
		mode_cmd = SCC30_CMD_START_PERIODIC_10;
		break;
	default:
		// Dieser Fall sollte nicht eintreten!
		return SCC30_INVALID_PARAM;
		break;
	}
	// niederes Byte entspricht der Wiederholungsgenauigkeit und hängt zusätzlich vom Modus ab
	mode_cmd |= SCC30_REPEATABILITY_VALS[mode + repeatability];
	// Kommando senden
	result = SCC30_sendCommand(mode_cmd);
	if(result == SCC30_OK){
		// Neuen Modus im Status vermerken
		sensor_state.acquisition_mode = mode;
		sensor_state.measurement_command = mode_cmd;  // Speichern, um den Befehl nicht jedesmal neu zu konstruieren
		if(mode == SCC30_MODE_SINGLE_SHOT){
			// Single-Shot -> Einmal Dummy auslesen um den Befehl abzuschließen
			do {
				SCC30_delayMs(SCC30_STD_DELAY);
			}while(SCC30_readI2C(buffer, sizeof(buffer)) != SCC30_OK);
		}
		else{
			// Periodic -> Messung am Laufen vermerken
			sensor_state.measurement_state = SCC30_MEASUREMENT_RUNNING;
		}
	}
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_reset(){
	uint8_t result = SCC30_OK;
	// Zu erst ein Break-Commando senden, falls der Sensor noch im Periodic-Modus läuft
	result = SCC30_sendCommand(SCC30_CMD_BREAK);
	SCC30_delayMs(SCC30_RESET_DELAY);
	if(result != SCC30_OK){
		return result;
	}
	// Befehl senden und Delay auslösen
	result = SCC30_sendCommand(SCC30_CMD_SOFT_RESET);
	SCC30_delayMs(SCC30_RESET_DELAY);
	if(result == SCC30_OK){
		// Erfolg -> Status zurücksetzen
		sensor_state.init_state &= ~SCC30_INIT_PENDING;
		sensor_state.acquisition_mode = 0xFFu;
		sensor_state.measurement_command = 0x00u;
		sensor_state.measurement_state = SCC30_MEASUREMENT_STOPPED;
		sensor_state.heater_state = SCC30_HEATER_DISABLED;
		sensor_state.current_temp = 0;
		sensor_state.current_humid = 0;
	}
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_enableHeater(){
	uint8_t result = SCC30_OK;
	// Befehl nur senden, wenn der Heater inaktiv ist
	if(sensor_state.heater_state == SCC30_HEATER_DISABLED){
		result = SCC30_sendCommand(SCC30_CMD_HEATER_ENABLE);
		if(result == SCC30_OK){
			// Erfolg -> Zustand aktualisieren
			sensor_state.heater_state = SCC30_HEATER_ENABLED;
		}
	}
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_disableHeater(){
	uint8_t result = SCC30_OK;
	// Befehl nur senden, wenn der Heater aktiv ist
	if(sensor_state.heater_state == SCC30_HEATER_ENABLED){
		result = SCC30_sendCommand(SCC30_CMD_HEATER_DISABLE);
		if(result == SCC30_OK){
			// Erfolg -> Zustand aktualisieren
			sensor_state.heater_state = SCC30_HEATER_DISABLED;
		}
	}
	return result;
}

// --------------------------------------------------------

uint16_t SCC30_getStatus(){
	uint16_t result = SCC30_OK;
#ifdef SCC30_USE_CRC
	// CRC-Überprüfung aktiv -> alle 3 Bytes müssen ausgelesen werden
	uint8_t buffer[3] = {0};
	uint8_t crc_val = 0;
#else
	// CRC-Überprüfung inaktiv -> Nach dem 2. Byte kann die Übertragung abgebrochen werden
	uint8_t buffer[2] = {0};
#endif
	// Befehl senden und Register auslesen
	result = SCC30_sendCommandAndReadI2C(SCC30_CMD_STATUS_REG, buffer, sizeof(buffer));
	if(result != SCC30_OK){
		return result;
	}
	// Erfolg -> Ergebnis konstruieren
	result = (uint16_t)buffer[0] << 8u;
	result |= buffer[1];
#ifdef SCC30_USE_CRC
	// CRC überprüfen
	crc_val = SCC30_calcCRC8(result);
	if(crc_val != buffer[2]){
		result = SCC30_CRC_ERROR;
	}
#endif
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_clearStatus(){
	uint8_t result = SCC30_OK;
	// Befehl senden
	result = SCC30_sendCommand(SCC30_CMD_CLEAR_STATUS);
	return result;
}
