/*
 * rcc.c
 *
 *  Created on: 30 окт. 2021 г.
 *      Author: AlexKeisy
 *
 *  /details System Timer initialization routines
 */
#include <rcc.h>

uint32_t RCC_Start(uint32_t aFlashLatency,uint32_t  aPLLN,uint32_t  aPLLM,uint32_t  aAHB,uint32_t  aAPB1,uint32_t  aAPB2){
	volatile uint32_t i;
	uint32_t Tmp_Reg;

	SET_BIT(RCC->APB2ENR ,RCC_APB2ENR_SYSCFGEN);
	SET_BIT(RCC->APB1ENR ,RCC_APB1ENR_PWREN);

	// HSE ON
	SET_BIT(RCC->CR ,RCC_CR_HSEON);
	i=0;
	// wait for HSE ON
	while  ((RCC->CR & RCC_CR_HSERDY_Msk)==0) {
		i++;
		if (i>1000000) return RES_FAULT; //no Success to HSE ON
	}
	//have hard fault if already unlocked
	if ((FLASH->CR & FLASH_CR_LOCK_Msk)){
		FLASH->KEYR = 0x45670123U; // if flash lock, then magic unlock
		FLASH->KEYR = 0xCDEF89ABU;
	}
	Tmp_Reg = FLASH_ACR_DCEN | FLASH_ACR_ICEN | FLASH_ACR_PRFTEN | aFlashLatency;
	MODIFY_REG(FLASH->ACR , FLASH_ACR_DCEN_Msk | FLASH_ACR_ICEN_Msk | FLASH_ACR_PRFTEN_Msk| FLASH_ACR_LATENCY_Msk  ,Tmp_Reg);

	// !!! It`s need to off PLL
	CLEAR_BIT( RCC->CR, RCC_CR_PLLON);
	// wait for PLL OFF
	while  ((RCC->CR & RCC_CR_PLLRDY_Msk)>0) {
		i++;
		if (i>1000000) 	return (RES_FAULT); //no Success to PLL OFF
	}

	Tmp_Reg = ( 4U << RCC_PLLCFGR_PLLQ_Pos)	| RCC_PLLCFGR_PLLSRC_HSE|( aPLLN << RCC_PLLCFGR_PLLN_Pos)|( aPLLM << RCC_PLLCFGR_PLLM_Pos);
	/*PLLP =0 (/2) RCC_PLLCFGR_PLLP_Pos*/

	MODIFY_REG(RCC->PLLCFGR,RCC_PLLCFGR_PLLQ_Msk|RCC_PLLCFGR_PLLSRC_Msk|RCC_PLLCFGR_PLLP_Msk|RCC_PLLCFGR_PLLN_Msk|RCC_PLLCFGR_PLLM_Msk,Tmp_Reg);

	// PLL ON
	SET_BIT(RCC->CR ,RCC_CR_PLLON);
	i=0;
	// wait for PLL ON
	while  ((RCC->CR & RCC_CR_PLLRDY_Msk)==0) {
		i++;
		if (i>1000000) {
			return RES_FAULT; //no Success to PLL ON
		}
	}

	// set prescaler`s for AHB,APB1,APB2 and  change RCC source to PLL
	MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE_Msk | RCC_CFGR_PPRE2_Msk|RCC_CFGR_PPRE1_Msk | RCC_CFGR_SW_Msk,
			aAHB | aAPB1| aAPB2| RCC_CFGR_SW_PLL);
	i=0;
	while (i<100){
		i++;


		if (RCC->CFGR & RCC_CFGR_SWS_PLL ){
		   return RES_OK;
		}
	}
	return RES_FAULT;
}

