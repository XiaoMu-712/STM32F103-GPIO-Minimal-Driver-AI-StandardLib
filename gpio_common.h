#ifndef GPIO_COMMON_H
#define GPIO_COMMON_H

#include "gpio_port_pin.h"

// -------------------------- 函数声明：参数为两个（端口+引脚），但用户只需传PC_13 --------------------------
// 注：PC_13会被展开为两个参数，与函数参数列表匹配
void GPIO_PP_Init(GPIO_TypeDef* port, uint16_t pin);
void GPIO_SetHigh(GPIO_TypeDef* port, uint16_t pin);
void GPIO_SetLow(GPIO_TypeDef* port, uint16_t pin);
void GPIO_Toggle(GPIO_TypeDef* port, uint16_t pin);
void GPIO_PuIn_Init(GPIO_TypeDef* port, uint16_t pin);
BitAction GPIO_ReadIn(GPIO_TypeDef* port, uint16_t pin);

#endif