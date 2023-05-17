#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"


int main(void)
{
  int i;
  GPIO_InitTypeDef  InitSt;  // 1

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);  // 2

  InitSt.GPIO_Pin = GPIO_Pin_1;  // 3
  InitSt.GPIO_Mode = GPIO_Mode_Out_PP;  // 4
  InitSt.GPIO_Speed = GPIO_Speed_50MHz;  // 5
  GPIO_Init(GPIOC, &InitSt);  // 6
 
  GPIO_ResetBits(GPIOC, GPIO_Pin_13); // Set C13 to Low level ("0")  // 7


  // Enable PORTB Clock  // 8
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  // 9

  InitSt.GPIO_Pin = GPIO_Pin_9;  // 10
  InitSt.GPIO_Mode = GPIO_Mode_IPU;  // 11
  InitSt.GPIO_Speed = GPIO_Speed_2MHz;  // 12
  GPIO_Init(GPIOB, &InitSt);  // 13

  while (1) {
          /* 15*/
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) != 0) {
         /* 16*/
        GPIOC->ODR ^= GPIO_Pin_1; // Invert C13
        /* delay */
        for(i=0;i<0x100000;i++);
        /* 17*/
        GPIOC->ODR ^= GPIO_Pin_1;
        /* delay */
        for(i=0;i<0x100000;i++);
    }
    else {
        GPIO_SetBits(GPIOC, GPIO_Pin_1);  // 14
    }

  }
}