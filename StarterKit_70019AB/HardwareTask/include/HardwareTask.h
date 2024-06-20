/*
 * HardwareTask.h
 *
 *  Created on: 20.10.2020
 *      Author: Rausch_Luca
 */

#ifndef APPLICATION_USER_HARDWARETASK_H_
#define APPLICATION_USER_HARDWARETASK_H_

#include <stdint.h>

// Kernel einbinden
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

// Task-Konfiguration
#define configHARDWARETASK_PRIO		(tskIDLE_PRIORITY + 1u)			// Priorität
#define configHARDWARETASK_SIZE		(500u)							// Stack-Größe (in Words)
#define configHARDWARETASK_PERIOD	(100u)							// Periodischs Intervall, in welchem der Task ausgeführt wird
#define DATA_QUEUE_NMBR_OF_ELEM		(5u)							// Anzahl der Elemente in der Daten-Queue
#define DATA_QUEUE_SIZE_OF_ELEM		(sizeof(struct Data_Package))			// Größe der Elemente in der Daten-Queue
#define CMD_QUEUE_NMBR_OF_ELEM		(5u)							// Anzahl der Elemente in der Kommando-Queue
#define CMD_QUEUE_SIZE_OF_ELEM		(sizeof(Cmd_Package))			// Größe der Elemente in der Kommando-Queue

// Aufzählung der Nachrichten-Arten
enum Msg_Type {
	TEMPERATURE_VALUE,			// Temperatur
	HUMIDITY_VALUE,				// Luftfeuchtigkeit
	SENSOR_CONNECTED,			// Bestätigung, dass der Sensor verbunden ist
	SENSOR_DISCONNECTED,		// Kein Sensor ist verbunden
	NMBR_OF_MSG_TYPES			// Anzahl der Nachrichten-Arten
};

// Aufzählung der Fehler-Typen (entspricht 1:1 der Definition von HAL_STATUS)
enum ERROR_TYPE {
	ERROR_OK = 0x00,			// Kein Fehler, alles ist in Ordnung
	ERROR_GENERAL = 0x01,		// Allgemeiner Fehler -> meist Hardware-Probleme
	ERROR_BUSY = 0x02,			// Die Schnittstelle ist beschäftigt und kann momentan nicht antworten (sollte nie auftreten)
	ERROR_TIMEOUT = 0x03		// Es konnte keine Antwort von der Gegenstelle innerhalb des definierten Zeitfensters erhalten werden
};

// Struktur für ein Nachrichten-Paket
struct Data_Package {
	enum Msg_Type type;			// Art der Nachricht
	uint32_t data;				// ggf. Daten zu der Nachricht
};

// Verweise auf die Queue-Handles -> definiert in 'HardwareTask.c'
extern QueueHandle_t dataQueue;

// Prototyp für die Task-Funktion
void hardwareTask(void* param);

// Prototyp für den Zugriff auf die Backlight-PWM
void setPWMDuty(uint32_t duty);

#endif /* APPLICATION_USER_HARDWARETASK_H_ */
