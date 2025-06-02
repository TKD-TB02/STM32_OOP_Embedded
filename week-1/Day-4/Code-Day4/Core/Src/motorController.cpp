#include "motorController.h"

/* Hàm khai báo contrutor */
motorController::motorController(GPIO_TypeDef *portIN1, uint16_t pinIN1, GPIO_TypeDef *portIN2, uint16_t pinIN2) : 
portIN1_(portIN1), pinIN1_(pinIN1), portIN2_(portIN2), pinIN2_(pinIN2){}

/* Hàm khai báo Destrutor */
motorController::~motorController(){
    /* Khi ngoài hết phạm vi của object thì bật cờ */
    Ngoai_pham_vi_ = true; 
    stop();     
}

/* Hàm đi thẳng */
void motorController::forward(){
    portIN1_->BSRR = pinIN1_;
    portIN2_->BSRR = pinIN2_;
}

/* Hàm dừng */
void motorController::stop(){
    portIN1_->BSRR = (pinIN1_ << 16);
    portIN2_->BSRR = (pinIN2_ << 16);
}

/* Hàm sang trái*/
void motorController::left(){
    portIN1_->BSRR = (pinIN1_ << 16);
    portIN2_->BSRR = pinIN2_ ;
}

/* Hàm sang phải*/
void motorController::right(){
    portIN1_->BSRR = pinIN1_ ;
    portIN2_->BSRR = (pinIN2_ << 16) ;
}
