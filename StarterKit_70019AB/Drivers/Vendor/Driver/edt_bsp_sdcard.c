/**
  ******************************************************************************  
  * File Name          : edt_bsp_sdcard.c
  * @author            : EDT Embedded Application Team
  * Description        : This file includes the micro SD card driver mounted on
  *                      smart embedded display board.                       
  * @brief             : EDT <https://smartembeddeddisplay.com/>
  ******************************************************************************
  * @attention
  *
  * COPYRIGHT(c) 2020 Emerging Display Technologies Corp.
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of Emerging Display Technologies Corp. nor the names of 
  *      its contributors may be used to endorse or promote products derived from 
  *      this software without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

SD_HandleTypeDef uSdHandle;
uint8_t SD_state;

static SDSTATUS sdStatus;

/**
  * @brief  Initializes the SD card device.
  * @retval SD status
  */
uint8_t EDT_SD_Init(void)
{
 // GPIO_InitTypeDef GPIO_InitStruct;
  uint8_t sd_state = MSD_OK;

  /* uSD device interface configuration */
  uSdHandle.Instance 		     	 = SDMMCx_INSTANCE;
  uSdHandle.Init.ClockPowerSave      = SDMMC_CLOCK_POWER_SAVE_DISABLE;
  uSdHandle.Init.ClockEdge           = SDMMC_CLOCK_EDGE_RISING;
  uSdHandle.Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
  uSdHandle.Init.BusWide             = SDMMC_BUS_WIDE_4B;
#if (USE_SD_TRANSCEIVER != 0U)
  uSdHandle.Init.TranceiverPresent   = SDMMC_TRANSCEIVER_NOT_PRESENT;
#endif
//  uSdHandle.Init.ClockDiv            = SDMMC_INIT_CLK_DIV;
  uSdHandle.Init.ClockDiv            = 0x20; // 0x20 for 3.215Mbps, 0x14 for 5Mbps

 /* It had been initialized by MX_GPIO_Init();
   SDMMCx_DETECT_GPIO_CLK_ENABLE()   ;
   //Check if the SD card when Initial plugged in the slot
   GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
   GPIO_InitStruct.Pull      = GPIO_PULLUP;
   GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
   GPIO_InitStruct.Pin       = SDMMCx_DETECT_PIN;
   HAL_GPIO_Init(SDMMCx_DETECT_GPIO_PORT, &GPIO_InitStruct);
*/
  
  /* Check if the SD card is plugged in the slot */
  if(EDT_SD_IsDetected() != SD_PRESENT)
  {
    sdStatus.SDCARD_EVENT          = MSDDISK_DISCONNECTION_EVENT;
    SD_state = sdStatus.SDCARD_EVENT;
    EDT_SD_DeInit();
    return MSD_ERROR_SD_NOT_PRESENT;
  }

  /* HAL SD initialization */
  if(HAL_SD_Init(&uSdHandle) != HAL_OK)
  {
    sd_state = MSD_ERROR;
  }

  /* Configure SD Bus width */
  if(sd_state == MSD_OK)
  {
	  /* Enable wide operation */
	  if(HAL_SD_ConfigWideBusOperation(&uSdHandle, SDMMC_BUS_WIDE_4B) != HAL_OK)
	  {
		  sd_state = MSD_ERROR;
	  }
	  /* Switch to High Speed mode if the card support this mode */
	  else if( HAL_SD_ConfigSpeedBusOperation(&uSdHandle, SDMMC_SPEED_MODE_HIGH) != HAL_OK)
	  {
		  sd_state = MSD_ERROR;
	  }
	  else
	  {
		  sd_state = MSD_OK;
	  }
  }

  sdStatus.UseExtiModeDetection  = 0;
  sdStatus.SDCARD_EVENT          = MSDDISK_CONNECTION_EVENT;
  SD_state = sdStatus.SDCARD_EVENT;
  return  sd_state;
}

/**
  * @brief  DeInitializes the SD card device.
  * @retval SD status
  */
uint8_t EDT_SD_DeInit(void)
{
  uint8_t sd_state = MSD_OK;

  uSdHandle.Instance = SDMMCx_INSTANCE;

  /* Set back Mfx pin to INPUT mode in case it was in exti */
  sdStatus.UseExtiModeDetection = 0;

  /* HAL SD deinitialization */
  if(HAL_SD_DeInit(&uSdHandle) != HAL_OK)
  {
    sd_state = MSD_ERROR;
  }

  /* Msp SD deinitialization */
  uSdHandle.Instance = SDMMCx_INSTANCE;

  return  sd_state;
}

/**
  * @brief  Configures Interrupt mode for SD1 detection pin.
  * @retval Returns 0
  */
