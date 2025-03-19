/*
 * USART_F4xx.h
 *
 *  Created on: 31 окт. 2021 г.
 *      Author: AlexKeisy for Few Bytes Software
 */
#include "USART_F4xx.h"
#include "dp_errors.h"
#include "GPIO_F4xx.h"
#include "GPIO_af_f4xx.h"
#include "rcc.h"


uint32_t UART_Init(USART_TypeDef * hUSART,uint32_t aBaudRate, hpin TxPin, hpin RxPin , int8_t over8){
	uint8_t af =0;
	uint32_t clockSpeed =0;
	if (( (uint32_t)hUSART & APB2PERIPH_BASE)==APB2PERIPH_BASE){
		clockSpeed = APB2_CLOCK_SPEED;
		if (hUSART==USART1){
			SET_BIT(RCC->APB2ENR,RCC_APB2ENR_USART1EN);
			af= PIN_AF_USART1;
		}
		#ifdef USART6
		if (hUSART==USART6){
			SET_BIT(RCC->APB2ENR,RCC_APB2ENR_USART6EN);
			af= PIN_AF_USART6;
		}
		#endif
	}else{
		clockSpeed = APB1_CLOCK_SPEED;
		if (hUSART==USART2){
			SET_BIT(RCC->APB1ENR,RCC_APB1ENR_USART2EN);
			af= PIN_AF_USART2;
		}
		#ifdef USART3
		if (hUSART==USART3){
			SET_BIT(RCC->APB1ENR,RCC_APB1ENR_USART3EN);
			af= PIN_AF_USART3;
		}
		#endif
		#ifdef UART4
		if (hUSART==UART4){
			SET_BIT(RCC->APB1ENR,RCC_APB1ENR_UART4EN);
			af= PIN_AF_UART4;
		}
		#endif
		#ifdef UART5
		if (hUSART==UART5){
			SET_BIT(RCC->APB1ENR,RCC_APB1ENR_UART5EN);
			af= PIN_AF_UART5;
		}
		#endif
	}
	if (af==0){
		return RES_FAULT;
	}

	pinInitAF(TxPin, GPIO_OTYPE_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_VERY_HIGH, af );
	pinInitAF(RxPin, GPIO_OTYPE_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_VERY_HIGH, af );

	if (over8){
		hUSART->CR1 |= USART_CR1_OVER8 | USART_CR1_TE | USART_CR1_RE ;
	}else {
		hUSART->CR1 =   USART_CR1_TE | USART_CR1_RE ;
	}
	(void)hUSART->CR1;

	clockSpeed=clockSpeed / aBaudRate;
	if (over8){
		//tree bits is fraction others is Mantissa
		clockSpeed = ((clockSpeed << 1U) & 0xfffffff0UL) | ( clockSpeed  & 0x07 );
	}
	hUSART->BRR =  clockSpeed;
	(void)hUSART->BRR;
	hUSART->CR2=0;
	hUSART->CR3=0;
	hUSART->CR1 |= USART_CR1_UE ;
	return RES_OK;

}
