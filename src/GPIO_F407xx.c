#include <GPIO_F407xx.h>
#include <GPIO_cfg_F407.h>
#include <dp_errors.h>
#include <jacket.h>


// declarations for internal  use
#define GPIO_mode             0x00000003U
#define EXTI_mode             0x10000000U
#define GPIO_MODE_IT          0x00010000U
#define GPIO_MODE_EVT         0x00020000U
#define RISING_EDGE           0x00100000U
#define FALLING_EDGE          0x00200000U
#define GPIO_OUTPUT_TYPE      0x00000010U

#define GPIO_MAX_PORT 8

#define GPIO_PORT_A_NUM 0
#define GPIO_PORT_B_NUM 1
#define GPIO_PORT_C_NUM 2
#define GPIO_PORT_D_NUM 3
#define GPIO_PORT_E_NUM 4
#define GPIO_PORT_F_NUM 5
#define GPIO_PORT_G_NUM 6
#define GPIO_PORT_H_NUM 7
#define GPIO_PORT_I_NUM 8



#define  ONE_BIT    0x01UL
#define  TWO_BIT    0x03UL
#define  THREE_BIT  0x07UL
#define  FOUR_BIT   0x0FUL

#define __DP_RCC_SYSCFG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);\
                                        UNUSED(tmpreg); \
                                          } while(0U)


void pinInit(hpin _pin, uint32_t _mode,  uint32_t _pull , uint32_t _alternate , uint32_t _speed){
	uint32_t pp = pinPort(_pin);
	GPIO_TypeDef_p _base = (GPIO_TypeDef_p)(GPIOA_BASE+PIN_BASE_INC*pp);
	pinNum_t pn =pinNum(_pin);
	uint32_t temp ;
	uint32_t iocurrent ;
    iocurrent = 0x01U << pn;
    //enable tact`ing
    if ((RCC->AHB1ENR & (0x01U<<pp)) == 0  ){
        RCC->AHB1ENR |=0x01U <<pp;//PORTpp enable tact`s
    }

    /*--------------------- GPIO Mode Configuration ------------------------*/
    /* In case of Alternate function mode selection */
    if(((_mode & 0xFFU) == GPIO_MODE_AF_PP) || ((_mode & 0xFFU) == GPIO_MODE_AF_OD))
    {
      /*!!! Check the Alternate function parameter */
      /* Configure Alternate function mapped with the current IO */
	    MODIFY_REG(_base->AFR[pn>>3],FOUR_BIT <<((pn & THREE_BIT)*4),(uint32_t)_alternate <<((pn & THREE_BIT)*4) );
    }

    /* Configure IO Direction mode (Input, Output, Alternate or Analog) */
	MODIFY_REG(_base->MODER, (TWO_BIT <<(pn*2)),((_mode & GPIO_mode)<<(pn*2)) );


    /* In case of Output or Alternate function mode selection */
    if(((_mode & 0xFF) == GPIO_MODE_OUTPUT_PP) || ((_mode & 0xFF) == GPIO_MODE_AF_PP) ||
       ((_mode & 0xFF) == GPIO_MODE_OUTPUT_OD) || ((_mode & 0xFF) == GPIO_MODE_AF_OD))
    {
      /*!!! Check the Speed parameter */
      //assert_param(IS_GPIO_SPEED(_speed));
      /* Configure the IO Speed */
      MODIFY_REG(_base->OSPEEDR,TWO_BIT <<(pn*2),(uint32_t)_speed <<(pn*2) );

      /* Configure the IO Output Type */
      MODIFY_REG(_base->OTYPER,pinMask(_pin), (((_mode & GPIO_OUTPUT_TYPE) >> 4U) <<pn) );
    }

    /* Activate the Pull-up or Pull down resistor for the current IO */
	MODIFY_REG(_base->PUPDR,TWO_BIT <<(pn*2),_pull <<(pn*2) );

    /*--------------------- EXTI Mode Configuration ------------------------*/
    /* Configure the External Interrupt or event for the current IO */
    if((_mode & EXTI_mode) == EXTI_mode)
    {
      /* Enable SYSCFG Clock */
      __DP_RCC_SYSCFG_CLK_ENABLE();

      temp = SYSCFG->EXTICR[pn >> 2U];
      temp &= ~(0x0FU << (4U * (pn & 0x03U)));
      temp |= ((uint32_t)(pinPort(_pin)) << (4U * (pn & 0x03U)));
      SYSCFG->EXTICR[pn >> 2U] = temp;

      /* Clear EXTI line configuration */
      temp = EXTI->IMR;
      temp &= ~((uint32_t)iocurrent);
      if((_mode & GPIO_MODE_IT) == GPIO_MODE_IT)
      {
        temp |= iocurrent;
      }
      EXTI->IMR = temp;

      temp = EXTI->EMR;
      temp &= ~((uint32_t)iocurrent);
      if((_mode & GPIO_MODE_EVT) == GPIO_MODE_EVT)
      {
        temp |= iocurrent;
      }
      EXTI->EMR = temp;

      /* Clear Rising Falling edge configuration */
      temp = EXTI->RTSR;
      temp &= ~((uint32_t)iocurrent);
      if((_mode & RISING_EDGE) == RISING_EDGE)
      {
        temp |= iocurrent;
      }
      EXTI->RTSR = temp;

      temp = EXTI->FTSR;
      temp &= ~((uint32_t)iocurrent);
      if((_mode & FALLING_EDGE) == FALLING_EDGE)
      {
        temp |= iocurrent;
      }
      EXTI->FTSR = temp;
    }

};