uint8_t EDT_SD_ITConfig(void)
{
  /* Configure Interrupt mode for SD detection pin */
  /* Note: disabling exti mode can be done calling BSP_SD_DeInit() */
  sdStatus.UseExtiModeDetection = 1;
  return EDT_SD_IsDetected();
}

/**
  * @brief  Configures Interrupt mode for SD1 detection pin.
  * @retval Returns 0
  */
uint8_t EDT_SD_GetSdEvent(void)
{
	return sdStatus.SDCARD_EVENT;
}
/**
 * @brief  Detects if SD card is correctly plugged in the memory slot or not.
 * @retval Returns if SD is detected or not
 */
uint8_t EDT_SD_IsDetected(void)
{
  __IO uint8_t status = SD_PRESENT;
  GPIO_InitTypeDef   GPIO_InitStructure;

  if ( HAL_GPIO_ReadPin( SDMMCx_DETECT_GPIO_PORT, SDMMCx_DETECT_PIN ) == 1 ) {
      status = SD_NOT_PRESENT;
  } 
  else {
      status = SD_PRESENT;
  }

  if ( sdStatus.UseExtiModeDetection ) {
      sdStatus.UseExtiModeDetection=0;
      GPIO_InitStructure.Pin = SDMMCx_DETECT_PIN;
      if ( status == SD_NOT_PRESENT ) {
          GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;
          GPIO_InitStructure.Pull = GPIO_PULLUP;
          
          sdStatus.SDCARD_EVENT = MSDDISK_DISCONNECTION_EVENT;
      }
      else {
          /* Configure PC.13 pin as input floating */
          GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING;
          GPIO_InitStructure.Pull = GPIO_NOPULL;

          sdStatus.SDCARD_EVENT = MSDDISK_CONNECTION_EVENT;
      }
      HAL_GPIO_Init(SDMMCx_DETECT_GPIO_PORT, &GPIO_InitStructure);
      SD_state = sdStatus.SDCARD_EVENT;
      /* Enable and set EXTI SDMMCx_DETECT_IRQn Interrupt to the lowest priority */
      HAL_NVIC_SetPriority(SDMMCx_DETECT_IRQn, SDMMCx_DETECT_IRQ_SetPriority, 0);
      HAL_NVIC_EnableIRQ(SDMMCx_DETECT_IRQn);      
  }
  return status;
}


/**
  * @brief  Reads block(s) from a specified address in an SD card, in polling mode.
  * @param  pData: Pointer to the buffer that will contain the data to transmit
  * @param  ReadAddr: Address from where data is to be read
  * @param  NumOfBlocks: Number of SD blocks to read
  * @param  Timeout: Timeout for read operation
  * @retval SD status
  */
uint8_t EDT_SD_ReadBlocks( uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks, uint32_t Timeout )
{
  if( HAL_SD_ReadBlocks( &uSdHandle, (uint8_t *)pData, ReadAddr, NumOfBlocks, Timeout ) == HAL_OK ) {
    return MSD_OK;
  }
  else {
    return MSD_ERROR;
  }
}

/**
  * @brief  Writes block(s) to a specified address in an SD card, in polling mode.
  * @param  pData: Pointer to the buffer that will contain the data to transmit
  * @param  WriteAddr: Address from where data is to be written
  * @param  NumOfBlocks: Number of SD blocks to write
  * @param  Timeout: Timeout for write operation
  * @retval SD status
  */
uint8_t EDT_SD_WriteBlocks(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks, uint32_t Timeout)
{
  if( HAL_SD_WriteBlocks( &uSdHandle, (uint8_t *)pData, WriteAddr, NumOfBlocks, Timeout ) == HAL_OK ) {
    return MSD_OK;
  }
  else {
    return MSD_ERROR;
  }
}

/**
  * @brief  Reads block(s) from a specified address in an SD card, in DMA mode.
  * @param  pData: Pointer to the buffer that will contain the data to transmit
  * @param  ReadAddr: Address from where data is to be read
  * @param  NumOfBlocks: Number of SD blocks to read
  * @retval SD status
  */
uint8_t EDT_SD_ReadBlocks_DMA(uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks)
{
  if( HAL_SD_ReadBlocks_DMA( &uSdHandle, (uint8_t *)pData, ReadAddr, NumOfBlocks ) == HAL_OK ) {
    return MSD_OK;
  }
  else {
    return MSD_ERROR;
  }
}

/**
  * @brief  Writes block(s) to a specified address in an SD card, in DMA mode.
  * @param  pData: Pointer to the buffer that will contain the data to transmit
  * @param  WriteAddr: Address from where data is to be written
  * @param  NumOfBlocks: Number of SD blocks to write
  * @retval SD status
  */
