/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : module_led.h
  * @brief          : Header for module_led.cpp file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#ifndef __MOTOR_CONTROLLER_H
#define __MOTOR_CONTROLLER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
  
/* Class: Led */
class motorController
{
  private:
    GPIO_TypeDef *portIN1_;
    uint16_t pinIN1_;

    GPIO_TypeDef *portIN2_;
    uint16_t pinIN2_;

    bool Ngoai_pham_vi_ = false;

  public:
    motorController(GPIO_TypeDef *portIN1, uint16_t pinIN1, GPIO_TypeDef *portIN2, uint16_t pinIN2);
    ~motorController();
    
    void forward();
    void left();
    void right();
    void stop();
};


#ifdef __cplusplus
}
#endif

#endif /* __MOTOR_CONTROLLER_H */