// port = A,B,C...
#define GPIO_MODE(Port)\
	((GPIO_## Port ## 0_MODE  & GPIO_mode) << ( 0 *2) )+ \
	((GPIO_## Port ## 1_MODE  & GPIO_mode) << ( 1 *2) )+ \
	((GPIO_## Port ## 2_MODE  & GPIO_mode) << ( 2 *2) )+ \
	((GPIO_## Port ## 3_MODE  & GPIO_mode) << ( 3 *2) )+ \
	((GPIO_## Port ## 4_MODE  & GPIO_mode) << ( 4 *2) )+ \
	((GPIO_## Port ## 5_MODE  & GPIO_mode) << ( 5 *2) )+ \
	((GPIO_## Port ## 6_MODE  & GPIO_mode) << ( 6 *2) )+ \
	((GPIO_## Port ## 7_MODE  & GPIO_mode) << ( 7 *2) )+ \
	((GPIO_## Port ## 8_MODE  & GPIO_mode) << ( 8 *2) )+ \
	((GPIO_## Port ## 9_MODE  & GPIO_mode) << ( 9 *2) )+ \
	((GPIO_## Port ## 10_MODE  & GPIO_mode) << ( 10 *2) )+ \
	((GPIO_## Port ## 11_MODE  & GPIO_mode) << ( 11 *2) )+ \
	((GPIO_## Port ## 12_MODE  & GPIO_mode) << ( 12 *2) )+ \
	((GPIO_## Port ## 13_MODE  & GPIO_mode) << ( 13 *2) )+ \
	((GPIO_## Port ## 14_MODE  & GPIO_mode) << ( 14 *2) )+ \
	((GPIO_## Port ## 15_MODE  & GPIO_mode) << ( 15 *2) )

#define GPIO_AF_LO(Port)\
	((GPIO_## Port ## 0_AF  & FOUR_BIT) << ( 0 *4) )+ \
	((GPIO_## Port ## 1_AF  & FOUR_BIT) << ( 1 *4) )+ \
	((GPIO_## Port ## 2_AF  & FOUR_BIT) << ( 2 *4) )+ \
	((GPIO_## Port ## 3_AF  & FOUR_BIT) << ( 3 *4) )+ \
	((GPIO_## Port ## 4_AF  & FOUR_BIT) << ( 4 *4) )+ \
	((GPIO_## Port ## 5_AF  & FOUR_BIT) << ( 5 *4) )+ \
	((GPIO_## Port ## 6_AF  & FOUR_BIT) << ( 6 *4) )+ \
	((GPIO_## Port ## 7_AF  & FOUR_BIT) << ( 7 *4) )

#define GPIO_AF_HI(Port)\
	((GPIO_## Port ## 8_AF  & FOUR_BIT) << ( 0 *4) )+ \
	((GPIO_## Port ## 9_AF  & FOUR_BIT) << ( 1 *4) )+ \
	((GPIO_## Port ## 10_AF  & FOUR_BIT) << ( 2 *4) )+ \
	((GPIO_## Port ## 11_AF  & FOUR_BIT) << ( 3 *4) )+ \
	((GPIO_## Port ## 12_AF  & FOUR_BIT) << ( 4 *4) )+ \
	((GPIO_## Port ## 13_AF  & FOUR_BIT) << ( 5 *4) )+ \
	((GPIO_## Port ## 14_AF  & FOUR_BIT) << ( 6 *4) )+ \
	((GPIO_## Port ## 15_AF  & FOUR_BIT) << ( 7 *4) )

#define GPIO_OTYPE(Port)\
	((GPIO_## Port ## 0_MODE  & GPIO_OUTPUT_TYPE) >>  4  )+ \
	((GPIO_## Port ## 1_MODE  & GPIO_OUTPUT_TYPE) >>  3  )+ \
	((GPIO_## Port ## 2_MODE  & GPIO_OUTPUT_TYPE) >>  2  )+ \
	((GPIO_## Port ## 3_MODE  & GPIO_OUTPUT_TYPE) >>  1  )+ \
	((GPIO_## Port ## 4_MODE  & GPIO_OUTPUT_TYPE)        )+ \
	((GPIO_## Port ## 5_MODE  & GPIO_OUTPUT_TYPE) <<  1  )+ \
	((GPIO_## Port ## 6_MODE  & GPIO_OUTPUT_TYPE) <<  2  )+ \
	((GPIO_## Port ## 7_MODE  & GPIO_OUTPUT_TYPE) <<  3  )+ \
	((GPIO_## Port ## 8_MODE  & GPIO_OUTPUT_TYPE) <<  4  )+ \
	((GPIO_## Port ## 9_MODE  & GPIO_OUTPUT_TYPE) <<  5  )+ \
	((GPIO_## Port ## 10_MODE  & GPIO_OUTPUT_TYPE) <<  6  )+ \
	((GPIO_## Port ## 11_MODE  & GPIO_OUTPUT_TYPE) <<  7  )+ \
	((GPIO_## Port ## 12_MODE  & GPIO_OUTPUT_TYPE) <<  8  )+ \
	((GPIO_## Port ## 13_MODE  & GPIO_OUTPUT_TYPE) <<  9  )+ \
	((GPIO_## Port ## 14_MODE  & GPIO_OUTPUT_TYPE) <<  10 )+ \
	((GPIO_## Port ## 15_MODE  & GPIO_OUTPUT_TYPE) <<  11 )

#define GPIO_PULL(Port)\
	((GPIO_## Port ## 0_PULL  ) << ( 0 *2) )+ \
	((GPIO_## Port ## 1_PULL  ) << ( 1 *2) )+ \
	((GPIO_## Port ## 2_PULL  ) << ( 2 *2) )+ \
	((GPIO_## Port ## 3_PULL  ) << ( 3 *2) )+ \
	((GPIO_## Port ## 4_PULL  ) << ( 4 *2) )+ \
	((GPIO_## Port ## 5_PULL  ) << ( 5 *2) )+ \
	((GPIO_## Port ## 6_PULL  ) << ( 6 *2) )+ \
	((GPIO_## Port ## 7_PULL  ) << ( 7 *2) )+ \
	((GPIO_## Port ## 8_PULL  ) << ( 8 *2) )+ \
	((GPIO_## Port ## 9_PULL  ) << ( 9 *2) )+ \
	((GPIO_## Port ## 10_PULL  ) << ( 10 *2) )+ \
	((GPIO_## Port ## 11_PULL  ) << ( 11 *2) )+ \
	((GPIO_## Port ## 12_PULL  ) << ( 12 *2) )+ \
	((GPIO_## Port ## 13_PULL  ) << ( 13 *2) )+ \
	((GPIO_## Port ## 14_PULL  ) << ( 14 *2) )+ \
	((GPIO_## Port ## 15_PULL  ) << ( 15 *2) )

#define GPIO_MODE_OR(Port)\
	( (GPIO_## Port ## 0_MODE)  \
	| (GPIO_## Port ## 1_MODE)  \
	| (GPIO_## Port ## 2_MODE)  \
	| (GPIO_## Port ## 3_MODE)  \
	| (GPIO_## Port ## 4_MODE)  \
	| (GPIO_## Port ## 5_MODE)  \
	| (GPIO_## Port ## 6_MODE)  \
	| (GPIO_## Port ## 7_MODE)  \
	| (GPIO_## Port ## 8_MODE)  \
	| (GPIO_## Port ## 9_MODE)  \
	| (GPIO_## Port ## 10_MODE)  \
	| (GPIO_## Port ## 11_MODE)  \
	| (GPIO_## Port ## 12_MODE)  \
	| (GPIO_## Port ## 13_MODE)  \
	| (GPIO_## Port ## 14_MODE)  \
	| (GPIO_## Port ## 15_MODE)  )


#define GPIO_CFG_EXTI_ONE(X_MODE, X_PORT, X_PIN)\
	if (X_MODE & EXTI_mode ){ \
	MODIFY_REG(SYSCFG->EXTICR[X_PIN >> 2U],(FOUR_BIT <<((X_PIN & 0x03)*4 )),((uint32_t)(GPIO_PORT_ ## X_PORT ##_NUM) << ( (X_PIN & 0x03U)*4 )) );\
	MODIFY_REG(EXTI->RTSR,(1U << X_PIN ), (   ((uint32_t)((X_MODE >> 20 ) & 0x01))<< X_PIN  ) );\
	MODIFY_REG(EXTI->FTSR,(1U << X_PIN ), (   ((uint32_t)((X_MODE >> 21 ) & 0x01))<< X_PIN  ) );\
	EXTI->PR|=(1U << X_PIN );\
	MODIFY_REG(EXTI->IMR,(1U << X_PIN ), (   ((uint32_t)((X_MODE >> 16 ) & 0x01))<< X_PIN  ) );\
	MODIFY_REG(EXTI->EMR,(1U << X_PIN ), (   ((uint32_t)((X_MODE >> 17 ) & 0x01))<< X_PIN  ) ); }

#define GPIO_CFG_EXTI(Port)\
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 0_MODE), Port, 0); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 1_MODE), Port, 1); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 2_MODE), Port, 2); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 3_MODE), Port, 3); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 4_MODE), Port, 4); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 5_MODE), Port, 5); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 6_MODE), Port, 6); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 7_MODE), Port, 7); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 8_MODE), Port, 8); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 9_MODE), Port, 9); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 10_MODE), Port, 10); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 11_MODE), Port, 11); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 12_MODE), Port, 12); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 13_MODE), Port, 13); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 14_MODE), Port, 14); \
	GPIO_CFG_EXTI_ONE((GPIO_## Port ## 15_MODE), Port, 15); \


uint32_t GPIO_InitAsDefined(){
RCC->AHB1ENR |= ( GPIO_PORTA_EN) | (GPIO_PORTB_EN << 1) | (GPIO_PORTC_EN << 2) | (GPIO_PORTD_EN << 3) | (GPIO_PORTE_EN << 4) | (GPIO_PORTF_EN << 5);
//  | (GPIO_PORTG_EN << 6) | (GPIO_PORTH_EN << 7) | (GPIO_PORTI_EN << 8) | (GPIO_PORTJ_EN << 9) | (GPIO_PORTK_EN << 10)

#if GPIO_PORTA_EN ==GPIO_PORT_ENABLE
	((GPIO_TypeDef_p) GPIOA_BASE)->AFR[0] = GPIO_AF_LO(A);
	((GPIO_TypeDef_p) GPIOA_BASE)->AFR[1] = GPIO_AF_HI(A);
	((GPIO_TypeDef_p) GPIOA_BASE)->MODER  = GPIO_MODE(A);
	((GPIO_TypeDef_p) GPIOA_BASE)->OTYPER = GPIO_OTYPE(A);
	((GPIO_TypeDef_p) GPIOA_BASE)->PUPDR  = GPIO_PULL(A);
	//GPIO EXTI
	#if GPIO_MODE_OR(A)> GPIO_MODE_IT
    	      // Enable SYSCFG Clock
  		__DP_RCC_SYSCFG_CLK_ENABLE();

	#endif
#endif

#if GPIO_PORTC_EN ==GPIO_PORT_ENABLE
	((GPIO_TypeDef_p) GPIOC_BASE)->AFR[0] = GPIO_AF_LO(C);
	((GPIO_TypeDef_p) GPIOC_BASE)->AFR[1] = GPIO_AF_HI(C);
	((GPIO_TypeDef_p) GPIOC_BASE)->MODER  = GPIO_MODE(C);
	((GPIO_TypeDef_p) GPIOC_BASE)->OTYPER = GPIO_OTYPE(C);
	((GPIO_TypeDef_p) GPIOC_BASE)->PUPDR  = GPIO_PULL(C);
	//GPIO EXTI
	#if GPIO_MODE_OR(C)> GPIO_MODE_IT
  		__DP_RCC_SYSCFG_CLK_ENABLE();
	#endif
#endif




#if GPIO_PORTE_EN ==GPIO_PORT_ENABLE
	((GPIO_TypeDef_p) GPIOE_BASE)->AFR[0] = GPIO_AF_LO(E);
	((GPIO_TypeDef_p) GPIOE_BASE)->AFR[1] = GPIO_AF_HI(E);
	((GPIO_TypeDef_p) GPIOE_BASE)->MODER  = GPIO_MODE(E);
	((GPIO_TypeDef_p) GPIOE_BASE)->OTYPER = GPIO_OTYPE(E);
	((GPIO_TypeDef_p) GPIOE_BASE)->PUPDR  = GPIO_PULL(E);
	//GPIO EXTI
	#if GPIO_MODE_OR(E)> GPIO_MODE_IT
  		__DP_RCC_SYSCFG_CLK_ENABLE();

  		/*
  		uint32_t X_MODE = GPIO_E4_MODE;
  		uint32_t X_PIN  = 4;
  		uint32_t X_PORT_NUM =4;
  		if (X_MODE & EXTI_mode ){ \
  		MODIFY_REG(SYSCFG->EXTICR[X_PIN >> 2U],(FOUR_BIT <<((X_PIN & 0x03)*4 )),((uint32_t)(X_PORT_NUM) << ( (X_PIN & 0x03U)*4 )) );\
  		MODIFY_REG(EXTI->RTSR,(1U << X_PIN ), (   ((uint32_t)((X_MODE >> 20 ) & 0x01))<< X_PIN  ) );\
  		MODIFY_REG(EXTI->FTSR,(1U << X_PIN ), (   ((uint32_t)((X_MODE >> 21 ) & 0x01))<< X_PIN  ) );\
  		EXTI->PR=(1U << X_PIN );\
  		MODIFY_REG(EXTI->IMR,(1U << X_PIN ), (   ((uint32_t)((X_MODE >> 16 ) & 0x01))<< X_PIN  ) );\
  		MODIFY_REG(EXTI->EMR,(1U << X_PIN ), (   ((uint32_t)((X_MODE >> 17 ) & 0x01))<< X_PIN  ) ); }
		*/
  		GPIO_CFG_EXTI(E);
	#endif
#endif


	return RES_OK;
}


