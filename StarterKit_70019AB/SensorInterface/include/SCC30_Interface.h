/*
 * SCC30_Interface.h
 *
 *  Created on: 15.10.2020
 *      Author: Rausch_Luca
 */

#ifndef APPLICATION_USER_SCC30_INTERFACE_H_
#define APPLICATION_USER_SCC30_INTERFACE_H_

#include <stdlib.h>
#include <stdint.h>

// Schaltet die CRC-Überprüfung frei -> Bitte auch in der SCC30_HAL.h freischalten!
#define SCC30_USE_CRC

/*
 * Über die Werte der folgenden Macros kann die Anzahl der Nachkommastellen
 * definiert werden, welche bei den Rückgabe-Werten der get-Funktionen (außer RawData)
 * genutzt werden. Es handelt sich dabei immer noch um Integer-Zahlen, jedoch um den Faktor
 * 10^n multipliziert mit n = Anzahl der Nachkommastellen.
 * Beispiel: n = 2  -> Das Ergebnis von SCC30_getTemperatureC() sei 2345
 * Dann wäre die tatsächliche Temperatur 23,45 °C, da die letzten 2 Dezimalstellen den
 * Nachkommaanteil beschreiben.
 * Mehr als 2 Nachkommastellen sind bei dem SCC30 nicht sinnvoll nutzbar.
 * Min = 0		Max = 3
 */
#define SCC30_TEMPERATURE_DEC_PLACE	1u
#define SCC30_HUMIDITY_DEC_PLACE	0u

// Modi des Sensors -> Bitte die Werte NICHT ändern!
#define SCC30_MODE_PERIODIC_MPS_05	0x00u	// 0.5 Messungen pro Sekunde
#define SCC30_MODE_PERIODIC_MPS_1	0x03u	// 1 Messung pro Sekunde
#define SCC30_MODE_PERIODIC_MPS_2	0x06u	// 2 Messungen pro Sekunde
#define SCC30_MODE_PERIODIC_MPS_4	0x09u	// 4 Messungen pro Sekunde
#define SCC30_MODE_PERIODIC_MPS_10	0x0Cu	// 10 Messungen pro Sekunde
#define SCC30_MODE_SINGLE_SHOT		0x0Fu	// Einzelmessungen

// Wiederholungsgenauigkeiten -> Bitte die Werte NICHT ändern!
#define SCC30_REPEATABILITY_LOW		0x00u
#define SCC30_REPEATABILITY_MEDIUM	0x01u
#define SCC30_REPEATABILITY_HIGH	0x02u

// Rückgabewerte der APIs
#define SCC30_OK					0x00u			// Operation erfolgreich
#define SCC30_ERROR					0xF1u			// Ein allgemeiner Fehler ist aufgetreten
#define SCC30_INVALID_PARAM			0xF2u			// Ein ungültiges Funktions-Argument wurde übergeben
#define SCC30_NOT_INITIALIZED		0xF3u			// Der Sensor ist noch nicht initialisiert!
#define SCC30_CRC_ERROR				0xF4u			// Checksumme ist nicht gültig (Nur wenn SCC30_USE_CRC freigeschaltet wurde)
#define SCC30_INVALID_DATA			0xFFFFFFFFu		// Ein Fehler ist aufgetreten -> ungültige Daten

// Bit-Masken für das Status-Register
#define SCC30_DEFAULT_STATUS		0x8010u				// Reset-Wert des Status-Registers
#define SCC30_STATUS_BIT_HEATER		(0x0001u << 13u)	// '1' -> Heizung aktiv 									'0' -> Heizung inaktiv
#define SCC30_STATUS_BIT_RESET		(0x0001u << 4u)		// '1' -> Reset festgestellt 								'0' -> kein Reset seit dem letztem 'Clear Status Register'
#define SCC30_STATUS_BIT_CMD_STATE	(0x0001u << 1u)		// '1' -> letzter Befehl konnte nicht verarbeitet werden 	'0' -> letzter Befehl erfolgreich
#define SCC30_STATUS_BIT_CRC_STATE	(0x0001u << 0u)		// '1' -> letzte empfangene Checksumme war inkorrekt 		'0' -> letzte empfangene Checksumme war korrekt

/*
 *  Initialisiert die I2C-Schnittstelle und startet den Messvorgang beim Sensor.
 *  @param mode: Arbeitsmodus des SCC30 -> gültige Arguemente lauten SCC30_MODE_XX
 *  @param repeatability: Wiederholgenauigkeit der Messung
 *  					  -> gültige Argumente lauten SCC30_REPEATABILITY_XX (LOW, MEDIUM oder HIGH)
 *  @return: Ergebnis der Initialisierung -> Fehler aus der HAL-Schicht werden weitergereicht
 */
uint8_t SCC30_init(uint32_t mode, uint32_t repeatability);

/*
 *  Aktualisiert ggf. die Messergebnisse und liefert die Luftfeuchtigkeit und Temperatur in Grad Celsius zurück.
 *  Diese Funktion sollte bevorzugt eingesetzt werden, wenn beide Werte von interesse sind.
 *  @param humidity: Zeiger auf den Speicher für die Luftfeuchtigkeit -> Wird NICHT aktualisiert, wenn der Lese-Vorgang fehlschlägt
 *  @param temperatureC: Zeiger auf den Speicher für die Temperatur -> Wird NICHT aktualisiert, wenn der Lese-Vorgang fehlschlägt
 *  @return: Ergebnis des Befehls -> Fehler aus der HAL-Schicht werden weitergereicht
 */
uint8_t SCC30_getHumidAndTempC(uint32_t* humidity, int32_t* temperatureC);

