#ifndef MODEL_HPP
#define MODEL_HPP

#include <touchgfx/Utils.hpp>
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

class Model {
public:
	Model();

	void bind(ModelListener *listener) {
		modelListener = listener;
	}

	void tick();

#ifndef SIMULATOR

	void HW_LED_OFF();
	void HW_LED_green_ON();
	void HW_LED_orange_ON();
	void HW_LED_red_ON();
//	void Interface_CanSlider_send(int value);
	void Interface_Can_send(int CAN_ID);

#endif // Simulator

protected:
	ModelListener *modelListener;


private:

};

#endif // MODEL_HPP
