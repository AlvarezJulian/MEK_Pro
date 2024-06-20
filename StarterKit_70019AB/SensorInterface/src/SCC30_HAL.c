/*
 * SCC30_HAL.c
 *
 *  Created on: 15.10.2020
 *      Author: Rausch_Luca
 */

#include "SCC30_HAL.h"
#include "stm32f7xx_hal.h"

#include "FreeRTOS.h"
#include "task.h"

//#defines ergänzt die vorher in der se21070_msp.h stand
/**********************************************************/
//        CTP(I2C_1)  & EXT  I2C(I2C_2)  INTERFACE
/**********************************************************/
    /**I2C1 GPIO Configuration for CTP
    PB8     ------> I2C1_SCL
    PB7     ------> I2C1_SDA
    PG7     ------> I2C1_INT
    PG6     ------> I2C1_RESET
    */
#define CTP_I2C_Instance                I2C1
/*
//I2C TIMING Register define when I2C clock source is PCLK1 54MHz
// I2C TIMING is calculated from APB1 source clock = 54 MHz
// Due to the big MOFSET capacity for adapting the camera level the rising time is very large (>1us)
// Enabled Analog Filter Delay
// Timing Setting Follow STM I2C_Timing_Configuration AN4235
*/
/*I2C Speed Mode Standard Mode*/
#define CTP_I2C_TIMING     ((uint32_t)0x1070699E)  //  100KHz
/*I2C Speed Mode Fast Mode */
//#define CTP_I2C_TIMING     ((uint32_t)0x102028DF)  //  100KHz
//#define CTP_I2C_TIMING     ((uint32_t)0x00501EE4)  //  200KHz
//#define CTP_I2C_TIMING     ((uint32_t)0x00501D5E)  //  400KHz

#define CTP_I2C_FORCE_RESET()           __HAL_RCC_I2C1_FORCE_RESET()
#define CTP_I2C_RELEASE_RESET()         __HAL_RCC_I2C1_RELEASE_RESET()

#define RCC_PERIPHCLK_CTP               RCC_PERIPHCLK_I2C1
#define RCC_CTP_CLKSOURCE_SYSCLK        RCC_I2C1CLKSOURCE_PCLK1
#define CTP_CLK_ENABLE()                __HAL_RCC_I2C1_CLK_ENABLE()
#define CTP_CLK_DISABLE()               __HAL_RCC_I2C1_CLK_DISABLE()

#define CTP_SCL_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()
#define CTP_SDA_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()
#define CTP_RESET_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOG_CLK_ENABLE()
#define CTP_INT_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOG_CLK_ENABLE()

#define CTP_SCL_PIN                     GPIO_PIN_8
#define CTP_SCL_GPIO_PORT               GPIOB
#define CTP_SCL_GPIO_AF                 GPIO_AF4_I2C1

#define CTP_SDA_PIN                     GPIO_PIN_7
#define CTP_SDA_GPIO_PORT               GPIOB
#define CTP_SDA_GPIO_AF                 GPIO_AF4_I2C1

#define CTP_INT_PIN                     GPIO_PIN_7
#define CTP_INT_GPIO_PORT               GPIOG

#define CTP_RESET_PIN                   GPIO_PIN_6
#define CTP_RESET_GPIO_PORT             GPIOG

/* CTP_I2C interrupt requests */
#define CTP_I2C_EV_IRQn                 I2C1_EV_IRQn
#define CTP_I2C_ER_IRQn                 I2C1_ER_IRQn
#define CTP_IRQ_SetPriority             0x0F
/*******************external I2c interafce***************************************/
    /**I2C2 GPIO Configuration for external I2C
    PH4     ------> I2C2_SCL
    PB11    ------> I2C2_SDA
    PE2     ------> I2C2_INT
    PG2     ------> I2C2_RESET
    */
#define I2Cx_INSTANCE                   I2C2
/*
//I2C TIMING Register define when I2C clock source is PCLK1 54MHz
// I2C TIMING is calculated from APB1 source clock = 54 MHz
// Due to the big MOFSET capacity for adapting the camera level the rising time is very large (>1us)
// Enabled Analog Filter Delay
// Timing Setting Follow STM I2C_Timing_Configuration AN4235
*/
/*I2C Speed Mode Standard Mode*/
//#define I2Cx_TIMING                      ((uint32_t)0x1070699E)
/*I2C Speed Mode Fast Mode */
#define I2Cx_TIMING                      ((uint32_t)0x102028DF)
//#define I2Cx_TIMING                      ((uint32_t)0x00501EE4)
//#define I2Cx_TIMING                      ((uint32_t)0x00501D5E)

