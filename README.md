# STM32F103-GPIO-Minimal-Driver-AI-StandardLib
基于标准库的stm32f103c8t6的gpio极简封装（ai修改）,仅需一行代码即可完成对gpio的初始化等常用操作,具体引脚定义查看gpio_port_pin.h
Based on the minimal GPIO encapsulation of the STM32F103C8T6 library (modified by AI), only one line of code is needed to complete common operations such as GPIO initialization. For specific pin definitions, please refer to gpio_port_pin.h.

exmple: GPIO_PP_Init(PC_13);  

25/10/7******
将引脚改为结构体常量类型，最大化泛用性，库函数也同步修改。
同步添加基于此库和freertos的支持多模式多输入的按键驱动库，用于其他系统或者裸机需要修改头文件中时间函数定义，其他使用方法也在头文件中。
Change the pins to be of the structure constant type to maximize their versatility, and simultaneously modify the library functions. Simultaneously, a key driver library based on this library and FreeRTOS is added to support multi-mode and multi-input keys. For other systems or bare-metal devices that need to modify the definitions of time functions in the header files, other usage methods are also provided in the header files.
