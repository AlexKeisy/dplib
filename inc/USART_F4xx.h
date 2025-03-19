#ifndef USART_F4XX_H_
#define USART_F4XX_H_

#include "dp_errors.h"
#include "GPIO_F4xx.h"
#include "GPIO_af_f4xx.h"

uint32_t UART_Init(USART_TypeDef * hUSART,uint32_t aBaudRate, hpin TxPin, hpin RxPin, int8_t over8 );

#ifdef __cplusplus
extern "C" {
#endif





#ifdef __cplusplus
}
#endif
#endif /* USART_F4XX_H_ */
