#ifndef GPIO_F407XX_H_
#define GPIO_F407XX_H_

#include "stm32F4xx.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO_MAX_PORT 8

#define GPIO_PORT_DISABLE 0
#define GPIO_PORT_ENABLE 1

// for compatibility with hal
/** @defgroup GPIO_mode_define GPIO mode define
  * @brief GPIO Configuration Mode
  *        Elements values convention: 0xX0yz00YZ
  *           - X  : GPIO mode or EXTI Mode
  *           - y  : External IT or Event trigger detection
  *           - z  : IO configuration on External IT or Event
  *           - Y  : Output type (Push Pull or Open Drain)
  *           - Z  : IO Direction mode (Input, Output, Alternate or Analog)
  * @{
  */
#define  GPIO_MODE_INPUT                        0x00000000U   /*!< Input Floating Mode                   */
#define  GPIO_MODE_OUTPUT_PP                    0x00000001U   /*!< Output Push Pull Mode                 */
#define  GPIO_MODE_OUTPUT_OD                    0x00000011U   /*!< Output Open Drain Mode                */
#define  GPIO_MODE_AF_PP                        0x00000002U   /*!< Alternate Function Push Pull Mode     */
#define  GPIO_MODE_AF_OD                        0x00000012U   /*!< Alternate Function Open Drain Mode    */

#define  GPIO_MODE_ANALOG                       0x00000003U   /*!< Analog Mode  */

#define  GPIO_MODE_IT_RISING                    0x10110000U   /*!< External Interrupt Mode with Rising edge trigger detection          */
#define  GPIO_MODE_IT_FALLING                   0x10210000U   /*!< External Interrupt Mode with Falling edge trigger detection         */
#define  GPIO_MODE_IT_RISING_FALLING            0x10310000U   /*!< External Interrupt Mode with Rising/Falling edge trigger detection  */

#define  GPIO_MODE_EVT_RISING                   0x10120000U   /*!< External Event Mode with Rising edge trigger detection               */
#define  GPIO_MODE_EVT_FALLING                  0x10220000U   /*!< External Event Mode with Falling edge trigger detection              */
#define  GPIO_MODE_EVT_RISING_FALLING           0x10320000U   /*!< External Event Mode with Rising/Falling edge trigger detection       */
/**
  * @}
  */

/** @defgroup GPIO_speed_define  GPIO speed define
  * @brief GPIO Output Maximum frequency
  * @{
  */
#define  GPIO_SPEED_FREQ_LOW         0x00000000U  /*!< IO works at 2 MHz, please refer to the product datasheet */
#define  GPIO_SPEED_FREQ_MEDIUM      0x00000001U  /*!< range 12,5 MHz to 50 MHz, please refer to the product datasheet */
#define  GPIO_SPEED_FREQ_HIGH        0x00000002U  /*!< range 25 MHz to 100 MHz, please refer to the product datasheet  */
#define  GPIO_SPEED_FREQ_VERY_HIGH   0x00000003U  /*!< range 50 MHz to 200 MHz, please refer to the product datasheet  */
/**
  * @}
  */

 /** @defgroup GPIO_pull_define GPIO pull define
   * @brief GPIO Pull-Up or Pull-Down Activation
   * @{
   */
#define  GPIO_NOPULL        0x00000000U   /*!< No Pull-up or Pull-down activation  */
#define  GPIO_PULLNO        0x00000000U   /*!< No Pull-up or Pull-down activation  */
#define  GPIO_PULLUP        0x00000001U   /*!< Pull-up activation                  */
#define  GPIO_PULLDOWN      0x00000002U   /*!< Pull-down activation                */


#define __IO volatile

typedef struct
{
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef_F407xx;


typedef GPIO_TypeDef_F407xx  *GPIO_TypeDef_p;



//  pin type contain info about port number and number of pin on port
//  pin_t = pinPort<<4 | pinNum
#define hpin       uint8_t
#define pinPort_t   uint8_t
#define pinNum_t    uint8_t
#define pinMask_t   uint16_t




//private definitions  do not use this functions outside of module
#define PIN_BASE_INC    0x0400UL

#define pin(_pinPort,_pinNum)    ((_pinPort <<4) | _pinNum)
#define pinPort(_pin)   ((_pin>>4) & 0x0F)
#define pinNum(_pin)    (_pin & 0x0F)
#define pinMask(_pin)    (1UL << (_pin & 0x0F) )
#define pinMaskHi(_pin)    (1UL << ((_pin & 0x0F) + 0x10) )

//public definitions
#define pinSet(_pin)    ((GPIO_TypeDef_p)(GPIOA_BASE+PIN_BASE_INC*pinPort(_pin)))->BSRR=pinMask(_pin)
#define pinReset(_pin)  ((GPIO_TypeDef_p)(GPIOA_BASE+PIN_BASE_INC*pinPort(_pin)))->BSRR=pinMaskHi(_pin)
#define pinGet(_pin)    ((((GPIO_TypeDef_p)(GPIOA_BASE+PIN_BASE_INC*pinPort(_pin)))->IDR >> pinNum(_pin)) & 1)

#define pinModeGet(_pin)    (((GPIO_TypeDef_p)(GPIOA_BASE+PIN_BASE_INC*pinPort(_pin)))->MODER)
#define pinIDRGet(_pin)    (((GPIO_TypeDef_p)(GPIOA_BASE+PIN_BASE_INC*pinPort(_pin)))->IDR)

void pinInit(hpin _pin, uint32_t _mode,  uint32_t _pull ,  uint32_t _alternate , uint32_t _speed);

uint32_t GPIO_InitAsDefined();





#ifdef __cplusplus
}
#endif
#endif /* GPIO_F407XX_H_ */
