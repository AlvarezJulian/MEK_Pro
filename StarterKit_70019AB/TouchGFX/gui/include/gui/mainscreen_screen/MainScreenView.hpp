#ifndef MAINSCREENVIEW_HPP
#define MAINSCREENVIEW_HPP

#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

class MainScreenView : public MainScreenViewBase
{
public:
	MainScreenView();
	virtual ~MainScreenView() {}
	virtual void setupScreen();
	virtual void tearDownScreen();

	// Schnittstelle System -> GUI
	void updateTemperature(int32_t temp);
	void updateHumidity(uint32_t humid);
	void sensorConnected();
	void sensorDisconnected();

	// Schnittstelle GUI -> System
	void handleSliderValue(int value);
protected:
	// Konfiguration der Fade-Animation
	const uint16_t FADE_DURATION = 150u;
	const touchgfx::EasingEquation FADE_EASING_EQUATION = touchgfx::EasingEquations::expoEaseIn;
};

#endif // MAINSCREENVIEW_HPP
