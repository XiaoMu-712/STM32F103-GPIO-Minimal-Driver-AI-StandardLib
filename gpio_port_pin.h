#ifndef GPIO_PORT_PIN_H
#define GPIO_PORT_PIN_H

#include "stm32f10x.h"

// -------------------------- 先定义GPIO_Pin结构体 --------------------------
typedef struct
{
    GPIO_TypeDef* Port;  // 端口指针（如GPIOA）
    uint16_t      Pin;   // 引脚掩码（如GPIO_Pin_0）
} GPIO_Pin;

// -------------------------- 再重新定义引脚宏 --------------------------
// 关键修改：让PA_0成为GPIO_Pin类型的结构体常量，直接包含Port和Pin
#define PA_0     ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_0})
#define PA_1     ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_1})
#define PA_2     ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_2})
#define PA_3     ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_3})
#define PA_4     ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_4})
#define PA_5     ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_5})  // SPI1_SCK
#define PA_6     ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_6})  // SPI1_MISO
#define PA_7     ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_7})  // SPI1_MOSI
#define PA_8     ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_8})  // TIM1_CH1
#define PA_9     ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_9})  // USART1_TX
#define PA_10    ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_10}) // USART1_RX
#define PA_11    ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_11}) // USB_DM
#define PA_12    ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_12}) // USB_DP
#define PA_13    ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_13}) // SWDIO（慎⽤）
#define PA_14    ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_14}) // SWCLK（慎⽤）
#define PA_15    ((GPIO_Pin){(GPIO_TypeDef*)GPIOA, GPIO_Pin_15}) // JTDI（慎⽤）

// PB系列同理，全部改成结构体常量形式
#define PB_0     ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_0})  // TIM3_CH3
#define PB_1     ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_1})  // TIM3_CH4
#define PB_2     ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_2})  // BOOT1（慎⽤）
#define PB_3     ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_3})  // JTDO（慎⽤）
#define PB_4     ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_4})  // JTRST（慎⽤）
#define PB_5     ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_5})  // SPI1_NSS
#define PB_6     ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_6})  // I2C1_SCL
#define PB_7     ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_7})  // I2C1_SDA
#define PB_8     ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_8})  // TIM4_CH3
#define PB_9     ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_9})  // TIM4_CH4
#define PB_10    ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_10}) // USART3_TX
#define PB_11    ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_11}) // USART3_RX
#define PB_12    ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_12}) // SPI2_NSS
#define PB_13    ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_13}) // SPI2_SCK
#define PB_14    ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_14}) // SPI2_MISO
#define PB_15    ((GPIO_Pin){(GPIO_TypeDef*)GPIOB, GPIO_Pin_15}) // SPI2_MOSI

// PC、PD系列同理，全部按此格式修改
#define PC_0     ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_0})  // TIM3_CH2
#define PC_1     ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_1})  // TIM3_CH1
#define PC_2     ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_2})  // TIM3_ETR
#define PC_3     ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_3})  // TIM2_CH4
#define PC_4     ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_4})  // DAC_OUT1
#define PC_5     ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_5})  // DAC_OUT2
#define PC_6     ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_6})  // TIM3_CH1N
#define PC_7     ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_7})  // TIM3_CH2N
#define PC_8     ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_8})  // TIM3_CH3
#define PC_9     ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_9})  // TIM3_CH4
#define PC_10    ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_10}) // TIM2_CH3
#define PC_13    ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_13}) // 板载LED
#define PC_14    ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_14}) // RTC_OSC（慎⽤）
#define PC_15    ((GPIO_Pin){(GPIO_TypeDef*)GPIOC, GPIO_Pin_15}) // RTC_OSC（慎⽤）
#define PD_0     ((GPIO_Pin){(GPIO_TypeDef*)GPIOD, GPIO_Pin_0})  // TIM2_CH1
#define PD_1     ((GPIO_Pin){(GPIO_TypeDef*)GPIOD, GPIO_Pin_1})  // TIM2_CH2

#endif