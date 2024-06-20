#ifndef GRAPHSCREENVIEW_HPP
#define GRAPHSCREENVIEW_HPP

#include <gui_generated/graphscreen_screen/GraphScreenViewBase.hpp>
#include <gui/graphscreen_screen/GraphScreenPresenter.hpp>

class GraphScreenView : public GraphScreenViewBase
{
public:
	GraphScreenView();
	virtual ~GraphScreenView() {}
	virtual void setupScreen();
	virtual void tearDownScreen();

	// Schnittstelle System -> GUI
	void updateTemperature(int32_t temp);
	void updateHumidity(uint32_t humid);
	void sensorConnected();
	void sensorDisconnected();

protected:
	// Zähler für die x-Koordinaten der Werte
	uint32_t counter_temp = 0u;
	uint32_t counter_humid = 0u;

	// Pseudo-Konstanten -> werden zu Beginn einmalig berechnen
	int16_t GRAPH_OFFSET_TEXT_ABOVE = 0,
		GRAPH_OFFSET_TEXT_BELOW = 0,
		GRAPH_BORDER_TEXT_HUMID = 0,
		GRAPH_BORDER_TEXT_TEMP = 0,
		GRAPH_TEMP_DELTA = 0,
		GRAPH_HUMID_DELTA = 0;
};

#endif // GRAPHSCREENVIEW_HPP
