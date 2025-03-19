
#include <fifo.h>
#include <stdint.h>
#include <string.h>
#include "assert.h"

void   FIFO_Init(FIFO_p  hFIFO  ){
	hFIFO->reIdx= 0;
	hFIFO->wrIdx= 0;
}

//
/**
  \brief   FIFO Add cnt bytes pointed by dataPtr into hFIFO buffer
  \details FIFO_Add() modify`s  wrIdx that points area to write
  \param [in]  hFIFO pointer to FIFO buffer structure
  \param [in]  dataPtr pointer to data to Add
  \param [in]  cnt count of elements to Add
 */
int16_t   FIFO_Add     (FIFO_p  hFIFO ,  char *dataPtr, uint16_t cnt ){
	assert_stack();

	//calculate  enough space
	uint16_t bytesToWr;
	if (hFIFO->flags & FIFO_FLG_CYCLE ){
		bytesToWr = (hFIFO->buffSize - (hFIFO->wrIdx - hFIFO->reIdx));
	}else{
		bytesToWr = hFIFO->buffSize - hFIFO->wrIdx ;
	}
	if (bytesToWr>0) {
		if (  bytesToWr >  cnt ){
			bytesToWr =  cnt;
		};
		uint16_t wrPos = hFIFO->wrIdx & (hFIFO->buffSize-1);

		if ( ( wrPos +bytesToWr ) <= (hFIFO->buffSize)){
			// one part data
			memcpy(hFIFO->buff+wrPos,dataPtr,bytesToWr );
		}else{
			// two part data
			uint16_t firstPartSize = hFIFO->buffSize-wrPos ;
			memcpy(hFIFO->buff+wrPos,dataPtr,firstPartSize);
			memcpy(hFIFO->buff,dataPtr+firstPartSize,bytesToWr-firstPartSize );
		}
	    	hFIFO->wrIdx = hFIFO->wrIdx+bytesToWr;
		return bytesToWr;
	}else{
		return 0;
	}

}
// Get can modify reIdx that points data to read
int16_t   FIFO_Get (FIFO_p  hFIFO ,  char *dataPtr, uint16_t cnt ,uint8_t options){
	assert_stack();

	uint8_t fatalOverrun;
	uint16_t bytesRead;
	do {
		fatalOverrun=0;
		bytesRead=hFIFO->wrIdx -hFIFO->reIdx ;
		if (bytesRead==0){
			return 0;// empty buffer nothing to get
		};
		if (bytesRead > hFIFO->buffSize){
			bytesRead = hFIFO->buffSize ;
			hFIFO->reIdx = hFIFO->wrIdx - bytesRead;// point to correct data
		}
		if (bytesRead> cnt){
			bytesRead= cnt;
		};
		uint16_t rePos = hFIFO->reIdx & (hFIFO->buffSize-1);

		if ( ( rePos +bytesRead ) <= (hFIFO->buffSize)){
			// one part data
			memcpy(dataPtr,hFIFO->buff+rePos,bytesRead );
		}else{
			// two part data
			uint16_t firstPartSize = hFIFO->buffSize-rePos ;
			memcpy(dataPtr,hFIFO->buff+rePos,firstPartSize);
			memcpy(dataPtr+firstPartSize,hFIFO->buff,bytesRead-firstPartSize );
		};
		// how many data overrun while we copied
		int16_t bytesOver=(hFIFO->wrIdx -  hFIFO->reIdx) - hFIFO->buffSize ;
		if (bytesOver>0){
			if (bytesOver>=bytesRead){
				//!!! fatal overrun error, no correct data read
				fatalOverrun =1;
			}else{
				memmove(dataPtr,dataPtr+bytesOver,bytesRead -bytesOver );
				//memcpy(dataPtr,dataPtr+bytesOver,bytesRead -bytesOver );
				bytesRead =bytesRead -bytesOver;
			}
		}
	} while (fatalOverrun);
	if (!(options & FIFO_GET_OPT_NO_DEL))  hFIFO->reIdx += bytesRead;
	return bytesRead;
}

int16_t   FIFO_Del (FIFO_p  hFIFO ,  uint16_t cnt ){
	uint16_t bytesDel=hFIFO->wrIdx -hFIFO->reIdx ;
	if (bytesDel==0){
		return 0;// empty buffer
	};
	if (bytesDel> cnt){
		bytesDel= cnt;
	};
	hFIFO->reIdx = hFIFO->reIdx+bytesDel;
	return bytesDel;
}


