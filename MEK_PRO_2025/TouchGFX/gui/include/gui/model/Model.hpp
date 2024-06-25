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

enum listOfWindows {
	WELLCOMEWINDOW = 1,
	STARTWINDOW,
	WORKSHOPWINDOW,
	VEHICLEWINDOW,
	VEHICLECHECKWINDOW,
	CHRASHWINDOW,
};


enum listOfLanguages{
	DEUTSCH = DE+1,
	ENLGISH
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
//	void forceScreenTransition(listOfWindows list);

#ifndef SIMULATOR

	void HW_LED_OFF();
	void HW_LED_green_ON();
	void HW_LED_orange_ON();
	void HW_LED_red_ON();
//	void Interface_CanSlider_send(int value);
	void Interface_Can_send(CANBUS_TX_ID CAN_ID);

#endif // Simulator

protected:
	ModelListener *modelListener;
	FrontendApplication *frontendApplication;

private:

};

#endif // MODEL_HPP
