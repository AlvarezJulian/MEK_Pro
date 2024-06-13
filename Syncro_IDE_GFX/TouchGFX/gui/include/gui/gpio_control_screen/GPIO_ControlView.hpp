#ifndef GPIO_CONTROLVIEW_HPP
#define GPIO_CONTROLVIEW_HPP

#include <gui_generated/gpio_control_screen/GPIO_ControlViewBase.hpp>
#include <gui/gpio_control_screen/GPIO_ControlPresenter.hpp>

#ifndef SIMULATOR
extern "C" {
#include "stm32f7xx.h"
}
#endif

class GPIO_ControlView: public GPIO_ControlViewBase {
public:
	GPIO_ControlView();
	virtual ~GPIO_ControlView() {
	}
	virtual void setupScreen();
	virtual void tearDownScreen();

#ifndef SIMULATOR
	virtual void LED_ON();
	virtual void LED_OFF();
#endif

protected:
};

#endif // GPIO_CONTROLVIEW_HPP
