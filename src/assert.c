#include "assert.h"


#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line){
	while (1)  {};
}

#endif /* USE_FULL_ASSERT */


#ifdef  USE_STACK_ASSERT

volatile uint32_t stackMin=0xFFFFFFFF;
uint8_t* stackFile;
uint32_t stackLine;


void __assert_stack(uint8_t * f, uint32_t l){
	uint32_t __cS__= stack_ptr;
	if (stackMin> __cS__){
		//!!! if an interrupt will occur in this place, stackMin,stackFile,stackLine can be incorrect (but this is not  a problem ;)
		//fix minimal stack position
		stackMin= __cS__;
		stackFile = f;
		stackLine = l;
		//!!! need to disable interrupts 
		if(((uint32_t)&_Min_Stack_Ptr)>=__cS__) {
			//if out of stack
			while (1)  {};
		}
		if (_Min_Stack_Ptr!=ASSERT_STACK_SIGN){
			//if stack sign was corrupted
			while (1)  {};
		}
  	};
}


#endif /* USE_STACK_ASSERT */
