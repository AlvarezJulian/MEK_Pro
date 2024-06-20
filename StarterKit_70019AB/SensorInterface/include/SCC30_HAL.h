/*
 * SCC30_HAL.h
 *
 *  Created on: 15.10.2020
 *      Author: Rausch_Luca
 */

#ifndef APPLICATION_USER_SCC30_HAL_H_
#define APPLICATION_USER_SCC30_HAL_H_

#include <stdint.h>

// Schaltet die Nutzung der CRC-Einheit frei
#define SCC30_ENABLE_CRC

// I2C-Adresse des SCC30 -> auf STM32 Systemen muss die Adresse schon bei der Übergabe um 1 Bit verschoben sein
#define SCC30_I2C_ADDR		(0x44u << 1u)

#ifdef SCC30_ENABLE_CRC
// CRC-Konfiguration
// 8 Bit breit (x^8 + x^5 + x^4 + 1) in Standarddarstellung
#define SCC30_CRC_POLYNOMIAL			0x31u
#define SCC30_CRC_INIT_VAL				0xFFu
#endif

/*
 *  Initialisiert die I2C-Schnittstelle für den Sensor.
 *  @return: Status der Initialisierung -> 0 für Erfolg
 */
uint8_t SCC30_initI2C();

/*
 *  Sendet ein Byte-Array an den Sensor. Erzeugt sowohl eine Start- als auch Stopp-Bedingung
 *  @param data: Zeiger auf die zu sendenen Daten
 *  @param size: Anzahl der Bytes die gesendet werden sollen
 *  @return: Ergebnis der Kommunikationn -> 0 für Erfolg
 */
uint8_t SCC30_sendI2C(uint8_t* data, uint32_t size);

/*
 *  Liest Bytes vom Sensor. Erzeugt sowohl eine Start- als auch Stopp-Bedingung
 *  @param buffer: Zeiger auf den Zielspeicher
 *  @param size: Anzahl der Bytes die gelesen werden sollen
 *  @return: Ergebnis der Kommunikationn -> 0 für Erfolg
 */
uint8_t SCC30_readI2C(uint8_t* buffer, uint32_t size);

/*
 *  Sendet 2 Bytes an den Sensor und ließt ihn direkt im Anschluss aus.
 *  Es darf keine Stopp-Bedingung zwischen Schreiben und Lesen erzeugt werden,
 *  stattdessen eine Repeated-Start-Bedingung. Nach dem Lesen kann eine Stopp-Bedingung
 *  übermittelt werden.
 *  @param cmd: 16-Bit Befehl der MSB-First an den Sensor geschickt wird
 *  @param buffer: Zeiger auf den Zielspeicher
 *  @param size: Anzahl der Bytes die gelesen werden sollen
 *  @return: Ergebnis der Kommunikationn -> 0 für Erfolg
 */
uint8_t SCC30_sendCommandAndReadI2C(uint16_t command, uint8_t* buffer, uint32_t size);

/*
 * Pausiert die Ausführung für die angegebene Zeit in Millisekunden
 */
void SCC30_delayMs(uint32_t delay_ms);

#ifdef SCC30_ENABLE_CRC

/*
 *  Initialisiert das CRC Modul mit dem 8-Bit Polynom SCC30_CRC_POLYNOMIAL und dem Initialisierungswert SCC30_CRC_INIT_VAL
 *  @return: Ergebnis der Initialisierung -> 0 für Erfolg
 */
uint8_t SCC30_initCRC8();

/*
 *  Berechnet die 8-Bit Checksumme eines 16-Bit Werts
 *  @return: Berechnete 8-Bit Checksumme
 */
uint8_t SCC30_calcCRC8(uint16_t data);

#endif

#endif /* APPLICATION_USER_SCC30_HAL_H_ */
