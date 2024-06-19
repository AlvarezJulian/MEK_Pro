/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
extern void Led_Off();
extern void Led_green_On();
extern void Led_orange_On();
extern void Led_red_On();
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_LR_Pin GPIO_PIN_3
#define LCD_LR_GPIO_Port GPIOE
#define I2C2_INT_Pin GPIO_PIN_2
#define I2C2_INT_GPIO_Port GPIOE
#define LCD_UD_Pin GPIO_PIN_4
#define LCD_UD_GPIO_Port GPIOB
#define GPIO2_Pin GPIO_PIN_7
#define GPIO2_GPIO_Port GPIOD
#define LCD_RESET_Pin GPIO_PIN_5
#define LCD_RESET_GPIO_Port GPIOE
#define RS232_INV_Pin GPIO_PIN_9
#define RS232_INV_GPIO_Port GPIOB
#define RS232_F_ON_Pin GPIO_PIN_12
#define RS232_F_ON_GPIO_Port GPIOJ
#define RTC_TS_LED_Pin GPIO_PIN_8
#define RTC_TS_LED_GPIO_Port GPIOI
#define FS_OVER_CURRENT_Pin GPIO_PIN_10
#define FS_OVER_CURRENT_GPIO_Port GPIOG
#define EEP_WC_Pin GPIO_PIN_13
#define EEP_WC_GPIO_Port GPIOC
#define GPIO3_Pin GPIO_PIN_11
#define GPIO3_GPIO_Port GPIOI
#define FS_PowerSwitchOn_Pin GPIO_PIN_13
#define FS_PowerSwitchOn_GPIO_Port GPIOI
#define GPIO4_Pin GPIO_PIN_7
#define GPIO4_GPIO_Port GPIOC
#define I2C1_INT_Pin GPIO_PIN_7
#define I2C1_INT_GPIO_Port GPIOG
#define I2C1_RST_Pin GPIO_PIN_6
#define I2C1_RST_GPIO_Port GPIOG
#define GPIO1_Pin GPIO_PIN_6
#define GPIO1_GPIO_Port GPIOF
#define RS232_F_OFF_Pin GPIO_PIN_10
#define RS232_F_OFF_GPIO_Port GPIOF
#define GPIO5_Pin GPIO_PIN_0
#define GPIO5_GPIO_Port GPIOC
#define GPIO0_Pin GPIO_PIN_3
#define GPIO0_GPIO_Port GPIOG
#define I2C2_RST_Pin GPIO_PIN_2
#define I2C2_RST_GPIO_Port GPIOG
#define CAN2_STB_Pin GPIO_PIN_11
#define CAN2_STB_GPIO_Port GPIOD
#define LCD_BL_CTRL_Pin GPIO_PIN_14
#define LCD_BL_CTRL_GPIO_Port GPIOB
#define LCD_BL_PWM_Pin GPIO_PIN_15
#define LCD_BL_PWM_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#include "se21070_sys_conf.h"
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