#define I2Cx_FORCE_RESET()              __HAL_RCC_I2C2_FORCE_RESET()
#define I2Cx_RELEASE_RESET()            __HAL_RCC_I2C2_RELEASE_RESET()

#define RCC_PERIPHCLK_I2Cx              RCC_PERIPHCLK_I2C2
#define RCC_I2CxCLKSOURCE_SYSCLK        RCC_I2C2CLKSOURCE_PCLK1
#define I2Cx_CLK_ENABLE()               __HAL_RCC_I2C2_CLK_ENABLE()
#define I2Cx_CLK_DISABLE()              __HAL_RCC_I2C2_CLK_DISABLE()

#define I2Cx_SCL_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOH_CLK_ENABLE()
#define I2Cx_SDA_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()
#define I2Cx_INT_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOE_CLK_ENABLE()
#define I2Cx_RST_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOG_CLK_ENABLE()

/* Definition for I2Cx Pins */
#define I2Cx_SCL_PIN                    GPIO_PIN_4
#define I2Cx_SCL_GPIO_PORT              GPIOH
#define I2Cx_SCL_GPIO_AF                GPIO_AF4_I2C2

#define I2Cx_SDA_PIN                    GPIO_PIN_11
#define I2Cx_SDA_GPIO_PORT              GPIOB
#define I2Cx_SDA_GPIO_AF                GPIO_AF4_I2C2

#define I2Cx_INT_PIN                    GPIO_PIN_2
#define I2Cx_INT_GPIO_PORT              GPIOE

#define I2Cx_RST_PIN                    GPIO_PIN_2
#define I2Cx_RST_GPIO_PORT              GPIOG
/* I2C interrupt requests */

#define I2Cx_EV_IRQn                    I2C2_EV_IRQn
#define I2Cx_ER_IRQn                    I2C2_ER_IRQn
#define I2Cx_EV_IRQHandler              I2C2_EV_IRQHandler
#define I2Cx_ER_IRQHandler              I2C2_ER_IRQHandler
#define I2Cx_IRQ_SetPriority            0x0F
/**********************************************************/

// Standard Timeout bei der I2C-Kommunikation in ms
#define SCC30_STD_TIMEOUT	50u

// Handle für die I2C- (und ggf. CRC-) Instanz
static I2C_HandleTypeDef i2c_handle;

#ifdef SCC30_ENABLE_CRC
static CRC_HandleTypeDef crc_handle;
#endif

// --------------------------------------------------------

