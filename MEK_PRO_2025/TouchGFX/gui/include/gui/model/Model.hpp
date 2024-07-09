#ifndef MODEL_HPP
#define MODEL_HPP

#include <touchgfx/Utils.hpp>
#include <touchgfx/Screen.hpp>
#include <texts/TextKeysAndLanguages.hpp>

#ifndef SIMULATOR
extern "C" {
#include "edt_bsp_uart.h"
#include "stm32f7xx_hal.h"
#include <string.h>
#include <stdio.h>
#include "edt_bsp_io.h"
#include "edt_bsp_can.h"
#include <can.h>
#include "main.h"
#include "usbd_cdc_if.h"
}
#endif // Simulator

class ModelListener;
class FrontendApplication;
//class TopMenu;

enum listOfWindows {
	LOGINWINDOW = 1,
	WELLCOMEWINDOW,
	VEHICLECHECKWINDOW,
	STARTWINDOW,
	STATUSWINDOW,
	WORKSHOPWINDOW,
	CHRASHWINDOW,
};

enum listOfLanguages {
	GERMAN = 0, ENGLISH
};

class Model {
public:
	Model();

	void bind(ModelListener *listener) {
		modelListener = listener;
	}

	void bind(FrontendApplication *frontendApp) {
		frontendApplication = frontendApp;
	}

	void tick();

#ifndef SIMULATOR

	void HW_LED_OFF();
	void HW_LED_green_ON();
	void HW_LED_orange_ON();
	void HW_LED_red_ON();
//	void Interface_CanSlider_send(int value);
	void Interface_Can_send(CANBUS_TX_ID CAN_ID);

	/*
	 *  set
	 */

	void setWifiSignal(uint8_t wifiSignal) {
		current_Wifi_Signal = wifiSignal;
	}
	void setBluetoothSignal(uint8_t btSignal) {
		current_bluetooth_Status = btSignal;
	}
	void setCurrentHour(int16_t saveHour) {
		current_hour = saveHour;
	}
	void setCurrentMinute(int16_t saveMinute) {
		current_minute = saveMinute;
	}
	void setCurrentSecond(int16_t saveSecond) {
		current_second = saveSecond;
	}
	void setCurrentUserID(char *UserID) {
		current_UserID = UserID;
	}
	void SetLogStatus(bool state) {
		current_log_Status = state;
	}
	void SetWorkshopStatus(bool state) {
		current_Workshop_Status = state;
	}
	void SetCrashStatus(bool state) {
		current_Crash_Status = state;
	}
	void SetEZBHour(uint16_t hour) {
		current_EBZ_hour = hour;
	}
	void SetEZBMinute(uint16_t minute) {
		current_EBZ_minute = minute;
	}
	void SetEZBSecond(uint16_t second) {
		current_EBZ_second = second;
	}
	void SetELSStatus(bool state) {
		current_ELS_status = state;
	}
	void SetLogHour(uint16_t loghour) {
		current_log_hour = loghour;
	}
	void SetLogMinute(uint16_t logminute) {
		current_log_minute = logminute;
	}
	void SetLogSecond(uint16_t logsecond) {
		current_log_second = logsecond;
	}
	/*
	 * Get
	 */

	uint8_t getWifiSignal(uint8_t wifiSignal) {
		return current_Wifi_Signal;
	}
	bool getBluetoothSignal(uint8_t wifiSignal) {
		return current_bluetooth_Status;
	}
	int16_t getCurrentHour() {
		return current_hour;
	}

	int16_t getCurrentMinute() {
		return current_minute;
	}
	int16_t getCurrentSecond() {
		return current_second;
	}
	char* getCurrentUserID() {
		return current_UserID;
	}
	bool getLogStatus() {
		return current_log_Status;
	}
	bool getWorkshopStatus() {
		return current_Workshop_Status;
	}
	bool getCrashStatus() {
		return current_Crash_Status;
	}
	uint16_t getEZBHour() {
		return current_EBZ_hour;
	}
	uint16_t getEZBMinute() {
		return current_EBZ_minute;
	}
	uint16_t getEZBSecond() {
		return current_EBZ_second;
	}
	bool getELSStatus() {
		return current_ELS_status;
	}
	uint16_t getLogHour() {
		return current_log_hour;
	}
	uint16_t getLogMinute() {
		return current_log_minute;
	}
	uint16_t getLogSecond() {
		return current_log_second;
	}
#endif // Simulator

protected:
	ModelListener *modelListener;
	FrontendApplication *frontendApplication;

	//TopMenu Save Data:
	uint8_t current_Wifi_Signal;
	bool current_bluetooth_Status;
	uint16_t current_hour;
	uint16_t current_minute;
	uint16_t current_second;

	//Start Screen save Data:
	char ID_Data[32];
	char *current_UserID;
	bool current_log_Status;
	bool current_Workshop_Status;
	bool current_Crash_Status;
	uint16_t current_EBZ_hour;
	uint16_t current_EBZ_minute;
	uint16_t current_EBZ_second;
	bool current_ELS_status;
	// Botom Menu Save Data:
	uint16_t current_log_hour;
	uint16_t current_log_minute;
	uint16_t current_log_second;

private:

};

#endif // MODEL_HPP
