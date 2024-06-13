#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
	extern "C"
{
  #include "edt_bsp_uart.h"
  #include "stm32f7xx_hal.h"
  #include <string.h>
  #include <stdio.h>
  #include "edt_bsp_io.h"
  #include "edt_bsp_can.h"
  #include "main.h"
  #include "usbd_cdc_if.h"
 
#include <gui/widget/edt_f7xxh7xx_USARTAPI.h>
#include <gui/widget/edt_f7xxh7xx_TestAPI.h>
  
  extern UART_HandleTypeDef hRs232;
  extern UART_HandleTypeDef hRs485;
  
  extern CAN_HandleTypeDef CanHandle;  // can
   
  extern USARTRevSt  _RS232RevSt;
  extern USARTRevSt  _RS485RevSt;

  // Definitions for STLM75 
#define TEMP 0x00;      // Temperature Register
#define CONF 0x01;      // Configuration Register
#define Thys 0x02;      // Hysteresis Register
#define Tos  0x03;      // Overtemperature Register

#define STLM75ADR 0x90  // A0, A1 and A2 COnnected to VSS
}
#endif

  bool CANHOST;

Model::Model() : modelListener(0), n(0)
{
  #ifndef SIMULATOR
    TestAPI_ThreadInit();
    EDT_GPIO_Mode(GPIO0_GPIO_Port,GPIO0_Pin,GPIO_IN);
    EDT_GPIO_Mode(GPIO1_GPIO_Port,GPIO1_Pin,GPIO_IN);
    EDT_GPIO_Mode(GPIO4_GPIO_Port,GPIO4_Pin,GPIO_OUT);
    EDT_GPIO_Mode(GPIO5_GPIO_Port,GPIO5_Pin,GPIO_OUT);
  #endif  
}
/***************************************************************************************************/

void Model::tick()
{
  tickcount++;
  if (tickcount > 2)
  {
    tickcount=0;       
#ifndef SIMULATOR
    GPIO_0_State = EDT_GPIO_Read(GPIO0_GPIO_Port, GPIO0_Pin);  // read GPIO 0
    if (GPIO_0_State != old_GPIO_0_State)
    {
      old_GPIO_0_State = GPIO_0_State;
      if (GPIO_0_State == 0)
      {
        modelListener->ShowGPIO_0_State();
      }
    } 
    GPIO_1_State = EDT_GPIO_Read(GPIO1_GPIO_Port, GPIO1_Pin);   // Read GPIO 1
    if (GPIO_1_State != old_GPIO_1_State)
    {
      if (GPIO_1_State == 0)
      {
        modelListener->PopUpWindowGPIO1();      
      }
      old_GPIO_1_State = GPIO_1_State;
    }
#endif  
  }
/***************************************************************************************************/
  if (pulsecount <= 100)
  {
    pulsecount++;
    if(pulsecount == 100)
    {    	 
      touchgfx_printf("\rGPIO4 Set HIGH\n\r");		
#ifndef SIMULATOR    
      EDT_GPIO_Write(GPIO4_GPIO_Port,GPIO4_Pin, GPIO_PIN_SET);   // Turn OFF LED on Testboard
#endif
    }
  }
/***************************************************************************************************/  
/***************************************************************************************************/  
// Check if any character are received on RS232
// Characters are received under interrupt control and transferred via: 
// void rs232Rx_task(void *pvParameters) in file edt_F750_USARTAPI.c
//  
// It is up to the user to implement any Protocol to his own Choise  
#ifndef SIMULATOR     
  if(_RS232RevSt.RevF==true)
  {
    _RS232RevSt.RevF=false;
    modelListener->RS232CharReceived(_RS232RevSt.pdata,_RS232RevSt.size); // 
    memset(_RS232RevSt.pdata,0,sizeof(_RS232RevSt.pdata));
    _RS232RevSt.size=0;
  }
  extern uint8_t CRxData[]; 
  if(CanHandleSt.CAN_HandleDataEn == true)
  {
    CanHandleSt.CAN_HandleDataEn = false;
    modelListener->CANReceived(CRxData);
  } 
#endif // SIMULATOR
} // Model::tick()
/***************************************************************************************************/
/***************************************************************************************************/

 
/***************************************************************************************************/
/***************************************************************************************************/
//  CAN Transmite with can2.0-8byte / fdcan-16byte a packet 
/***************************************************************************************************/

