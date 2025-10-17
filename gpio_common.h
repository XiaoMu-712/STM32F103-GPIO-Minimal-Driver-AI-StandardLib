#ifndef GPIO_COMMON_H
#define GPIO_COMMON_H



#include "gpio_port_pin.h"  


void GPIO_PP_Init(GPIO_Pin gpio);       
void GPIO_SetHigh(GPIO_Pin gpio);       
void GPIO_SetLow(GPIO_Pin gpio);        
void GPIO_Toggle(GPIO_Pin gpio);        
void GPIO_PuIn_Init(GPIO_Pin gpio);     
void GPIO_PdIn_Init(GPIO_Pin gpio);     
BitAction GPIO_ReadIn(GPIO_Pin gpio);   


#endif