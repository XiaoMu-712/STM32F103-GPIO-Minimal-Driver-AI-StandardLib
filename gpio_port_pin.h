#ifndef GPIO_PORT_PIN_H
#define GPIO_PORT_PIN_H

#include "stm32f10x.h"

// -------------------------- 引脚预定义（保持单标识符） --------------------------
#define PA_0     (GPIO_TypeDef*)GPIOA, GPIO_Pin_0
#define PA_1     (GPIO_TypeDef*)GPIOA, GPIO_Pin_1
#define PA_2     (GPIO_TypeDef*)GPIOA, GPIO_Pin_2
#define PA_3     (GPIO_TypeDef*)GPIOA, GPIO_Pin_3
#define PA_4     (GPIO_TypeDef*)GPIOA, GPIO_Pin_4
#define PA_5     (GPIO_TypeDef*)GPIOA, GPIO_Pin_5
#define PA_6     (GPIO_TypeDef*)GPIOA, GPIO_Pin_6
#define PA_7     (GPIO_TypeDef*)GPIOA, GPIO_Pin_7
#define PA_8     (GPIO_TypeDef*)GPIOA, GPIO_Pin_8
#define PA_9     (GPIO_TypeDef*)GPIOA, GPIO_Pin_9
#define PA_10    (GPIO_TypeDef*)GPIOA, GPIO_Pin_10
#define PA_11    (GPIO_TypeDef*)GPIOA, GPIO_Pin_11
#define PA_12    (GPIO_TypeDef*)GPIOA, GPIO_Pin_12
#define PA_13    (GPIO_TypeDef*)GPIOA, GPIO_Pin_13
#define PA_14    (GPIO_TypeDef*)GPIOA, GPIO_Pin_14
#define PA_15    (GPIO_TypeDef*)GPIOA, GPIO_Pin_15

#define PB_0     (GPIO_TypeDef*)GPIOB, GPIO_Pin_0
#define PB_1     (GPIO_TypeDef*)GPIOB, GPIO_Pin_1
#define PB_2     (GPIO_TypeDef*)GPIOB, GPIO_Pin_2
#define PB_3     (GPIO_TypeDef*)GPIOB, GPIO_Pin_3
#define PB_4     (GPIO_TypeDef*)GPIOB, GPIO_Pin_4
#define PB_5     (GPIO_TypeDef*)GPIOB, GPIO_Pin_5
#define PB_6     (GPIO_TypeDef*)GPIOB, GPIO_Pin_6
#define PB_7     (GPIO_TypeDef*)GPIOB, GPIO_Pin_7
#define PB_8     (GPIO_TypeDef*)GPIOB, GPIO_Pin_8
#define PB_9     (GPIO_TypeDef*)GPIOB, GPIO_Pin_9
#define PB_10    (GPIO_TypeDef*)GPIOB, GPIO_Pin_10
#define PB_11    (GPIO_TypeDef*)GPIOB, GPIO_Pin_11
#define PB_12    (GPIO_TypeDef*)GPIOB, GPIO_Pin_12
#define PB_13    (GPIO_TypeDef*)GPIOB, GPIO_Pin_13
#define PB_14    (GPIO_TypeDef*)GPIOB, GPIO_Pin_14
#define PB_15    (GPIO_TypeDef*)GPIOB, GPIO_Pin_15

#define PC_0     (GPIO_TypeDef*)GPIOC, GPIO_Pin_0
#define PC_1     (GPIO_TypeDef*)GPIOC, GPIO_Pin_1
#define PC_2     (GPIO_TypeDef*)GPIOC, GPIO_Pin_2
#define PC_3     (GPIO_TypeDef*)GPIOC, GPIO_Pin_3
#define PC_4     (GPIO_TypeDef*)GPIOC, GPIO_Pin_4
#define PC_5     (GPIO_TypeDef*)GPIOC, GPIO_Pin_5
#define PC_6     (GPIO_TypeDef*)GPIOC, GPIO_Pin_6
#define PC_7     (GPIO_TypeDef*)GPIOC, GPIO_Pin_7
#define PC_8     (GPIO_TypeDef*)GPIOC, GPIO_Pin_8
#define PC_9     (GPIO_TypeDef*)GPIOC, GPIO_Pin_9
#define PC_10    (GPIO_TypeDef*)GPIOC, GPIO_Pin_10
#define PC_13    (GPIO_TypeDef*)GPIOC, GPIO_Pin_13  // 目标引脚
#define PC_14    (GPIO_TypeDef*)GPIOC, GPIO_Pin_14
#define PC_15    (GPIO_TypeDef*)GPIOC, GPIO_Pin_15

#define PD_0     (GPIO_TypeDef*)GPIOD, GPIO_Pin_0
#define PD_1     (GPIO_TypeDef*)GPIOD, GPIO_Pin_1

// -------------------------- 引脚结构体（明确类型） --------------------------
typedef struct
{
    GPIO_TypeDef* Port;  // 明确为GPIO端口指针类型
    uint16_t      Pin;   // 引脚掩码类型
} GPIO_Pin;

#endif