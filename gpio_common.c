#include "gpio_common.h"

// -------------------------- 推挽输出初始化（参数类型完全匹配标准库） --------------------------
void GPIO_PP_Init(GPIO_TypeDef* port, uint16_t pin)
{
    /* 1. PC13/14/15特殊处理 */
    if (port == GPIOC && (pin == GPIO_Pin_13 || pin == GPIO_Pin_14 || pin == GPIO_Pin_15))
    {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
        PWR_BackupAccessCmd(ENABLE);
    }

    /* 2. 使能GPIO时钟 */
    if (port == GPIOA) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    if (port == GPIOB) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    if (port == GPIOC) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    if (port == GPIOD) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    /* 3. GPIO初始化（完全标准库流程） */
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin   = pin;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = (port == GPIOC && (pin == GPIO_Pin_13 || pin == GPIO_Pin_14 || pin == GPIO_Pin_15)) ? GPIO_Speed_2MHz : GPIO_Speed_50MHz;
    GPIO_Init(port, &GPIO_InitStruct);

    /* 4. 初始高电平 */
    GPIO_SetBits(port, pin);
}

// -------------------------- 电平控制函数（参数类型完全匹配） --------------------------
void GPIO_SetHigh(GPIO_TypeDef* port, uint16_t pin)
{
    GPIO_SetBits(port, pin);  // 标准库函数，类型匹配
}

void GPIO_SetLow(GPIO_TypeDef* port, uint16_t pin)
{
    GPIO_ResetBits(port, pin);  // 标准库函数，类型匹配
}

void GPIO_Toggle(GPIO_TypeDef* port, uint16_t pin)
{
    if (GPIO_ReadOutputDataBit(port, pin) == Bit_SET)
    {
        GPIO_ResetBits(port, pin);
    }
    else
    {
        GPIO_SetBits(port, pin);
    }
}

// -------------------------- 上拉输入函数 --------------------------
void GPIO_PuIn_Init(GPIO_TypeDef* port, uint16_t pin)
{
    RCC_APB2PeriphClockCmd((port == GPIOA) ? RCC_APB2Periph_GPIOA : (port == GPIOB) ? RCC_APB2Periph_GPIOB : RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin   = pin;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IPU;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(port, &GPIO_InitStruct);
}

BitAction GPIO_ReadIn(GPIO_TypeDef* port, uint16_t pin)
{
    return GPIO_ReadInputDataBit(port, pin);
}