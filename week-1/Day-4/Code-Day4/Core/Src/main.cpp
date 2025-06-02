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
#include "motorController.h"

motorController motor(in1_GPIO_Port, in1_Pin, in2_GPIO_Port, in2_Pin);

int main(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  //MX_IWDG_Init();

  motor.stop();
  HAL_Delay(500);

  /* USER CODE BEGIN WHILE */
  while (1)
  {
    motor.forward();
    HAL_Delay(500);

    motor.left();
    HAL_Delay(500);

    motor.right();
    HAL_Delay(500);

    motor.stop();
    HAL_Delay(500);


    /* Làm mới IWDG */
    //HAL_IWDG_Refresh(&hiwdg);
  }

}