/*
 *  Aktualisiert ggf. die Messergebnisse und liefert die Luftfeuchtigkeit und Temperatur in Grad Fahrenheit zurück.
 *  Diese Funktion sollte bevorzugt eingesetzt werden, wenn beide Werte von interesse sind.
 *  @param humidity: Zeiger auf den Speicher für die Luftfeuchtigkeit -> Wird NICHT aktualisiert, wenn der Lese-Vorgang fehlschlägt
 *  @param temperatureC: Zeiger auf den Speicher für die Temperatur -> Wird NICHT aktualisiert, wenn der Lese-Vorgang fehlschlägt
 *  @return: Ergebnis des Befehls -> Fehler aus der HAL-Schicht werden weitergereicht
 */
uint8_t SCC30_getHumidAndTempF(uint32_t* humidity, int32_t* temperatureF);

/*
 *  Aktualisiert ggf. die Messergebnisse und liefert die Temperatur in Grad Celsius zurück.
 *  Wenn zusätzlich die Luftfeuchtigkeit ausgelesen wird, so sollte eine der dedizierten Funktionen genutzt werden
 *  @return: Aktuelle Temperatur in Grad Celsius -> Bei einem Fehler wird SCC30_INVALID_DATA zurückgegeben
 */
int32_t SCC30_getTemperatureC();

/*
 *  Aktualisiert ggf. die Messergebnisse und liefert die Temperatur in Grad Fahrenheit zurück.
 *  Wenn zusätzlich die Luftfeuchtigkeit ausgelesen wird, so sollte eine der dedizierten Funktionen genutzt werden
 *  @return: Aktuelle Temperatur in Grad Fahrenheit -> Bei einem Fehler wird SCC30_INVALID_DATA zurückgegeben
 */
int32_t SCC30_getTemperatureF();

/*
 *  Aktualisiert ggf. die Messergebnisse und liefert die Luftfeuchtigkeit in Prozent zurück.
 *  Wenn zusätzlich die Temperatur ausgelesen wird, so sollte eine der dedizierten Funktionen genutzt werden
 *  @return: Aktuelle Luftfeuchtigkeit in Prozent -> Bei einem Fehler wird SCC30_INVALID_DATA zurückgegeben
 */
uint32_t SCC30_getHumidity();

/*
 *  Stoppt die laufende periodische Messung.
 *  @return: Ergebnis des Befehls -> SCC30_ERROR, wenn der Sensor im Single-Shot Modus konfiguriert ist
 *  							  -> Fehler aus der HAL-Schicht werden weitergereicht
 */
uint8_t SCC30_stopPeriodicMeasurement();

/*
 *  Startet die periodische Messung.
 *  @return: Ergebnis des Befehls -> SCC30_ERROR, wenn der Sensor im Single-Shot Modus konfiguriert ist
 *  							  -> Fehler aus der HAL-Schicht werden weitergereicht
 */
uint8_t SCC30_resumePeriodicMeasurement();

/*
 *  Aktualisiert den Betriebsmodus des Sensors.
 *  @param mode: Arbeitsmodus des SCC30 -> gültige Arguemente lauten SCC30_MODE_XX
 *  @param repeatability: Wiederholgenauigkeit der Messung
 *  					  -> gültige Argumente lauten SCC30_REPEATABILITY_XX (LOW, MEDIUM oder HIGH)
 *  @return: Ergebnis des Befehls -> Fehler aus der HAL-Schicht werden weitergereicht
 */
uint8_t SCC30_setMode(uint32_t mode, uint32_t repeatability);

/*
 *  Liest die aktuellen Messergebnisse im Sensor aus. Diese Funktion wird intern von
 *  SCC30_getTemperatureC(), SCC30_getTemperatureF() und SCC30_getHumidity() genutzt und bietet
 *  die Möglichkeit, auf die Rohdaten direkt zuzugreifen.
 *  @param temp: Zeiger auf den Zielspeicher für den rohen Temperaturwert
 *  			-> Wird bei einem Fehler (außer CRC) NICHT überschrieben
 *  @param humid: Zeiger auf den Zielspeicher für den rohen Luftfeuchtigkeitswert
 *  			-> Wird bei einem Fehler (außer CRC) NICHT überschrieben
 *  @return: Ergebnis des Befehls -> Fehler aus der HAL-Schicht werden weitergereicht
 */
uint8_t SCC30_getRawData(uint16_t* temp, uint16_t* humid);

/*
 *  Setzt den Sensor zurück -> anschließend sollte SCC30_init() oder SCC30_setMode() aufgerufen werden!
 *  @return: Ergebnis des Befehls -> Fehler aus der HAL-Schicht werden weitergereicht
 */
uint8_t SCC30_reset();

/*
 *  Schaltet die interne Heizung des SCC30 ein.
 *  @return: Ergebnis des Befehls -> Fehler aus der HAL-Schicht werden weitergereicht
 */
uint8_t SCC30_enableHeater();

/*
 *  Schaltet die interne Heizung des SCC30 aus.
 *  @return: Ergebnis des Befehls -> Fehler aus der HAL-Schicht werden weitergereicht
 */
uint8_t SCC30_disableHeater();

/*
 *  Liest das Status-Register des SCC30 aus. Die einzelnen Bits können mit Hilfe der Bit-Masken (SCC30_STATUS_BIT_XX) ausgewertet werden.
 *  @return: 16-Bit Status-Register des SCC30 -> Fehler aus der HAL-Schicht werden weitergereicht
 */
uint16_t SCC30_getStatus();

/*
 *  Setzt das Status-Register auf den Ausgangs-Zustand zurück
 *  @return: Ergebnis des Befehls -> Fehler aus der HAL-Schicht werden weitergereicht
 */
uint8_t SCC30_clearStatus();

#endif /* APPLICATION_USER_SCC30_INTERFACE_H_ */
