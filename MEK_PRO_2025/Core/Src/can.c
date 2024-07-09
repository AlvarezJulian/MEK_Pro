/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    can.c
 * @brief   This file provides code for the configuration
 *          of the CAN instances.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "can.h"

/* USER CODE BEGIN 0 */
uint8_t TxData[CAN_SIZE];
uint8_t RxData[CAN_SIZE];
uint32_t TxMailbox;
CAN_TxHeaderTypeDef TxHeader;
CAN_RxHeaderTypeDef RxHeader;
CAN_HandleTypeDef hcan2;
CAN_HandleData CanHandleMsg;
CANBUS_RX_ID msgType;
CANBUS_TX_ID ID_btnPressed;
/* USER CODE END 0 */

CAN_HandleTypeDef hcan2;

/* CAN2 init function */
void MX_CAN2_Init(void) {

	/* USER CODE BEGIN CAN2_Init 0 */

	/* USER CODE END CAN2_Init 0 */

	/* USER CODE BEGIN CAN2_Init 1 */

	/* USER CODE END CAN2_Init 1 */
	hcan2.Instance =
	CAN2;
	hcan2.Init.Prescaler = 24;
	hcan2.Init.Mode =
	CAN_MODE_NORMAL;
	hcan2.Init.SyncJumpWidth =
	CAN_SJW_1TQ;
	hcan2.Init.TimeSeg1 =
	CAN_BS1_9TQ;
	hcan2.Init.TimeSeg2 =
	CAN_BS2_8TQ;
	hcan2.Init.TimeTriggeredMode = DISABLE;
	hcan2.Init.AutoBusOff = DISABLE;
	hcan2.Init.AutoWakeUp = DISABLE;
	hcan2.Init.AutoRetransmission = ENABLE;
	hcan2.Init.ReceiveFifoLocked = DISABLE;
	hcan2.Init.TransmitFifoPriority = DISABLE;
	if (HAL_CAN_Init(&hcan2) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN CAN2_Init 2 */

	/* USER CODE END CAN2_Init 2 */

}

void HAL_CAN_MspInit(CAN_HandleTypeDef *canHandle) {

	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	if (canHandle->Instance == CAN2) {
		/* USER CODE BEGIN CAN2_MspInit 0 */

		/* USER CODE END CAN2_MspInit 0 */
		/* CAN2 clock enable */
		__HAL_RCC_CAN2_CLK_ENABLE();
		__HAL_RCC_CAN1_CLK_ENABLE();

		__HAL_RCC_GPIOB_CLK_ENABLE();
		/**CAN2 GPIO Configuration
		 PB13     ------> CAN2_TX
		 PB12     ------> CAN2_RX
		 */
		GPIO_InitStruct.Pin =
		GPIO_PIN_13 | GPIO_PIN_12;
		GPIO_InitStruct.Mode =
		GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull =
		GPIO_NOPULL;
		GPIO_InitStruct.Speed =
		GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate =
		GPIO_AF9_CAN2;
		HAL_GPIO_Init(
		GPIOB, &GPIO_InitStruct);

		/* CAN2 interrupt Init */
		HAL_NVIC_SetPriority(CAN2_TX_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(CAN2_TX_IRQn);
		HAL_NVIC_SetPriority(CAN2_RX0_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(CAN2_RX0_IRQn);
		HAL_NVIC_SetPriority(CAN2_RX1_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(CAN2_RX1_IRQn);
		/* USER CODE BEGIN CAN2_MspInit 1 */

		/* USER CODE END CAN2_MspInit 1 */
	}
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef *canHandle) {

	if (canHandle->Instance == CAN2) {
		/* USER CODE BEGIN CAN2_MspDeInit 0 */

		/* USER CODE END CAN2_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_CAN2_CLK_DISABLE();
		__HAL_RCC_CAN1_CLK_DISABLE();

		/**CAN2 GPIO Configuration
		 PB13     ------> CAN2_TX
		 PB12     ------> CAN2_RX
		 */
		HAL_GPIO_DeInit(
		GPIOB,
		GPIO_PIN_13 | GPIO_PIN_12);

		/* CAN2 interrupt Deinit */
		HAL_NVIC_DisableIRQ(CAN2_TX_IRQn);
		HAL_NVIC_DisableIRQ(CAN2_RX0_IRQn);
		HAL_NVIC_DisableIRQ(CAN2_RX1_IRQn);
		/* USER CODE BEGIN CAN2_MspDeInit 1 */

		/* USER CODE END CAN2_MspDeInit 1 */
	}
}

/* USER CODE BEGIN 1 */

void CAN_Send(CANBUS_TX_ID CAN_ID, uint8_t dlc, uint8_t *Pdata) {

	if ((CAN_ID >= CANBUS_TX_START) && (CAN_ID < CANBUS_TX_MAX)) {
		TxHeader.StdId = CAN_ID;
	}
//	TxHeader.ExtId = CAN_ID;
	TxHeader.RTR =
	CAN_RTR_DATA;
	TxHeader.IDE =
	CAN_ID_STD;
	if (dlc > 0) {
		TxHeader.DLC = dlc;
	}
	TxHeader.TransmitGlobalTime = ENABLE;

	/*
	 char TX_Buffer[30];
	 sprintf((char*) TX_Buffer, "Val:%d", (int) value);
	 memset(TxData, 0, sizeof(TxData));
	 memcpy(TxData, TX_Buffer, 8);
	 */

	for (int i = 0; i < dlc; ++i) {
		TxData[i] = Pdata[i];
	}
	HAL_CAN_AddTxMessage(&hcan2, &TxHeader, TxData, &TxMailbox);
}

void CAN_Receive(CAN_HandleTypeDef *hcan) {

	if (HAL_CAN_GetRxMessage(&hcan2, CAN_RX_FIFO0, &RxHeader, RxData) == HAL_OK) {

		if ((RxHeader.StdId >= CANBUS_RX_USER_ID) && (RxHeader.StdId < CANBUS_RX_MAX)
				&& RxHeader.DLC > 0) {

			CanHandleMsg.CAN_HandleDataEn = true;
			CanHandleMsg.CAN_HandleDataSize = RxHeader.DLC;
			msgType = RxHeader.StdId;
		}
	}
}

/* USER CODE END 1 */
