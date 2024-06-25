/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    can.h
 * @brief   This file contains all the function prototypes for
 *          the can.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CAN_H__
#define __CAN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern CAN_HandleTypeDef hcan2;

/* USER CODE BEGIN Private defines */
#define CANBUS_DSPL_HIGHPRIO_TX_START	0x220 // 0x220 - 0x22F = 16  IDs
#define CANBUS_DSPL_LOWPRIO_TX_START	0x340 // 0x340 - 0x43F = 256 IDs

#define CANBUS_DSPL_HIGHPRIO_RX_START	0x230 // 0x230 - 0x23F = 16  IDs
#define CANBUS_DSPL_LOWPRIO_RX_START	0x440 // 0x440 - 0x53F = 256 IDs

typedef enum {
	// ID2 mit Prio Hoch
	CANBUS_TX_START = CANBUS_DSPL_HIGHPRIO_TX_START,
	CANBUS_TX_BTN_ACEPT_CONTROL,
	CANBUS_TX_BTN_GOOD,
	CANBUS_TX_BTN_OK,
	CANBUS_TX_BTN_BAD,
	CANBUS_TX_IDNR5,
	CANBUS_TX_IDNR6,
	CANBUS_TX_IDNR7,
	CANBUS_TX_IDNR8,
	CANBUS_TX_IDNR9,
	CANBUS_TX_IDNR10,
	CANBUS_TX_IDNR11,
	CANBUS_TX_IDNR12,
	CANBUS_TX_IDNR13,
	CANBUS_TX_IDNR14,
	CANBUS_TX_IDNR15,

	// IDs mit Prio Niedrig
	CANBUS_TX_LOWPRIONR1 = CANBUS_DSPL_LOWPRIO_TX_START,
	CANBUS_TX_LOWPRIONR2,

	CANBUS_TX_MAX
} CANBUS_TX_ID;

typedef enum {
	// ID2 mit Prio Hoch
	CANBUS_RX_START = CANBUS_DSPL_HIGHPRIO_RX_START,
	CANBUS_RX_IDNR2,
	CANBUS_RX_IDNR3,
	CANBUS_RX_IDNR4,
	CANBUS_RX_IDNR5,
	CANBUS_RX_IDNR6,
	CANBUS_RX_IDNR7,
	CANBUS_RX_IDNR8,
	CANBUS_RX_IDNR9,
	CANBUS_RX_IDNR10,
	CANBUS_RX_IDNR11,
	CANBUS_RX_IDNR12,
	CANBUS_RX_IDNR13,
	CANBUS_RX_IDNR14,
	CANBUS_RX_IDNR15,

	// IDs mit Prio Niedrig
	CANBUS_RX_USER_ID = CANBUS_DSPL_LOWPRIO_RX_START,
	CANBUS_RX_LOG_IN,
	CANBUS_RX_LOG_OUT,
	CANBUS_RX_LANGUAGE,
	CANBUS_RX_SCREEN,
	CANBUS_RX_ID6,
	CANBUS_RX_ID7,
	CANBUS_RX_ID8,
	CANBUS_RX_ID9,
	CANBUS_RX_ID10,

	CANBUS_RX_MAX
} CANBUS_RX_ID;

/*
 * DLC for CANBUS ID to SEND
 */
#define CANBUS_TX_BTN_ACEPT_CONTROL_DLC 1
#define CANBUS_TX_BTN_GOOD_DLC 			1
#define CANBUS_TX_BTN_OK_DLC			1
#define CANBUS_TX_BTN_BAD_DLC			1
// DLC muss definierrtt werden
#define CANBUS_TX_IDNR5_DLC				0
#define CANBUS_TX_IDNR6_DLC				0
#define CANBUS_TX_IDNR7_DLC				0
#define CANBUS_TX_IDNR8_DLC				0
#define CANBUS_TX_IDNR9_DLC				0
#define CANBUS_TX_IDNR10_DLC			0
#define CANBUS_TX_IDNR11_DLC			0
#define CANBUS_TX_IDNR12_DLC			0
#define CANBUS_TX_IDNR13_DLC			0
#define CANBUS_TX_IDNR14_DLC			0
#define CANBUS_TX_IDNR15_DLC			0
// IDs mit Prio Niedrig
#define CANBUS_TX_LOWPRIONR1 			0
#define CANBUS_TX_LOWPRIONR2 			0



extern uint8_t TxData[8];
extern uint8_t RxData[8];
extern CAN_TxHeaderTypeDef TxHeader;
extern CAN_RxHeaderTypeDef RxHeader;
extern uint32_t TxMailbox;
extern CANBUS_RX_ID msgType;
extern CANBUS_TX_ID ID_btnPressed;

extern void CAN_Send(CANBUS_TX_ID CAN_ID, uint8_t dlc, uint8_t *Pdata);
extern void CAN_Receive(CAN_HandleTypeDef *hcan);
/* USER CODE END Private defines */

void MX_CAN2_Init(void);

/* USER CODE BEGIN Prototypes */
void MX_CAN2_Init(void);
void CANx_Config(CAN_HandleTypeDef *hcan);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __CAN_H__ */

