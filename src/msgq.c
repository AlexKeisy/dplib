
#include <msgq.h>
#include <string.h>
#include "assert.h"



uint16_t msgQ_addMsgPtr(msgQ_p queue, msg_p msg){
	assert_param(queue);
	assert_param(msg);
	assert_param(msg->msgTypeGroup);
	assert_stack();
	msg_p slot = msgQ_getEmptySlot( queue);
	if (slot){
		memcpy(slot,msg,sizeof(msg_t));
		return 1;
	};
	return 0;
}
uint16_t msgQ_addMsg(msgQ_p queue, uint8_t aMsgTypeGroup, uint8_t aMsgByte, uint16_t aMsgWord, uint32_t aMsgDword){
	assert_param(queue);
	assert_param(aMsgTypeGroup);
	assert_stack();

	msg_p slot = msgQ_getEmptySlot( queue);
	if (slot){
		slot->msgDword = aMsgDword;
		slot->msgWord = aMsgWord;
		slot->msgByte = aMsgByte;
		slot->msgTypeGroup = aMsgTypeGroup;// copy`d last, indicate complete message
		return 1;
	};
	return 0;

}
uint16_t msgQ_addKb(msgQ_p queue, uint8_t aGroup, uint8_t aKey, uint32_t aKeys){
	assert_param(queue);
	assert_stack();
	msg_p slot = msgQ_getEmptySlot( queue);
	if (slot){
		slot->kbKeys = aKeys;
		slot->kbKey = aKey;
		slot->msgTypeGroup = MSG_TYPE_GROUP(MSG_TYPE_KB,aGroup)  ;// copy`d last, indicate complete message
		return 1;
	};
	return 0;

}
uint16_t msgQ_addPt(msgQ_p queue,uint8_t aGroup, uint16_t aStrength, uint16_t aX, uint16_t aY, uint8_t ptAction){
	assert_param(queue);
	assert_stack();
	msg_p slot = msgQ_getEmptySlot( queue);
	if (slot){
		slot->ptStrength = aStrength;
		slot->ptX = aX;
		slot->ptY = aY;
		slot->ptAction = ptAction;
		slot->msgTypeGroup = MSG_TYPE_GROUP(MSG_TYPE_PT,aGroup)  ;// copy`d last, indicate complete message
		return 1;
	};
	return 0;


}

//get next empty slot, internal function, thread/interrupt safe
//uses sys_cfg.h ENTER_CRITICAL_SECTION & LEAVE_CRITICAL_SECTION macro
msg_p msgQ_getEmptySlot(msgQ_p queue){
	msg_p res =0;
	ENTER_CRITICAL_SECTION(MSG_QUEUE_CRITICAL_SECTION);
	if ((queue->wrIdx-queue->reIdx)<MSG_QUEUE_BUFF_SIZE){
		res= queue->buff  + (queue->wrIdx & MSG_QUEUE_BUFF_MSK) ;
		// increment queue write position
		++queue->wrIdx;
	}
	LEAVE_CRITICAL_SECTION(MSG_QUEUE_CRITICAL_SECTION);
	return res;
}


// copy message data from queue to msg, then mark as unused slot in queue
// not thread safe, call only from one place (thread/ main cycle/etc)
uint16_t  msgQ_get(msgQ_p queue,  msg_p msg){
	assert_param(queue);
	assert_param(msg);
	assert_stack();
	//is there are messages?
	if ( (queue->wrIdx - queue->reIdx)>0 ){
		uint16_t rePos = queue->reIdx & MSG_QUEUE_BUFF_MSK;
		//if queue is full,..
		if ((queue->wrIdx - queue->reIdx)>= MSG_QUEUE_BUFF_SIZE ){
			// & first message to read is  incomplete.
			if ((queue->buff[rePos]).msgTypeGroup==MSG_TYPE_EMPTY){
				//skip them to avoid unlimited cycle
				queue->reIdx =queue->reIdx+1;
				rePos = queue->reIdx & MSG_QUEUE_BUFF_MSK;
				//TODO log this error? or increment skipped msg`s counter
				// this is potential risk for situations like ABA because this space can be filled
				//by previous owner and new owner at same time
			}
		}
		//if message is filled complete
		if ((queue->buff[rePos]).msgTypeGroup){
			memcpy(msg,&(queue->buff[rePos]), sizeof(msg_t));
			(queue->buff[rePos]).msgTypeGroup = MSG_TYPE_EMPTY;
			++queue->reIdx ;
			return 1;
		}

	}
	return 0;
};

