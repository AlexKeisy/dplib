/**
  ******************************************************************************
  * @file    sys_cfg.h
  * @author  AlexKeisy for Few Bytes
  * @brief   message Queue system header File.
  *
  *   This file provides macros to tuning dplib library with system
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

/** @addtogroup  System settings for dplib library
  * @{
  */

#ifndef SYS_CFG_H_
#define SYS_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <cmsis_gcc.h>

#define  MSG_QUEUE_CRITICAL_SECTION 0

#define  ENTER_CRITICAL_SECTION(SECTION_ID)  __disable_irq()
#define  LEAVE_CRITICAL_SECTION(SECTION_ID)  __enable_irq()






#ifdef __cplusplus
}
#endif
#endif /* SYS_CFG_H_ */

