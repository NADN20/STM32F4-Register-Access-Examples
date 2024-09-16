/**
  ******************************************************************************
  * @file    Lab-Libraries/main.c 
  * @author  Nader Noomen
  * @mail    Nader.noomen@gmail.com
  * @Tel     (+216)23.190.067
  * @version V1.0.0
  * @date    13-09-2024
  *****************************************************************************/

#include "gpio.h"

/* Private define ------------------------------------------------------------*/
#define NOMBRE_BOUCLES 100
                                                       
/* Private function prototypes -----------------------------------------------*/
void Delay(volatile unsigned  int  nCount);


/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */

int main(void)
{
  unsigned  int counter = 0x00;  

  /*Enable the clock for Port D*/
  GPIO_ClockEnable(GPIO_D);

  /* Re-initialize the Port D registers */
  GPIO_DeInit(GPIO_D);
  /*Read input data bit from GPIO_D*/
  GPIO_ReadInputDataBit( GPIO_D,GPIO_Pin_14);
  /*Read input data  from GPIO_D*/
  GPIO_ReadInputData(GPIO_D);
  
/* --- Configure PD14 and PD15 in Output Push-Pull mode with a speed of 2 MHz---*/  

  GPIO_Init(GPIO_D, OUTPUT,  PP, 14);
  GPIO_Init(GPIO_D, OUTPUT,  PP, 15);

  for(counter=0; counter<NOMBRE_BOUCLES ; counter++)
  {
    
   GPIO_WriteBit(GPIO_D, GPIO_Pin_14, 0x01)  ;
   GPIO_WriteBit(GPIO_D, GPIO_Pin_15, 0x01)  ;
    
    Delay(0x3FFFFF) ;
    
     
   GPIO_WriteBit(GPIO_D, GPIO_Pin_14, 0x00)  ;
   GPIO_WriteBit(GPIO_D, GPIO_Pin_15, 0x00)  ;
   
    Delay(0x3FFFFF) ;
           
  }
  
  while(1);
}
/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */
void Delay(volatile unsigned  int  nCount)
{
  for(; nCount != 0; nCount--);
}

/***************************END OF FILE********************************/
