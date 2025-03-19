/**
  ******************************************************************************
  * @file    msgQ.h
  * @author  AlexKeisy for Few Bytes
  * @brief   message Queue system header File.
  *
  *   This file provides macros for message exg
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

/** @addtogroup  Message_control
  * @{
  */



#ifndef MSGQ_H_
#define MSGQ_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <sys_cfg.h>

#ifndef __packed
#define __packed __attribute__((__packed__))
#endif

#define   MSG_TYPE_EMPTY      0

#define   MSG_TYPE_MSG      1
#define   MSG_TYPE_KB       2
#define   MSG_TYPE_PT       3


#define   MSG_TYPE_BITS   5
#define   MSG_TYPE_MASK   0x1F
#define   MSG_GROUP_MASK  0xE0

#define  MSG_TYPE_GROUP(_TYPE, _GROUP)   ((_GROUP<<MSG_TYPE_BITS) | _TYPE)
#define  MSG_TYPE(_TYPE_GROUP)   (_TYPE_GROUP & MSG_TYPE_MASK)
#define  MSG_GROUP(_TYPE_GROUP)   ((_TYPE_GROUP & MSG_GROUP_MASK)>>MSG_TYPE_BITS)

/** @addtogroup  Message structure
  * @{
  *
  * @brief Message structure
  * msgXXX message specific field`s
  * kbXXX  keyboard specific field`s
  * ptXXX  point device specific field`s
  */

typedef struct  __packed  {
	union {
		uint32_t msgDword;
		uint32_t kbKeys;/*!< four common pressed keys, order not specified*/
		struct {
			uint16_t ptX;
			uint16_t ptY;
		};
	};
	union {
		uint16_t msgWord;
		uint16_t ptStrength;
	};
	union {
		uint8_t  msgByte;
		uint8_t  kbKey; /*!< latest pressed */
		uint8_t  ptAction; /*!< point device move/down/up/ left key/right key/*/
	};
	// note: specially last field in structure, nonzero value indicates complete filled message, set/copy this field latest
	union{
		uint8_t msgTypeGroup;
	};
} msg_t, *msg_p;

/**
  * @brief Message buffer structure size
  * MSG_QUEUE_BUFF_SIZE must be power of 2 eg 4,8,16,32,64...
  */

#ifndef   MSG_QUEUE_BUFF_SIZE
#define   MSG_QUEUE_BUFF_SIZE   32
#endif
#define   MSG_QUEUE_BUFF_MSK    (MSG_QUEUE_BUFF_SIZE-1)


/**
  * @brief Message buffer structure
  */

typedef struct  __packed  {
	uint16_t reIdx;
	uint16_t wrIdx;
	msg_t  buff[MSG_QUEUE_BUFF_SIZE];
} msgQ_t, * msgQ_p;

//addXxx function`s is thread/interrupt safe
uint16_t msgQ_addMsgPtr(msgQ_p queue, msg_p msg);
uint16_t msgQ_addMsg(msgQ_p queue, uint8_t aMsgTypeGroup, uint8_t aMsgByte, uint16_t aMsgWord, uint32_t aMsgDword);
uint16_t msgQ_addKb(msgQ_p queue,uint8_t aGroup, uint8_t aKey, uint32_t aKeys);
uint16_t msgQ_addPt(msgQ_p queue,uint8_t aGroup, uint16_t aStrength, uint16_t aX, uint16_t aY, uint8_t ptAction);

//get next empty slot, internal function, thread/interrupt safe
//uses sys_cfg.h ENTER_CRITICAL_SECTION & LEAVE_CRITICAL_SECTION macro
msg_p msgQ_getEmptySlot(msgQ_p queue);


// copy message data from queue to msg, then then mark as unused slot in queue
uint16_t  msgQ_get(msgQ_p queue,  msg_p msg);

#ifdef __cplusplus
}
#endif
#endif /* MSGQ_H_ */
