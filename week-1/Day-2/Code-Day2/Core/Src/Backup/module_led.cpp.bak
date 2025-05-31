#include "module_led.h"

/* Hàm khai báo chân */
LED::LED(GPIO_TypeDef *gpioPort, uint16_t gpioPin){
    port = gpioPort;
    pin = gpioPin;
}

/* Hàm bật */
void LED::on(){
    port->BSRR = pin;
}

/* Hàm tắt */
void LED::off(){
    port->BSRR = (pin << 16);
}

/* Hàm đổi trạng thái */
void LED::toggle(){
    if ((port->ODR & pin) == 0)     // Do pin đã được MaskBit trong thư viện HAL rồi nên không cần  << 1
    {
        on();
    }
    else
    {
        off();
    }
}

/* Hàm đổi trạng thái theo thời gian
*       Đối số: time_ON
*               time_OFF
*/
void LED::toggle_On_OFF_time(uint32_t time_ON, uint32_t time_OFF){
    u32_nowTime_ = HAL_GetTick();
    static bool b_toggleStatusLED = 0;

    /* Chu kỳ tắt */
    if ((u32_nowTime_ - u32_lastTime_ >= time_OFF) && (b_toggleStatusLED == false))
    {
        on();
        b_toggleStatusLED = true;
        u32_lastTime_ = u32_nowTime_;
    }

    /* Chu kỳ bật */
    if ((u32_nowTime_ - u32_lastTime_ >= time_ON) && (b_toggleStatusLED == true) )
    {
        off();
        b_toggleStatusLED = false;
        u32_lastTime_ = u32_nowTime_;
    }
}

/* Hàm đổi trạng thái theo số lần
*       Đối số: numberOfTime
*/
void LED::toggle_On_OFF_number(uint8_t numberOfTime, uint16_t delay){
    for (uint8_t i = 0; i < numberOfTime*2; i++)
    {
        toggle();
        HAL_Delay(delay);
    }
}