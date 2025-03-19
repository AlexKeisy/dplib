#ifndef FIFO_H_
#define FIFO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifndef __packed
#define __packed __attribute__((__packed__))
#endif


typedef struct FIFO_str FIFO_t,*FIFO_p;

#define   FIFO_DEFAULT_BUFF_SIZE   128

/** 
  * @brief First Input First Output buffer structure 
  */

struct  __packed FIFO_str {
	uint16_t buffSize; /*!< Input             buffSize must be power of 2 (16,32,64...); mask= buffSize-1 */
	uint8_t  flags; /*!< cycle (cycle buffer or not);	generate event`s: evt_char (every Char);evt_half(half buffer);evt_full (buffer is full); evt_complete (reIdx==wrIdx event); */
	uint8_t  state;
	uint16_t reIdx;
	uint16_t wrIdx;
	//FIFO_clbk_t callback;maybe later...
	uint8_t  buff[FIFO_DEFAULT_BUFF_SIZE];
};

/** @defgroup FIFO_flags_define GPIO output type define
  * @brief GPIO Configuration Mode
  * @{
  */
#define FIFO_FLG_CYCLE       1  /*!< Cycle buffer type             */
#define FIFO_FLG_EVT_CHAR    2	/*!< event  for every char, be care may be called from interrupt  */
#define FIFO_FLG_EVT_HALF    4  /*!< event for half buffer              */
#define FIFO_FLG_EVT_FULL    8	/*!< event for full buffer              */
#define FIFO_FLG_EVT_CMPLT   16 /*!< event if read cnt bytes           */
#define FIFO_FLG_EVT_CH1     32 /*!< event if ch1 occurrence              */
#define FIFO_FLG_EVT_CH2     64  /*!< event if ch2 occurrence              */
#define FIFO_FLG_EVT_CH12    128 /*!< event if ch1, ch1 sequence  occurrence              */

/**
  * @}
  */

#define   FIFO_OVERRUN_SHIFT        (FIFO_DEFAULT_BUFF_SIZE /8)


// No options for FIFO_get()
#define   FIFO_GET_OPT_NO           0
// don`t delete read data from the buffer
#define   FIFO_GET_OPT_NO_DEL       1



//initialization
void   FIFO_Init(FIFO_p  hFIFO );

// FIFO_Add return= bytesWritten   or errorCode < 0
int16_t   FIFO_Add     (FIFO_p  hFIFO ,  char *dataPtr, uint16_t cnt );
//
int16_t   FIFO_Get (FIFO_p  hFIFO ,  char *dataPtr, uint16_t cnt ,uint8_t options);
int16_t   FIFO_Del (FIFO_p  hFIFO ,  uint16_t cnt );

#ifdef __cplusplus
}
#endif
#endif /* FIFO_H_ */
