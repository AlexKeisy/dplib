#ifndef __RCC_H
#define __RCC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "dp_errors.h"
#include "GPIO_F4xx.h"
#include "GPIO_af_f4xx.h"


uint32_t RCC_Start(uint32_t aFlashLatency,uint32_t  aPLLN,uint32_t  aPLLM,uint32_t  aAHB,uint32_t  aAPB1,uint32_t  aAPB2);

#define AHB_CLOCK_SPEED     (SystemCoreClock /(0x01UL<< ( ((RCC->CFGR >>RCC_CFGR_HPRE_Pos)& 0x7UL ) + ((RCC->CFGR >>(RCC_CFGR_HPRE_Pos+3))& 0x1UL ) ) ) )
#define APB1_CLOCK_SPEED    (AHB_CLOCK_SPEED /(0x01UL<< ( ((RCC->CFGR >>RCC_CFGR_PPRE1_Pos)& 0x3UL) + ((RCC->CFGR >>(RCC_CFGR_PPRE1_Pos+2))& 0x1UL) ) ) )
#define APB2_CLOCK_SPEED    (AHB_CLOCK_SPEED /(0x01UL<< ( ((RCC->CFGR >>RCC_CFGR_PPRE2_Pos)& 0x3UL) + ((RCC->CFGR >>(RCC_CFGR_PPRE2_Pos+2))& 0x1UL) ) ) )

#ifdef __cplusplus
}
#endif

#endif /* __RCC_H */
