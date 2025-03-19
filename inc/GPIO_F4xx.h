/**
  ******************************************************************************
  * @file    GPIO_F4xx.c
  * @author  AlexKeisy for Few Bytes
  * @brief   STM32F4xx  Device GPIO Access Layer System Source File.
  *
  *   This file provides macros to initialize MCU pin`s and control them`s
  *
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2021 AlexKeisy </center></h2>
  *
  *
  ******************************************************************************
  */

/** @addtogroup dplib
  * @{
  */

/** @addtogroup GPIO_control
  * @{
  */




#ifndef GPIO_F4XX_H_
#define GPIO_F4XX_H_

#include "stm32F4xx.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO_PORT_A_NUM 			0
#define GPIO_PORT_B_NUM 			1
#define GPIO_PORT_C_NUM 			2
#define GPIO_PORT_D_NUM 			3
#define GPIO_PORT_E_NUM 			4
#define GPIO_PORT_F_NUM 			5
#define GPIO_PORT_G_NUM 			6
#define GPIO_PORT_H_NUM 			7
#define GPIO_PORT_I_NUM 			8


#define GPIO_PORT_DISABLE 			0
#define GPIO_PORT_ENABLE 			1

/** @defgroup GPIO_mode_define GPIO mode define
  * @brief GPIO Configuration Mode
  * @{
  */
#define  GPIO_MODE_INPUT            0x00000000U   /*!< Input             */
#define  GPIO_MODE_OUTPUT           0x00000001U   /*!< Output            */
#define  GPIO_MODE_AF               0x00000002U   /*!< Alternate Function*/
#define  GPIO_MODE_ANALOG           0x00000003U   /*!< Analog Mode       */
/**
  * @}
  */

/** @defgroup GPIO_oType_define GPIO output type define
  * @brief GPIO Output type
  * @{
  */
#define  GPIO_OTYPE_PP              0x00000000U   /*!< Push Pull             */
#define  GPIO_OTYPE_OD              0x00000001U   /*!< Open Drain            */
/**
  * @}
  */

/** @defgroup GPIO_speed_define  GPIO speed define
  * @brief GPIO Output Maximum frequency
  * @{
  */
#define  GPIO_SPEED_FREQ_LOW        0x00000000U  /*!< IO works at 2 MHz, please refer to the product datasheet */
#define  GPIO_SPEED_FREQ_MEDIUM     0x00000001U  /*!< range 12,5 MHz to 50 MHz, please refer to the product datasheet */
#define  GPIO_SPEED_FREQ_HIGH       0x00000002U  /*!< range 25 MHz to 100 MHz, please refer to the product datasheet  */
#define  GPIO_SPEED_FREQ_VERY_HIGH  0x00000003U  /*!< range 50 MHz to 200 MHz, please refer to the product datasheet  */
/**
  * @}
  */

 /** @defgroup GPIO_pull_define GPIO pull define
   * @brief GPIO Pull-Up or Pull-Down Activation
   * @{
   */
#define  GPIO_NOPULL        		0x00000000U   /*!< No Pull-up or Pull-down activation  */
#define  GPIO_PULLNO        		0x00000000U   /*!< No Pull-up or Pull-down activation  */
#define  GPIO_PULLUP        		0x00000001U   /*!< Pull-up activation                  */
#define  GPIO_PULLDOWN      		0x00000002U   /*!< Pull-down activation                */
/**
  * @}
  */

#define __IO volatile
typedef GPIO_TypeDef  *GPIO_TypeDef_p;

//  pin type contain info about port number and number of pin on port
//  hpin = pinPort<<4 | pinNum
#define hpin        uint8_t
#define pinPort_t   uint8_t
#define pinNum_t    uint8_t
#define pinMask_t   uint16_t


//private definitions  do not use this functions and macro outside of this module
#define PIN_BASE_INC    0x0400UL

