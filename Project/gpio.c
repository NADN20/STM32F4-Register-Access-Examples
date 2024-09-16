/**
  ******************************************************************************
  * @file    Lab-Libraries/main.c 
  * @author  Nader Noomen
  * @mail    Nader.noomen@gmail.com
  * @Tel     (+216)23.190.067
  * @version V1.0.0
  * @date    13-09-2024
  *****************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
//Add define for RCC clock
volatile unsigned short int* RCC_GPIO_clock=(unsigned short int*) 0x40023830 ;       
// Add define for RCC reset
volatile unsigned short int * RCC_GPIO_reset=(unsigned short int*) 0x40023810;

/**
  * @brief  Deinitializes the gpio_x peripheral registers to their default reset values.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_ClockEnable (unsigned int * gpio_x)
{

  if (gpio_x == GPIO_A)
  { 
   *RCC_GPIO_clock |= (1<<0x00);
  }
  else if (gpio_x == GPIO_B)
  {
   *RCC_GPIO_clock |= (1<<0x01); 
  }
  else if (gpio_x == GPIO_C)
  {
   *RCC_GPIO_clock |= (1<<0x02);
  } 
  else if (gpio_x == GPIO_D)
  {
   *RCC_GPIO_clock |= (1<<0x04);
  }
  else if (gpio_x == GPIO_E)
  {
   *RCC_GPIO_clock |= (1<<0x08);
  }
  else if (gpio_x == GPIO_F)
  {
   *RCC_GPIO_clock |= (1<<0x10);
  }
  else if (gpio_x == GPIO_G)
  {
   *RCC_GPIO_clock |= (1<<0x20);
  }
  else if (gpio_x == GPIO_H)
  {
   *RCC_GPIO_clock |= (1<<0x40);
  }
   else
  {
     if(gpio_x == GPIO_I)       
     {  
       *RCC_GPIO_clock |= (1<<0x80);
     }              
  }
}  
/**
  * @brief  Deinitializes the gpio_x peripheral registers to their default reset values.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_DeInit(unsigned int * gpio_x)
{
      
  if (gpio_x == GPIO_A)
  {
   *RCC_GPIO_reset |=(1<<0x00);    
   *RCC_GPIO_reset &=~(1<<0x00); 
  }
  else if (gpio_x == GPIO_B)
  {
   *RCC_GPIO_reset |=(1<<0x01);    
   *RCC_GPIO_reset &=~(1<<0x01);
  }
  else if (gpio_x == GPIO_C)
  {
   *RCC_GPIO_reset |=(1<<0x02);  
   *RCC_GPIO_reset &=~(1<<0x02); 
  }
  else if (gpio_x == GPIO_D)
  {
   *RCC_GPIO_reset |=(1<<0x04);    
   *RCC_GPIO_reset &=~(1<<0x04); 
  }
  else if (gpio_x == GPIO_E)
  {
   *RCC_GPIO_reset |=(1<<0x08);    
   *RCC_GPIO_reset &=~(1<<0x08);
  }
  else if (gpio_x == GPIO_F)
  {
   *RCC_GPIO_reset |=(1<<0x10);    
   *RCC_GPIO_reset &=~(1<<0x10); 
  }
  else if (gpio_x == GPIO_G)
  {
   *RCC_GPIO_reset |=(1<<0x20);    
   *RCC_GPIO_reset &=~(1<<0x20); 
  }
  else if (gpio_x == GPIO_H)
  {
   *RCC_GPIO_reset |=(1<<0x40);    
   *RCC_GPIO_reset &=~(1<<0x40); 
  }
  else
  {
    if(gpio_x == GPIO_I)
    {
      *RCC_GPIO_reset |=(1<<0x80);    
      *RCC_GPIO_reset &=~(1<<0x80); 
    }
  }
} 
          
/**   
  * @brief  Configure the gpio_x
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  Mode: can be INPUT, OUTPUT, AF or AN
  * @param  typeOutput: can be PP or OD
  * @param  pin: can be 0...15
  * @retval None
  */

void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin)
{
  volatile unsigned int mask=(2*pin); 
  volatile unsigned int *GPIO_Moder=(gpio_x+MODER); 
  volatile unsigned int *GPIO_OTyper=(gpio_x+OTYPER);
  *GPIO_Moder &=~ (0x03<<mask);    
  *GPIO_Moder |= (Mode<<(mask)); 
   if(typeOutput==OD)
  {
    *GPIO_OTyper |= (1<<pin);
  }
   else
  {  
    *GPIO_OTyper &=~(1<<pin);  
  }
}

/**
  * @brief  Reads the specified input port pin.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin:  specifies the port bit to read.
  *   This parameter can be GPIO_Pin_x where x can be (0..15).
  * @retval The input port pin value.
  */
           
unsigned  char GPIO_ReadInputDataBit(unsigned int *  gpio_x, unsigned  short int GPIO_Pin)
{
  unsigned  char bitstatus = 0x00;
  
   volatile unsigned int *GPIO_IDR_bit= (gpio_x+IDR/4);
  
  if((*GPIO_IDR_bit && GPIO_Pin)!=0x00 )
  {
    bitstatus = 0x01;
  }
  else 
  {
    bitstatus = 0x00;
  }
  return bitstatus;
}
/**
  * @brief  Reads the specified GPIO input data port.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval GPIO input data port value.
  */
           
unsigned  short int GPIO_ReadInputData(unsigned int *  gpio_x)
{
    volatile unsigned int *GPIO_Input_data=(gpio_x+IDR/4) ;
   return(*GPIO_Input_data);
}
/*
/**
  * @brief  Sets or clears the selected data port bit.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @param  BitVal: specifies the value to be written to the selected bit.
  *   This parameter can be one of the BitAction enum values:
  *     @arg Bit_RESET: to clear the port pin
  *     @arg Bit_SET: to set the port pin
  * @retval None
  */
          
void GPIO_WriteBit(unsigned int * gpio_x, unsigned  short int GPIO_Pin, char BitVal)
{
   unsigned int *GPIO_ODR_bit=(gpio_x+ODR/4);
  if(BitVal!=0)
  {
    *GPIO_ODR_bit |= GPIO_Pin;
  }
  else 
  {
    *GPIO_ODR_bit &=~(GPIO_Pin);
  }
} 

/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  PortVal: specifies the value to be written to the port output data register.
  * @retval None
  */
     
void GPIO_Write(unsigned int * gpio_x, unsigned  short int PortVal)
{
 *(gpio_x+ODR)=PortVal ; 
}
/*****************************END OF FILE**************************************/