uint8_t SCC30_initI2C(){
	uint8_t result = HAL_OK;
	GPIO_InitTypeDef gpio_init;

	// 1. Clock Freischalten
	I2Cx_CLK_ENABLE();
	I2Cx_SDA_GPIO_CLK_ENABLE();
	I2Cx_SCL_GPIO_CLK_ENABLE();

	// 2. GPIOs Konfigurieren
	// SDA
	gpio_init.Pin = I2Cx_SDA_PIN;
	gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
	gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_init.Pull = GPIO_NOPULL;
	//gpio_init.Alternate = I2Cx_SDA_GPIO_AF;
	HAL_GPIO_Init(I2Cx_SDA_GPIO_PORT, &gpio_init);
	// SCL
	gpio_init.Pin = I2Cx_SCL_PIN;
	//gpio_init.Alternate = I2Cx_SCL_GPIO_AF;
	HAL_GPIO_Init(I2Cx_SCL_GPIO_PORT, &gpio_init);

	// 3. I2C-Interface des Sensors zurücksetzen -> manuell den SCL Pin 9x toggeln
	HAL_GPIO_WritePin(I2Cx_SDA_GPIO_PORT, I2Cx_SDA_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(I2Cx_SCL_GPIO_PORT, I2Cx_SCL_PIN, GPIO_PIN_SET);
	for(uint32_t i = 0; i < 18; i++){
		HAL_GPIO_TogglePin(I2Cx_SCL_GPIO_PORT, I2Cx_SCL_PIN);
		SCC30_delayMs(1);
	}
	// Pins für das Peripherie-Modul freigeben
	HAL_GPIO_DeInit(I2Cx_SCL_GPIO_PORT, I2Cx_SCL_PIN);
	HAL_GPIO_DeInit(I2Cx_SDA_GPIO_PORT, I2Cx_SDA_PIN);
	gpio_init.Alternate = I2Cx_SCL_GPIO_AF;
	HAL_GPIO_Init(I2Cx_SCL_GPIO_PORT, &gpio_init);
	gpio_init.Pin = I2Cx_SDA_PIN;
	gpio_init.Alternate = I2Cx_SDA_GPIO_AF;
	HAL_GPIO_Init(I2Cx_SDA_GPIO_PORT, &gpio_init);


	// 4. I2C Konfigurieren
	i2c_handle.Instance = I2Cx_INSTANCE;
	i2c_handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	i2c_handle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	i2c_handle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	i2c_handle.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	i2c_handle.Init.Timing = 0x1060EFFF;	// 50 kHz
	result = HAL_I2C_Init(&i2c_handle);
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_sendI2C(uint8_t* data, uint32_t size){
	uint8_t result = HAL_OK;
	result = HAL_I2C_Master_Transmit(&i2c_handle, SCC30_I2C_ADDR, data, size, SCC30_STD_TIMEOUT);
	if(result != HAL_OK){
		result = HAL_I2C_GetError(&i2c_handle);
		if((result & HAL_I2C_ERROR_TIMEOUT) != 0u){
			HAL_I2C_DeInit(&i2c_handle);
			SCC30_initI2C();
		}
	}
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_readI2C(uint8_t* buffer, uint32_t size){
	uint8_t result = HAL_OK;
	result = HAL_I2C_Master_Receive(&i2c_handle, SCC30_I2C_ADDR, buffer, size, SCC30_STD_TIMEOUT);
	if(result != HAL_OK){
		result = HAL_I2C_GetError(&i2c_handle);
		if((result & HAL_I2C_ERROR_TIMEOUT) != 0u){
			HAL_I2C_DeInit(&i2c_handle);
			SCC30_initI2C();
		}
	}
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_sendCommandAndReadI2C(uint16_t command, uint8_t* buffer, uint32_t size){
	uint8_t result = HAL_OK;
	/* Die Mem_Read-API liefert genau das gewünschte Verhalten,
	   dass nach dem Schreiben ohne eine Stopp-Bedingung gelesen werden kann.*/
	result = HAL_I2C_Mem_Read(&i2c_handle, SCC30_I2C_ADDR, command, I2C_MEMADD_SIZE_16BIT, buffer, size, SCC30_STD_TIMEOUT);
	if(result != HAL_OK){
		result = HAL_I2C_GetError(&i2c_handle);
		if((result & HAL_I2C_ERROR_TIMEOUT) != 0u){
			HAL_I2C_DeInit(&i2c_handle);
			SCC30_initI2C();
		}
	}
	return result;
}

// --------------------------------------------------------

void SCC30_delayMs(uint32_t delay_ms){
	// OS-Delay Funktion aufrufen
	vTaskDelay(pdMS_TO_TICKS(delay_ms));
}

// --------------------------------------------------------

#ifdef SCC30_ENABLE_CRC

// --------------------------------------------------------

uint8_t SCC30_initCRC8(){
	uint8_t result = HAL_OK;
	// Clock freischalten
	__HAL_RCC_CRC_CLK_ENABLE();
	// Modul initialisieren
	crc_handle.Instance = (CRC_TypeDef*)CRC_BASE;
	crc_handle.Init.DefaultPolynomialUse = DEFAULT_POLYNOMIAL_DISABLE;
	crc_handle.Init.DefaultInitValueUse = DEFAULT_INIT_VALUE_DISABLE;
	crc_handle.Init.CRCLength = CRC_POLYLENGTH_8B;
	crc_handle.Init.GeneratingPolynomial = SCC30_CRC_POLYNOMIAL;
	crc_handle.Init.InitValue = SCC30_CRC_INIT_VAL;
	crc_handle.Init.InputDataInversionMode = CRC_INPUTDATA_INVERSION_NONE;
	crc_handle.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_DISABLE;
	crc_handle.InputDataFormat = CRC_INPUTDATA_FORMAT_HALFWORDS;  // Eingabeformat sind 16-Bit Werte
	result = HAL_CRC_Init(&crc_handle);
	return result;
}

// --------------------------------------------------------

uint8_t SCC30_calcCRC8(uint16_t data){
	uint8_t crc8 = 0;
	/* Auch wenn das 2. Argument einen 32-Bit Integer Zeiger erwartet
	   müssen die Daten als 16-Bit Integer Zeiger übergeben werden,
	   da das Modul entsprechend konfiguriert wurde */
	crc8 = HAL_CRC_Calculate(&crc_handle, (uint32_t*)&data, 1u);
	return crc8;
}

// --------------------------------------------------------

#endif