#define pin(_pinPort,_pinNum)    ((_pinPort <<4) | _pinNum)
#define pinPort(_pin)     ((_pin>>4) & 0x0F)
#define pinNum(_pin)      (_pin & 0x0F)
#define pinMask(_pin)     (1U  << (_pin & 0x0F) )
#define pinMaskHi(_pin)   (1UL << ((_pin & 0x0F) + 0x10) )

#define pinGPIO(_pin)    ((GPIO_TypeDef_p)(GPIOA_BASE+PIN_BASE_INC*pinPort(_pin)))
#define portGPIO(_prt)    ((GPIO_TypeDef_p)(GPIOA_BASE+PIN_BASE_INC*_prt))

//public definitions
#define pinSet(_pin)    pinGPIO(_pin)->BSRR=pinMask(_pin)
#define pinReset(_pin)  pinGPIO(_pin)->BSRR=pinMaskHi(_pin)
#define pinToggle(_pin) pinGPIO(_pin)->ODR ^=pinMask(_pin)
#define pinGet(_pin)    ( ( (pinGPIO(_pin)->IDR) >> pinNum(_pin)) & 1)

#define pinInitInp(_pin, _pullUpDn) do{ \
	GPIO_TypeDef_p prt= pinGPIO(_pin); \
	int pN2 = pinNum(_pin)*2;	\
	CLEAR_BIT (prt->MODER,(0x03 << pN2 )  ); \
	MODIFY_REG(prt->PUPDR,(0x03 << pN2 ), _pullUpDn <<  pN2 );\
	} while(0U)


#define pinInitAnalog(_pin)	do{ \
	GPIO_TypeDef_p prt= pinGPIO(_pin);\
	int pN2 = pinNum(_pin)*2; \
	SET_BIT  (prt->MODER, 0x00000003U <<  pN2 );\
	CLEAR_BIT(prt->PUPDR, 0x00000003U <<  pN2 );\
	} while(0U)



#define pinInitOut(_pin, _oType, _pullUpDn, _oSpeed, _initVal) do{ \
	GPIO_TypeDef_p prt= pinGPIO(_pin);\
	int pN = pinNum(_pin); \
	int pN2 = pN*2; \
	MODIFY_REG(prt->ODR    ,0x01U <<  pN  , _initVal <<  pN  );\
	MODIFY_REG(prt->MODER  ,0x03U <<  pN2 ,   0x01UL <<  pN2 );\
	MODIFY_REG(prt->OSPEEDR,0x03U <<  pN2 ,   _oSpeed<<  pN2 );\
	MODIFY_REG(prt->OTYPER ,0x01U <<  pN  ,   _oType <<  pN  );\
	MODIFY_REG(prt->PUPDR  ,0x03U <<  pN2 , _pullUpDn<<  pN2 );\
	} while(0U)

#define pinInitAF(_pin, _oType, _pullUpDn, _oSpeed, _AF) do{ \
	GPIO_TypeDef_p prt= pinGPIO(_pin);\
	int pN = pinNum(_pin); \
	int pN2 = pN*2; \
	MODIFY_REG(prt->AFR[(_pin >>3)& 0x01U],0x0FU <<  ((_pin &0x07U)*4) ,   _AF <<  ((_pin & 0x07U)*4) );\
	MODIFY_REG(prt->MODER  ,0x03U <<  pN2 ,   0x02UL <<  pN2 );\
	MODIFY_REG(prt->OSPEEDR,0x03U <<  pN2 ,   _oSpeed<<  pN2 );\
	MODIFY_REG(prt->OTYPER ,0x01U <<  pN  ,   _oType <<  pN  );\
	MODIFY_REG(prt->PUPDR  ,0x03U <<  pN2 , _pullUpDn<<  pN2 );\
	} while(0U)

#define portOnTacting(_prt)   SET_BIT(RCC->AHB1ENR , 0x0001U << _prt)
#define portOffTacting(_prt)  CLEAR_BIT(RCC->AHB1ENR , 0x0001U << _prt)




#ifdef __cplusplus
}
#endif
#endif /* GPIO_F4XX_H_ */
