#include <gui/graphscreen_screen/GraphScreenView.hpp>

#define GRAPH_TEXT_SPACING	40

GraphScreenView::GraphScreenView()
{
	// Berechnen der Konstanten
	GRAPH_OFFSET_TEXT_ABOVE = graph_temperature.getY() + graph_temperature.getHeight() - 42;
	GRAPH_OFFSET_TEXT_BELOW = graph_temperature.getY() + graph_temperature.getHeight() - 2;
	GRAPH_BORDER_TEXT_TEMP = graph_temperature.getX() + graph_temperature.getWidth() - textArea_TempVal.getWidth();
	GRAPH_BORDER_TEXT_HUMID = graph_temperature.getX() + graph_temperature.getWidth() - textArea_HumidVal.getWidth();
	GRAPH_TEMP_DELTA = graph_temperature.getGraphRangeYMaxAsInt() - graph_temperature.getGraphRangeYMinAsInt();
	GRAPH_HUMID_DELTA = graph_humidity.getGraphRangeYMaxAsInt() - graph_humidity.getGraphRangeYMinAsInt();
}

void GraphScreenView::setupScreen()
{
	GraphScreenViewBase::setupScreen();

	// Farben der Textfelder an die Graphen anpassen
	textArea_TempVal.setColor(graph_temperatureLine1Painter.getColor());
	textArea_HumidVal.setColor(graph_humidityLine1Painter.getColor());
}

void GraphScreenView::tearDownScreen()
{
	GraphScreenViewBase::tearDownScreen();
}

void GraphScreenView::updateTemperature(int32_t temp)
{
	// Wert dem Graphen hinzuf�gen
	graph_temperature.addDataPoint((int)temp);
	// Textfeld ausblenden um visuelle Artefakte zu vermeiden
	textArea_TempVal.setVisible(false);
	textArea_TempVal.invalidate();
	// Wert in das Textfeld schreiben -> Die letzte Dezimalstelle des Wertes entspricht dem Nachkommaanteil
	Unicode::snprintf(textArea_TempValBuffer, TEXTAREA_TEMPVAL_SIZE, "%d.%d", temp / 10, temp % 10);
	// Koordinaten des Textfeldes berechnen
	textArea_TempVal.setX(graph_temperature.getX() + 2 * counter_temp);			// X-Koordinate -> 2 * dem Counter Wert, da der Graph nur X-Aufl�sung / 2 Werte enth�lt
	if (textArea_TempVal.getX() > GRAPH_BORDER_TEXT_TEMP) {
		textArea_TempVal.setX(GRAPH_BORDER_TEXT_TEMP);
	}
	temp = temp - graph_temperature.getGraphRangeYMinAsInt();		// Um den Werte-Offset verschieben
	temp = temp * graph_temperature.getHeight() / GRAPH_TEMP_DELTA;		// Wert auf die Gr��e des Graphen skalieren
	textArea_TempVal.setY(GRAPH_OFFSET_TEXT_ABOVE - temp);	// Neue Koordinate -> Offset - Skalierter Wert
	textArea_TempVal.setVisible(true);
	textArea_TempVal.invalidate();
	counter_temp++;
	if (counter_temp == (uint16_t)graph_temperature.getGraphRangeXMax()) {
		// Ende des Graphen erreicht -> zur�cksetzen
		counter_temp = 0;
		graph_temperature.clear();
		graph_temperature.invalidate();
	}
}

void GraphScreenView::updateHumidity(uint32_t humid)
{
	int32_t delta_y = 0;
	// Wert dem Graphen hinzuf�gen
	graph_humidity.addDataPoint((int)humid);
	// Textfeld ausblenden um visuelle Artefakte zu vermeiden
	textArea_HumidVal.setVisible(false);
	textArea_HumidVal.invalidate();
	// Wert in das Textfeld schreiben
	Unicode::snprintf(textArea_HumidValBuffer, TEXTAREA_HUMIDVAL_SIZE, "%d", humid);
	// Koordinaten des Textfeldes berechnen
	textArea_HumidVal.setX(graph_humidity.getX() + 2 * counter_humid);			// X-Koordinate -> 2 * dem Counter Wert, da der Graph nur X-Aufl�sung / 2 Werte enth�lt
	if (textArea_HumidVal.getX() > GRAPH_BORDER_TEXT_HUMID) {
		textArea_HumidVal.setX(GRAPH_BORDER_TEXT_HUMID);
	}
	humid = humid - graph_humidity.getGraphRangeYMinAsInt();					// Um den Werte-Offset verschieben
	humid = humid * graph_humidity.getHeight() / GRAPH_HUMID_DELTA;	// Wert auf die Gr��e des Graphen skalieren
	textArea_HumidVal.setY(GRAPH_OFFSET_TEXT_ABOVE - humid);	// Neue Koordinate -> Offset - Skalierter Wert
	// Platz zum Text der Temperatur �berpr�fen und ggf. anpassen, damit sie sich nicht �berlappen
	delta_y = textArea_TempVal.getY() - textArea_HumidVal.getY();
	if (delta_y > 0) {   // positive Differenz -> Temp. niedriger als Luftf. -> Luftf. Text nach oben verschieben
		textArea_TempVal.setY(textArea_TempVal.getY() + GRAPH_TEXT_SPACING);
	}
	else {
		textArea_HumidVal.setY(GRAPH_OFFSET_TEXT_BELOW - humid);
	}
	textArea_HumidVal.setVisible(true);
	textArea_HumidVal.invalidate();
	counter_humid++;
	if (counter_humid == (uint16_t)graph_humidity.getGraphRangeXMax()) {
		// Ende des Graphen erreicht -> zur�cksetzen
		counter_humid = 0;
		graph_humidity.clear();
		graph_humidity.invalidate();
	}
}