uint8_t EDT_SD_WriteBlocks_DMA(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks)
{
  if( HAL_SD_WriteBlocks_DMA(&uSdHandle, (uint8_t *)pData, WriteAddr, NumOfBlocks) == HAL_OK ) {
    return MSD_OK;
  }
  else {
    return MSD_ERROR;
  }
}

/**
  * @brief  Erases the specified memory area of the given SD card.
  * @param  StartAddr: Start byte address
  * @param  EndAddr: End byte address
  * @retval SD status
  */
uint8_t EDT_SD_Erase(uint32_t StartAddr, uint32_t EndAddr)
{
  if( HAL_SD_Erase(&uSdHandle, StartAddr, EndAddr) == HAL_OK ) {
    return MSD_OK;
  }
  else {
    return MSD_ERROR;
  }
}

/**
  * @brief  Gets the current SD card data status.
  * @retval Data transfer state.
  *          This value can be one of the following values:
  *            @arg  SD_TRANSFER_OK: No data transfer is acting
  *            @arg  SD_TRANSFER_BUSY: Data transfer is acting
  */
uint8_t EDT_SD_GetCardState(void)
{
  return((HAL_SD_GetCardState(&uSdHandle) == HAL_SD_CARD_TRANSFER ) ? SD_TRANSFER_OK : SD_TRANSFER_BUSY);
}


/**
  * @brief  Get SD information about specific SD card.
  * @param  CardInfo: Pointer to HAL_SD_CardInfoTypedef structure
  * @retval None
  */
void EDT_SD_GetCardInfo(EDT_SD_CardInfo *CardInfo)
{
  HAL_SD_GetCardInfo(&uSdHandle, CardInfo);
}

#if 1
void BSP_SD_AbortCallback(void)
{

}

/**
  * @brief BSP Tx Transfer completed callback
  * @retval None
  * @note empty (up to the user to fill it in or to remove it if useless)
  */
__weak void BSP_SD_WriteCpltCallback(void)
{

}

/**
  * @brief BSP Rx Transfer completed callback
  * @retval None
  * @note empty (up to the user to fill it in or to remove it if useless)
  */
__weak void BSP_SD_ReadCpltCallback(void)
{

}
#else
/**
  * @brief SD Abort callbacks
  * @param hsd: SD handle
  * @retval None
  */
void HAL_SD_AbortCallback(SD_HandleTypeDef *hsd)
{
  EDT_SD_AbortCallback();
}


/**
  * @brief Tx Transfer completed callbacks
  * @param hsd: SD handle
  * @retval None
  */
void HAL_SD_TxCpltCallback(SD_HandleTypeDef *hsd)
{
  EDT_SD_WriteCpltCallback();
}

/**
  * @brief Rx Transfer completed callbacks
  * @param hsd: SD handle
  * @retval None
  */
void HAL_SD_RxCpltCallback(SD_HandleTypeDef *hsd)
{
  EDT_SD_ReadCpltCallback();
}

/**
  * @brief Error callbacks
  * @param hsd: SD handle
  * @retval None
  */
void HAL_SD_ErrorCallback(SD_HandleTypeDef *hsd)
{
  EDT_SD_ErrorCallback();
}
/**
  * @brief SDMMCx_IRQ Handler
  * @retval None
  */
void SDMMCx_IRQHandler(void)
{
     EDT_SDMMCx_IRQHandler();
}
/**
  * @brief SDMMCx_IRQ Handler
  * @retval None
  */
__weak void EDT_SDMMCx_IRQHandler(void)
{
    HAL_SD_IRQHandler(&uSdHandle);
}
/**
  * @brief BSP SD Abort callbacks
  * @retval None
  */
__weak void EDT_SD_AbortCallback(void)
{
}

/**
  * @brief BSP Tx Transfer completed callbacks
  * @retval None
  */
__weak void EDT_SD_WriteCpltCallback(void)
{
}

/**
  * @brief BSP Rx Transfer completed callbacks
  * @retval None
  */
__weak void EDT_SD_ReadCpltCallback(void)
{
}


/**
  * @brief BSP Error callbacks
  * @retval None
  */
__weak void EDT_SD_ErrorCallback(void)
{

}
#endif
//void SDMMCx_DETECT_IRQHandler(void)
//{
//    HAL_GPIO_EXTI_IRQHandler(SDMMCx_DETECT_PIN);
//  if(EDT_SD_ITConfig()==SD_PRESENT) //if sdcard SD_NOT_PRESENT
//    {
//      EDT_SD_Init();
//    }
//    else
//    {
//      EDT_SD_DeInit();
//    }
//}

 /*******(C) COPYRIGHT Emerging Display Technologies Corp. **** END OF FILE ***/

