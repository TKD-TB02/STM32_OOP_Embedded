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
#ifndef __MODULE_LED_H
#define __MODULE_LED_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
  
/* Class: Led */
class LED
{
  private:
    GPIO_TypeDef *port;
    uint16_t pin;
    uint32_t u32_nowTime_ = 0;
    uint32_t u32_lastTime_ = 0;
    bool Ngoai_pham_vi_ = false;

  public:
    LED(GPIO_TypeDef *gpioPort, uint16_t gpioPin);
    ~LED();
    
    void on();
    void off();
    void toggle();
    void toggle_On_OFF_time(uint32_t time_ON, uint32_t time_OFF);
    void toggle_On_OFF_number(uint8_t numberOfTime, uint16_t delay);
};


#ifdef __cplusplus
}
#endif

#endif /* __MODULE_LED_H */
