#include <gui/gpio_control_screen/GPIO_ControlView.hpp>

GPIO_ControlView::GPIO_ControlView() {

}

void GPIO_ControlView::setupScreen() {
	GPIO_ControlViewBase::setupScreen();
}

void GPIO_ControlView::tearDownScreen() {
	GPIO_ControlViewBase::tearDownScreen();
}

#ifndef SIMULATOR
void GPIO_ControlView::LED_ON() {

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);

}

void GPIO_ControlView::LED_OFF() {
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);
}
#endif
