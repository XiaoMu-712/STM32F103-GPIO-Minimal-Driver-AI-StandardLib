#include "gpio_common.h"

// -------------------------- 推挽输出初始化：参数改为GPIO_Pin，内部拆分port和pin --------------------------
void GPIO_PP_Init(GPIO_Pin gpio)
{
    // 从结构体拆分端口和引脚（核心修改：所有函数都加这一步）
    GPIO_TypeDef* port = gpio.Port;
    uint16_t      pin  = gpio.Pin;

    /* 1. PC13/14/15特殊处理（逻辑完全不变） */
    if (port == GPIOC && (pin == GPIO_Pin_13 || pin == GPIO_Pin_14 || pin == GPIO_Pin_15))
    {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
        PWR_BackupAccessCmd(ENABLE);
    }

    /* 2. 使能GPIO时钟（逻辑完全不变） */
    if (port == GPIOA) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    if (port == GPIOB) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    if (port == GPIOC) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    if (port == GPIOD) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    /* 3. GPIO初始化（逻辑完全不变） */
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin   = pin;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = (port == GPIOC && (pin == GPIO_Pin_13 || pin == GPIO_Pin_14 || pin == GPIO_Pin_15)) ? GPIO_Speed_2MHz : GPIO_Speed_50MHz;
    GPIO_Init(port, &GPIO_InitStruct);

    /* 4. 初始高电平（逻辑完全不变） */
    GPIO_SetBits(port, pin);
}

// -------------------------- 电平控制函数：参数改为GPIO_Pin，内部拆分 --------------------------
void GPIO_SetHigh(GPIO_Pin gpio)
{
    // 拆分结构体
    GPIO_TypeDef* port = gpio.Port;
    uint16_t      pin  = gpio.Pin;
    // 原逻辑不变
    GPIO_SetBits(port, pin);
}

void GPIO_SetLow(GPIO_Pin gpio)
{
    // 拆分结构体
    GPIO_TypeDef* port = gpio.Port;
    uint16_t      pin  = gpio.Pin;
    // 原逻辑不变
    GPIO_ResetBits(port, pin);
}

void GPIO_Toggle(GPIO_Pin gpio)
{
    // 拆分结构体
    GPIO_TypeDef* port = gpio.Port;
    uint16_t      pin  = gpio.Pin;
    // 原逻辑不变
    if (GPIO_ReadOutputDataBit(port, pin) == Bit_SET)
    {
        GPIO_ResetBits(port, pin);
    }
    else
    {
        GPIO_SetBits(port, pin);
    }
}

// -------------------------- 上拉输入初始化：参数改为GPIO_Pin，内部拆分 --------------------------
void GPIO_PuIn_Init(GPIO_Pin gpio)
{
    // 拆分结构体
    GPIO_TypeDef* port = gpio.Port;
    uint16_t      pin  = gpio.Pin;
    // 原逻辑不变
    RCC_APB2PeriphClockCmd((port == GPIOA) ? RCC_APB2Periph_GPIOA : (port == GPIOB) ? RCC_APB2Periph_GPIOB : RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin   = pin;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IPU;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(port, &GPIO_InitStruct);
}

// -------------------------- 下拉输入初始化：参数改为GPIO_Pin，内部拆分 --------------------------
void GPIO_PdIn_Init(GPIO_Pin gpio)
{
    // 拆分结构体
    GPIO_TypeDef* port = gpio.Port;
    uint16_t      pin  = gpio.Pin;
    // 原逻辑不变
    if (port == GPIOA) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    else if (port == GPIOB) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    else if (port == GPIOC) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    else if (port == GPIOD) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin   = pin;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IPD; 
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(port, &GPIO_InitStruct);
}

// -------------------------- 输入电平读取：参数改为GPIO_Pin，内部拆分 --------------------------
BitAction GPIO_ReadIn(GPIO_Pin gpio)
{
    // 拆分结构体
    GPIO_TypeDef* port = gpio.Port;
    uint16_t      pin  = gpio.Pin;
    // 原逻辑不变
    return GPIO_ReadInputDataBit(port, pin);
}