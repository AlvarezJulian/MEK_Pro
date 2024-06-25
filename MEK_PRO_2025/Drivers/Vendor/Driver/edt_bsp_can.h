/**
  ******************************************************************************  
  * File Name          : edt_bsp_can.h
  * @author            : EDT Embedded Application Team
  * Description        : This file contains the common defines and functions 
  *                      prototypes for the edt_bsp_can.c driver.
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EDT_BSP_CAN_H
#define __EDT_BSP_CAN_H

#ifdef __cplusplus
 extern "C" {
#endif   
   
/* Includes ------------------------------------------------------------------*/
#include "main.h"  
#include "can.h"
#include <stdbool.h>
   
typedef struct{
 bool CAN_HandleDataEn;               //CANBUS Receive IRQ Callback Enable
 uint32_t CAN_HandleDataSize;         //CANBUS Receive IRQ Data length
}CAN_HandleData;

extern	 CAN_HandleTypeDef    CanHandle;
extern CAN_HandleData CanHandleSt;
extern CAN_HandleData CanHandleMsg;
void EDT_CANx_Init(void);
void EDT_CANx_DeInit(void);
HAL_StatusTypeDef EDT_CAN_Transmit(CAN_HandleTypeDef *hcan , uint16_t DeviceID, uint8_t *pdata, uint8_t Size);
HAL_StatusTypeDef EDT_CAN_Receive(CAN_HandleTypeDef *hcan, uint8_t *pdata , uint8_t Size );
void EDT_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
void EDT_CANx_Config(CAN_HandleTypeDef *hcan);
#ifdef __cplusplus
}
#endif

#endif /* __EDT_BSP_CAN_H */

 /*******(C) COPYRIGHT Emerging Display Technologies Corp. **** END OF FILE ***/


