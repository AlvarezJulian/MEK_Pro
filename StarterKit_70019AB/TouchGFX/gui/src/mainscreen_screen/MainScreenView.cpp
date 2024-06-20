#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

MainScreenView::MainScreenView()
{

}

void MainScreenView::setupScreen()
{
	MainScreenViewBase::setupScreen();

	// Text-Felder auf den Ausgangszustand setzen
	// Die Ressource hat absichtlich KEINE Wildcard, damit der aktuelle Wert nicht angezeigt wird
	textArea_temp.setTypedText(TypedText(T_RESOURCEID_NOVALUE));
	textArea_temp.invalidate();
	textProgress_humid.setTypedText(TypedText(T_RESOURCEID_NOVALUE));
	textProgress_humid.invalidate();

	// Aktuellen Sensor-Status vom Model abfragen
	presenter->updateSensorState();
}

void MainScreenView::tearDownScreen()
{
	MainScreenViewBase::tearDownScreen();
}

void MainScreenView::updateTemperature(int32_t temp)
{
	// Wert in das Textfeld schreiben
	// Wir verwenden hier ein normales Textfeld, da der TextProgress keine negativen Zahlen darstellen kann
	// Die letzte Dezimalstelle des Werts entspricht dem Nachkommaanteil
	Unicode::snprintf(textArea_tempBuffer, TEXTAREA_TEMP_SIZE, "%d.%d", temp / 10, temp % 10);
	textArea_temp.invalidate();
}

void MainScreenView::updateHumidity(uint32_t humid)
{
	// Wert in das Textfeld schreiben
	textProgress_humid.setValue(humid);
	textProgress_humid.invalidate();
}

void MainScreenView::sensorConnected()
{
	// Sensor ist verbunden -> Textfelder auf die Messwertdarstellung setzen
	textArea_temp.setTypedText(TypedText(T_RESOURCEID_DEFAULTTEMP));
	textProgress_humid.setTypedText(TypedText(T_RESOURCEID_DEFAULTHUMID));
}

void MainScreenView::sensorDisconnected()
{
	// Sensor ist getrennt -> Textfelder zurücksetzen
	textArea_temp.setTypedText(TypedText(T_RESOURCEID_NOVALUE));
	textArea_temp.invalidate();
	textProgress_humid.setTypedText(TypedText(T_RESOURCEID_NOVALUE));
	textProgress_humid.invalidate();
}

void MainScreenView::handleSliderValue(int value)
{
	// Text-Feld sichtbar schalten, Wert aktualisieren und Animation starten
	textArea_Backlight.setAlpha(255u);
	Unicode::snprintf(textArea_BacklightBuffer, TEXTAREA_BACKLIGHT_SIZE, "%d", value);
	textArea_Backlight.cancelFadeAnimation();
	textArea_Backlight.startFadeAnimation(0, FADE_DURATION, FADE_EASING_EQUATION);
	// Aktuellen Slider-Wert an das System weiterleiten
	presenter->updateBacklight((uint8_t)value);
}
