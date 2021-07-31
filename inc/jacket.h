// Hardware configuration
#ifndef JACKET_H_
#define JACKET_H_

#include "stdint.h"
#include "main.h"
#include "GPIO_af_F407xx.h"
#include "GPIO_F407xx.h"
#include "stm32f4xx.h"

extern volatile uint32_t mTick;

inline void delay(uint32_t msec ){
	uint32_t startTick  = mTick;
	while ((mTick-startTick)<msec) ;
}

#ifndef UNUSED
#define UNUSED(X) (void)X      /* To avoid gcc/g++ warnings */
#endif

#ifdef __cplusplus
extern "C" {
#endif





#ifdef __cplusplus
}
#endif
#endif //JACKET_H_
