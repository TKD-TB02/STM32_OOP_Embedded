/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.cpp
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "iwdg.h"
#include "gpio.h"
#include "config.h"
#include "module_led.h"

struct buzzer_t{
  GPIO_TypeDef *port;
  uint16_t pin;

  /* Hàm bật */
  void on(){
      port->BSRR = pin;
  }

  /* Hàm tắt */
  void off(){
      port->BSRR = (pin << 16);
  }

  /* Hàm đổi trạng thái */
  void toggle(){
      if ((port->ODR & pin) == 0)     // Do pin đã được MaskBit trong thư viện HAL rồi nên không cần  << 1
      {
          on();
      }
      else
      {
          off();
      }
  }

  /* Hàm đổi trạng thái theo số lần
  *       Đối số: numberOfTime
  */
  void toggle_On_OFF_number(uint8_t numberOfTime, uint16_t delay){
      for (uint8_t i = 0; i < numberOfTime*2; i++)
      {
          toggle();
          HAL_Delay(delay);
      }
  }
};



LED ledMain(led_main_GPIO_Port, led_main_Pin);      // led main sử dụng class
buzzer_t buzzer = {buzzer_GPIO_Port, buzzer_Pin};   // buzzer sử dụng Struct


int main(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_IWDG_Init();

  buzzer.toggle_On_OFF_number(3, 100);

  /* USER CODE BEGIN WHILE */
  while (1)
  {
    ledMain.toggle_On_OFF_time(1000, 200);

    /* Làm mới IWDG */
    HAL_IWDG_Refresh(&hiwdg);
  }

}


