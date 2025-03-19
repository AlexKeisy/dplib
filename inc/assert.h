#ifndef ASSERT_H_
#define ASSERT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT
/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr If expr is false, it calls assert_failed function
  *         which reports the name of the source file and the source
  *         line number of the call that failed.
  *         If expr is true, it returns no value.
  * @retval None
  */
#ifndef assert_param
// to avoid problems with STm HAL library
#define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
void assert_failed(uint8_t* file, uint32_t line);
#endif //assert_param
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

#ifdef  USE_STACK_ASSERT
/**
  * @brief  The assert_stack macro is used for stack size check.
  * @retval None
  */

extern volatile uint32_t stackMin;   /*!< External variable to save top of stack, !stack grows down*/
extern uint8_t* stackFile;   /*!< External variable to save file where have top of stack, */
extern uint32_t stackLine;	/*!< External variable to save file line where have top of stack, */
extern uint32_t _ebss;

extern uint32_t _estack  ;
extern uint32_t _Min_Stack_Ptr ;  /*!< !!!must be declared in linker script  */



register uint32_t stack_ptr asm("sp");

void __assert_stack(uint8_t * f, uint32_t l);
#define ASSERT_STACK_SIGN    0xA5A5F0F0
#define init_assert_stack()   _Min_Stack_Ptr = ASSERT_STACK_SIGN;

#define assert_stack()   __assert_stack((uint8_t *)__FILE__, __LINE__)

#else
#define assert_stack() ((void)0U)
#endif /* USE_STACK_ASSERT */



#ifdef __cplusplus
}
#endif
#endif /* ASSERT_H_ */
