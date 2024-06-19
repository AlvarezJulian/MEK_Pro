/**
  ******************************************************************************  
  * File Name          : edt_bsp_can.c
  * @author            : EDT Embedded Application Team
  * Description        : This file provides a set of firmware functions to CAN 
  *                      communicate with  external devices available on smart 
  *                      embedded display board. 
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
#include "edt_bsp_can.h"
#include <string.h>
#include <stdbool.h>

CAN_HandleTypeDef    CanHandle; /*CANBUS Handle*/
CAN_HandleData       CanHandleSt;

uint8_t              TxData1[8];
uint8_t              RxData1[8];
uint32_t             TxMailbox1;

CAN_TxHeaderTypeDef  TxHeader1;
CAN_RxHeaderTypeDef  RxHeader1;
/*****************************************************************************
  * @brief  Canx bus Initial
  * @param  
  * @retval None
  *BaudRate = APB1 Timer APB1 Peripheral clock / (Prescaler*(CAN_SJW_1TQ+CAN_BS1_2TQ+CAN_BS2_2TQ)
  ex: 125Kb = 54000000/(24*(1+9+8))
  ex: 500Kb = 54000000/(9*(1+5+6))
  ex: 1Mb   = 54000000/(9*(1+2+3))
******************************************************************************/
 void EDT_CANx_Init(void)
{ 
  EDT_CANx_DeInit();
  
  /*##-1- Configure the CAN peripheral */
  CanHandle.Instance = CANx_INSTANCE;
  
  CanHandle.Init.TimeTriggeredMode = DISABLE;
  CanHandle.Init.AutoBusOff = DISABLE;
  CanHandle.Init.AutoWakeUp = DISABLE;
  CanHandle.Init.AutoRetransmission = ENABLE;
  CanHandle.Init.ReceiveFifoLocked = DISABLE;
  CanHandle.Init.TransmitFifoPriority = DISABLE;
  CanHandle.Init.Mode = CAN_MODE_NORMAL;
#if defined (CAN_BAUDRATE1M)
 /*1Mhz BaudRate Bit*/
  CanHandle.Init.SyncJumpWidth  = CAN_SJW_1TQ;
  CanHandle.Init.TimeSeg1  = CAN_BS1_2TQ;//(1~17)
  CanHandle.Init.TimeSeg2  = CAN_BS2_2TQ;//(1~17)
  CanHandle.Init.Prescaler = 10;
#elif defined (CAN_BAUDRATE500K)
  /*500Khz BaudRate Bit*/
  CanHandle.Init.SyncJumpWidth  = CAN_SJW_1TQ;
  CanHandle.Init.TimeSeg1  = CAN_BS1_5TQ;//(1~17)
  CanHandle.Init.TimeSeg2  = CAN_BS2_6TQ;//(1~17)
  CanHandle.Init.Prescaler = 9;
#else
  /*125Khz BaudRate Bit */
  CanHandle.Init.SyncJumpWidth  = CAN_SJW_1TQ;
  CanHandle.Init.TimeSeg1  = CAN_BS1_9TQ;   //(1~16)
  CanHandle.Init.TimeSeg2  = CAN_BS2_8TQ;   //(1~8)
  CanHandle.Init.Prescaler = 24;
#endif

  if ( HAL_CAN_Init ( &CanHandle ) != HAL_OK ) {
    
  }  
  
  /*##-2- Configure the CAN Filter */
  EDT_CANx_Config ( &CanHandle );
}
void EDT_CANx_Config ( CAN_HandleTypeDef *hcan )
{
  CAN_FilterTypeDef sFilterConfig = {0};
  if ( CANx_INSTANCE == CAN2 ) {
      sFilterConfig.FilterBank = 14;  //FilterNumber 14 for CAN2  
      sFilterConfig.SlaveStartFilterBank = 14;
  } 
  else {
      sFilterConfig.FilterBank = 0;  //FilterNumber 0 for CAN1  
  }
  sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
  sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
  sFilterConfig.FilterIdHigh = 0x0000;
  sFilterConfig.FilterIdLow = 0x0000;  
  sFilterConfig.FilterMaskIdHigh = 0x0000;
  sFilterConfig.FilterMaskIdLow = 0x0000;    
  sFilterConfig.FilterFIFOAssignment = 0;
  sFilterConfig.FilterActivation = ENABLE;

  if ( HAL_CAN_ConfigFilter ( hcan, &sFilterConfig ) != HAL_OK) {
    }
  
  if ( HAL_CAN_Start ( hcan ) != HAL_OK) {
    }
  
  if ( HAL_CAN_ActivateNotification ( hcan, CAN_IT_RX_FIFO0_MSG_PENDING ) \
    != HAL_OK) {
  }
  
  TxHeader1.StdId = CANBUS_HOSTID;
  TxHeader1.ExtId = CANBUS_HOSTID;
  TxHeader1.RTR = CAN_RTR_DATA;
  TxHeader1.IDE = CAN_ID_STD;
  TxHeader1.DLC = 8;
  TxHeader1.TransmitGlobalTime = DISABLE;
  
  CanHandleSt.CAN_HandleDataEn = false;
  CanHandleSt.CAN_HandleDataSize = 0;
}
/*****************************************************************************
  * @brief  Can bus 2 De-Initial
  * @param  
  * @retval None
******************************************************************************/
void EDT_CANx_DeInit( void )
{   
  if ( HAL_CAN_DeInit ( &CanHandle ) != HAL_OK ) {
    /* Initialization Error */
    }
}
/*****************************************************************************
  * @brief CAN MX USER USED Can Bus Tramsmite 
  *        This function frees the hardware resources used in this example:
  * @param hcan     : CAN handle pointer
  *        DeviceID : Remote Device ID
  *        pdata    : CAN Tramsmite Data pointer
  *        Size     : CAN Tramsmite Data Length Max:8
  *        Timeout  : CAN Tramsmite wait time out
  * @retval HAL_StatusTypeDef
******************************************************************************/  
HAL_StatusTypeDef EDT_CAN_Transmit ( CAN_HandleTypeDef *hcan , uint16_t DeviceID, \
      uint8_t *pdata , uint8_t Size )
{   
  HAL_StatusTypeDef  Status  =  HAL_ERROR;   

  if ( Size > 8 ) return Status;

  TxHeader1.StdId = DeviceID;
  TxHeader1.ExtId = CANBUS_HOSTID;
  TxHeader1.RTR = CAN_RTR_DATA;
  TxHeader1.IDE = CAN_ID_STD;
  TxHeader1.DLC = Size;
  TxHeader1.TransmitGlobalTime = ENABLE;

  memset ( TxData1, 0, sizeof ( TxData1 ));
  memcpy ( TxData1, pdata, Size );

  if ( HAL_CAN_AddTxMessage ( hcan, &TxHeader1, TxData1, &TxMailbox1 ) != HAL_OK ) {

  }
  return Status;
}
/*****************************************************************************
  * @brief CAN MX USER USED Can Bus Receive Function
  *        This function frees the hardware resources used in this example:
  * @param hcan    : CAN handle pointer
  *        pdata   : CAN Receive Data pointer
  *        Size    : CAN Receive Data Length Max:8
  *        Timeout : CAN Receive wait time out
  * @retval HAL_StatusTypeDef
******************************************************************************/
HAL_StatusTypeDef EDT_CAN_Receive ( CAN_HandleTypeDef *hcan, uint8_t *pdata , uint8_t Size )
{   
   HAL_StatusTypeDef  Status  =  HAL_ERROR;   
   if ( Size >8 ) return Status;
   
   if ( ( CanHandleSt.CAN_HandleDataEn ) && ( CanHandleSt.CAN_HandleDataSize <= 8 ) ) {
     CanHandleSt.CAN_HandleDataEn = false;
     CanHandleSt.CAN_HandleDataSize = 0;
     memcpy ( pdata, RxData1, Size );
     Status = HAL_OK;
   } 
   else {
     memset ( pdata, 0, Size );
   }
   return  Status;
}
/*****************************************************************************
  *  * @brief CAN MX USER USED Can Bus Setting BaudRate Function
  *        This function frees the hardware resources used in this example:
  * @param hcan    : CAN handle pointer
  *        BaudRate   : 1M/500K/125M
  * @retval HAL_StatusTypeDef
******************************************************************************/
void EDT_CANx_Baud ( uint16_t BaudRate )
{
  CanHandle.Instance = CANx_INSTANCE;
  
  CanHandle.Init.TimeTriggeredMode = DISABLE;
  CanHandle.Init.AutoBusOff = DISABLE;
  CanHandle.Init.AutoWakeUp = DISABLE;
  CanHandle.Init.AutoRetransmission = ENABLE;
  CanHandle.Init.ReceiveFifoLocked = DISABLE;
  CanHandle.Init.TransmitFifoPriority = DISABLE;
  CanHandle.Init.Mode = CAN_MODE_NORMAL;
  
  switch ( BaudRate ) {
  case 1000:
   /*1Mhz BaudRate Bit*/
    CanHandle.Init.SyncJumpWidth  = CAN_SJW_1TQ;
    CanHandle.Init.TimeSeg1  = CAN_BS1_2TQ;//(1~17)
    CanHandle.Init.TimeSeg2  = CAN_BS2_2TQ;//(1~17)
    CanHandle.Init.Prescaler = 10;
   break;
  case 500:
    CanHandle.Init.SyncJumpWidth  = CAN_SJW_1TQ;
    CanHandle.Init.TimeSeg1  = CAN_BS1_5TQ;//(1~17)
    CanHandle.Init.TimeSeg2  = CAN_BS2_6TQ;//(1~17)
    CanHandle.Init.Prescaler = 9;
    break;
    
  case 125:
   default:
    /*125Khz BaudRate Bit */
    CanHandle.Init.SyncJumpWidth  = CAN_SJW_1TQ;
    CanHandle.Init.TimeSeg1  = CAN_BS1_9TQ;   //(1~16)
    CanHandle.Init.TimeSeg2  = CAN_BS2_8TQ;   //(1~8)
    CanHandle.Init.Prescaler = 24;
    break;
  }
  
  if ( HAL_CAN_Init ( &CanHandle ) != HAL_OK ) {   
    }  
}
/*****************************************************************************
  * @brief CAN MX USER USED Can Bus HAL_CAN_RxFifo0MsgPendingCallback
  *        This function frees the hardware resources used in this example:
  * @param hcan    : CAN handle pointer
  * @retval HAL_StatusTypeDef
******************************************************************************/
void HAL_CAN_RxFifo0MsgPendingCallback ( CAN_HandleTypeDef *hcan )
{
//   EDT_CAN_RxFifo0MsgPendingCallback ( hcan );
   CAN_Receive(hcan);
}
/*****************************************************************************
  * @brief CAN MX USER USED Can Bus EDT_CAN_RxFifo0MsgPendingCallback
  *        This function frees the hardware resources used in this example:
  * @param hcan    : CAN handle pointer
  * @retval HAL_StatusTypeDef
******************************************************************************/
__weak void EDT_CAN_RxFifo0MsgPendingCallback ( CAN_HandleTypeDef *hcan )
{
  /* Get RX message */
  if ( HAL_CAN_GetRxMessage ( hcan, CAN_RX_FIFO0, &RxHeader1, RxData1 ) != HAL_OK ) {

  }
  /* Process Struct from CAN Bus */
  if ( ( RxHeader1.StdId == CANBUS_HOSTID ) && ( RxHeader1.IDE == CAN_ID_STD ) && \
        ( RxHeader1.DLC > 0 ) ) {
    CanHandleSt.CAN_HandleDataEn = true;
    CanHandleSt.CAN_HandleDataSize = RxHeader1.DLC;
  }
}
/*****************************************************************************
 CAN Bus Tramsmite IRQ Handler
*****************************************************************************/
//void CANx_2_TX_IRQHandler ( void )
void CAN2_TX_IRQHandler ( void )
{
   HAL_CAN_IRQHandler ( &CanHandle );
}
/*****************************************************************************
 CAN Bus Receive IRQ Handler
*****************************************************************************/
//void CANx_2_RX_IRQHandler ( void )
void CAN2_RX0_IRQHandler ( void )
{
   HAL_CAN_IRQHandler ( &CanHandle );
}
/*****************************************************************************
USED BYTE CAN Bus Transmite Finlish Irq CallBack 
*****************************************************************************/
void HAL_CAN_TxCpltCallback ( CAN_HandleTypeDef *CanHandle )
{
  /* USER CODE Transmite finlish interrupt by CAN_HandleTypeDef *CanHandle*/    
}
 /*******(C) COPYRIGHT Emerging Display Technologies Corp. **** END OF FILE ***/