void Model::SendCAN(uint8_t value)
{
  if (CANHOST)
  {
    touchgfx_printf("\rCAN Slidervalue to REMOTE =  %d\n\r",value);
  }
  else
  {
    touchgfx_printf("\rCAN Slidervalue to HOST =  %d\n\r",value);
  }
    

#ifndef SIMULATOR
  char TX_Buffer[30];
  sprintf((char *) TX_Buffer,"Val:%d",(int) value);
  n = (uint16_t) strlen (TX_Buffer);
  if (CANHOST)
  {
    EDT_CAN_Transmit(&CanHandle, CANBUS_REMOTEID, (uint8_t *)TX_Buffer, 8);
  }
  else
  {
    EDT_CAN_Transmit(&CanHandle, CANBUS_HOSTID, (uint8_t *)TX_Buffer, 8);    
  }
#endif
}
/***************************************************************************************************/  
/***************************************************************************************************/  
void Model::SendRS232(uint8_t value) 
{
      touchgfx_printf("\rRS232 Slidervalue = %d\n\r", value);

#ifndef SIMULATOR 
  char TX_Buffer[30];
  sprintf((char *) TX_Buffer,"RS232 Slider Position = %d\n\r",(int) value);
  n = (uint16_t) strlen (TX_Buffer);
  touchgfx_printf("\r%s\n\r",TX_Buffer);

  EDT_UART_Transmit_IT(&hRs232, (uint8_t *)TX_Buffer, n);  
#endif
}
/***************************************************************************************************/
/***************************************************************************************************/

void Model::SendRS485(uint8_t value)
{
      touchgfx_printf("\rRS485 Slidervalue = %d\n\r", value);

#ifndef SIMULATOR
  char TX_Buffer[30];
  EDT_LCD_BL_SetPwm(value);
  sprintf((char *) TX_Buffer,"Backlight PWM Value = %d\n\r",(int) value);
  n = (uint16_t) strlen (TX_Buffer);
  EDT_UART_Transmit_IT(&hRs485, (uint8_t *)TX_Buffer, n);  
#endif
}
/***************************************************************************************************/
/***************************************************************************************************/
  
void Model::USBCDCSend(int value)
{
    touchgfx_printf("\rUSBCDC Slidervalue = %d\n\r", value);

#ifndef SIMULATOR
    sprintf((char *) USB_CDC_Tx_Buffer, "USB_CDC_TX: Slider Position = %d\n\r", value);
    n =  (uint16_t) strlen ((char *)USB_CDC_Tx_Buffer);
    CDC_Transmit_FS(USB_CDC_Tx_Buffer, n);
    //HAL_Delay(3);
#endif
}
/***************************************************************************************************/
/***************************************************************************************************/
float Model::ReadTemperatureSensor()
{
  touchgfx_printf("\rReading Temperature Sensor on I2C\n\r");	
#ifndef SIMULATOR

  HAL_I2C_Master_Receive(&I2cHandle,STLM75ADR,Rx_Buffer,2,50); // Get Temperature 

  raw = ((Rx_Buffer[0] << 8)  | Rx_Buffer[1]) >> 7;
  
  if (raw & 0x0100) {
		// Negative temperature
		intTemperature = -10 * (((~(uint8_t)(raw & 0x7E) + 1) & 0x7F) >> 1) - (raw & 0x01) * 5;
	} else {
		// Positive temperature
		intTemperature = ((raw & 0x7E) >> 1) * 10 + (raw & 0x01) * 5;
	}
  Temperature = (double) intTemperature;
  Temperature = Temperature / 10.0; 
/*
  sprintf((char *)Tx_Buffer, "\n\rPool Temperature = %.1f\n\r", Temperature);
  n =  (uint16_t) sizeof (Tx_Buffer);
  HAL_UART_Transmit_IT(&hRs232, Tx_Buffer, n);    // RS232 Non-Blocking
*/
#endif

  modelListener->GetModelTemperature();
  return (Temperature);
}
/***************************************************************************************************/
/***************************************************************************************************/

void Model::SetGPIO4Active()
{
  touchgfx_printf("\rGPIO4 Set LOW\n\r");	
#ifndef SIMULATOR
  EDT_GPIO_Write(GPIO4_GPIO_Port,GPIO4_Pin, GPIO_PIN_RESET);   // Turn ON LED on testboard
#endif
  pulsecount = 0;
}

/***************************************************************************************************/

void Model::SetGPIO5(char value)
{
  GPIO5_Level = value;
  if (GPIO5_Level)
  {
    touchgfx_printf("\rGPIO5 Set HIGH\n\r");		
  }
  else
  {
    touchgfx_printf("\rGPIO5 Set LOW\n\r");		
  }

#ifndef SIMULATOR
  if (GPIO5_Level)
    EDT_GPIO_Write(GPIO5_GPIO_Port,GPIO5_Pin, GPIO_PIN_SET);
  else
    EDT_GPIO_Write(GPIO5_GPIO_Port,GPIO5_Pin, GPIO_PIN_RESET);
#endif
}
/***************************************************************************************************/

