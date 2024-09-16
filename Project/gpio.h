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
/** 
  * @brief General Purpose I/O
  */

#define        GPIO_A (unsigned int *)  (0x40020000)
#define        GPIO_B (unsigned int *)  (0x40020400)
#define        GPIO_C (unsigned int *)  (0x40020800)
#define        GPIO_D (unsigned int *)  (0x40020C00)
#define        GPIO_E (unsigned int *)  (0x40021000)
#define        GPIO_F (unsigned int *)  (0x40021400)
#define        GPIO_G (unsigned int *)  (0x40021800)
#define        GPIO_H (unsigned int *)  (0x40021C00)
#define        GPIO_I (unsigned int *)  (0x40022000)


                /* Register location */

#define MODER                       0x00
#define OTYPER                      0X04
#define OSPEEDER                    0X08 
#define PUPDR                       0X0C 
#define IDR                         0X10
#define ODR                         0X14
#define BSRR                        0X18 
#define LCKR                        0X1C
#define AFRL                        0X20
#define AFRH                        0X24 
#define AHB1ENR                     0x30


                       /* Pin Number */
#define Pin0                       0
#define Pin1                       1
#define Pin2                       2
#define Pin3                       3
#define Pin4                       4
#define Pin5                       5
#define Pin6                       6
#define Pin7                       7
#define Pin8                       8
#define Pin9                       9
#define Pin10                      10
#define Pin11                      11
#define Pin12                      12
#define Pin13                      13 
#define Pin14                      14 
#define Pin15                      15




                         /* Mode */
#define INPUT                       0x00
#define OUTPUT                      0X01    
#define ALTERNATE FUNCTION          0X10 
#define ANALOG MODE                 0X11 

                    /* typeOutput */
#define PP                            0x00
#define OD                            0X01 
 

            /** @defgroup GPIO_pins_define */


#define GPIO_Pin_0          ((unsigned short)0x0001)/* Pin 0 selected    0000 0000 0000 0001*/
#define GPIO_Pin_1          ((unsigned short)0x0002)/* Pin 1 selected    0000 0000 0000 0010*/
#define GPIO_Pin_2          ((unsigned short)0x0004)/* Pin 2 selected    0000 0000 0000 0100*/ 
#define GPIO_Pin_3          ((unsigned short)0x0008)/* Pin 3 selected    0000 0000 0000 1000*/                           
#define GPIO_Pin_4          ((unsigned short)0x0010)/* Pin 4 selected    0000 0000 0001 0000*/   
#define GPIO_Pin_5          ((unsigned short)0x0020)/* Pin 5 selected    0000 0000 0010 0000*/
#define GPIO_Pin_6          ((unsigned short)0x0040)/* Pin 6 selected    0000 0000 0100 0000*/
#define GPIO_Pin_7          ((unsigned short)0x0080)/* Pin 7 selected    0000 0000 1000 0000*/
#define GPIO_Pin_8          ((unsigned short)0x0100)/* Pin 8 selected    0000 0001 0000 0000*/
#define GPIO_Pin_9          ((unsigned short)0x0200)/* Pin 9 selected    0000 0010 0000 0000*/
#define GPIO_Pin_10         ((unsigned short)0x0400)/* Pin 10 selected   0000 0100 0000 0000*/
#define GPIO_Pin_11         ((unsigned short)0x0800)/* Pin 11 selected   0000 1000 0000 0000*/
#define GPIO_Pin_12         ((unsigned short)0x1000)/* Pin 12 selected   0001 0000 0000 0000*/
#define GPIO_Pin_13         ((unsigned short)0x2000)/* Pin 13 selected   0010 0000 0000 0000*/
#define GPIO_Pin_14         ((unsigned short)0x4000)/* Pin 14 selected   0100 0000 0000 0000*/
#define GPIO_Pin_15         ((unsigned short)0x8000)/* Pin 15 selected   1000 0000 0000 0000*/



/* -----------------Add the function prototypes----------------------*/


/* GPIO enable function */
void GPIO_ClockEnable (unsigned int * gpio_x ) ;

/* GPIO Resete function */
void GPIO_DeInit(unsigned int * gpio_x);

/* Config function */
void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin);

/* Read functions */
unsigned  char GPIO_ReadInputDataBit(unsigned int *  gpio_x, unsigned  short int GPIO_Pin);
unsigned  short int GPIO_ReadInputData(unsigned int *  gpio_x);

/* Write functions */
void GPIO_WriteBit(unsigned int * gpio_x, unsigned  short int GPIO_Pin, char BitVal);
void GPIO_Write(unsigned int * gpio_x, unsigned  short int PortVal);

/***************************END OF FILE********************************/