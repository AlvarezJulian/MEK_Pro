#include <gui/rs232_screen/RS232View.hpp>

  
RS232View::RS232View() : n(0), i(0), j(0)
{  
}

void RS232View::setupScreen()
{
    RS232ViewBase::setupScreen();
#ifndef SIMULATOR
    for(i=0 ; i<512;i++)
    rs232data.RxDataBuffer[i]=0;
    rs232data.RxDataCount=0;
    rs232data.RxDataIndex=0;
#endif    
}

void RS232View::tearDownScreen()
{
    RS232ViewBase::tearDownScreen();  
}

// Fill received data in local buffer
void RS232View::RS232CharReceived(uint8_t *data , uint16_t len)
{
#ifndef SIMULATOR
  for(i=0;i<512;i++)
    rs232data.RxDataBuffer[i]=0;  // Clear Buffer
  
  for(i=0;i<len;i++)
  {
    rs232data.RxDataBuffer[i] = data[i];
  }
  rs232data.RxDataCount=len;
  rs232data.RxDataIndex=0;
  
#endif
}

// Show Received data if any
void RS232View::handleTickEvent()
{
  
  if(rs232data.RxDataCount>rs232data.RxDataIndex)
  {      
    if (n<30)
    {
      RS232RXStringBuffer[n++] = rs232data.RxDataBuffer[rs232data.RxDataIndex++];
      RS232RXString.invalidate();
    }
    else
    {  
      for (i=0;i<30;i++)
      {
        RS232RXStringBuffer[i] = RS232RXStringBuffer[i+1];
      }
      RS232RXStringBuffer[29] = rs232data.RxDataBuffer[rs232data.RxDataIndex++];
      RS232RXString.invalidate();
    }
  } 
}

void RS232View::RS232SliderValueChanged(int value)
{
// Update text field and report to presenter
	Unicode::snprintf(SliderValueBuffer, sizeof(SliderValue), "%d", value);
	SliderValue.invalidate();
	presenter->RS232SliderValueChanged(value);
}
