#ifndef __PRIMITIV_H
#define __PRIMITIV_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __packed
#define __packed __attribute__((__packed__))
#endif

#include <stdint.h>


#define PR_GET_TYPE (_PR)  (((prSys_t)_PR).T)
//type is known for caller , parameters unpacking now
#define PR_2_SYS (_PR,  _ADDR) do{\
	_ADDR=((prSys_t)_PR).shrtAddres;\
};
#define PR_2_PIXEL (_PR, _XD, _X, _YD , _Y, _PAL) do{\
	_XD =((prPix_t)_PR).XD;\
	_X  =((prPix_t)_PR).X; \
	_YD =((prPix_t)_PR).YD;\
	_Y  =((prPix_t)_PR).Y; \
	_PAL=((prPix_t)_PR).P; \
};

// be care do not use these types and structures outside of PR_2_XXX macros!!!

// type to examine type of the  record, not in list, has`nt type_Id
typedef  struct __packed  {
	union{
		uint8_t  TT;
		struct {
			uint8_t  T :5;
			uint8_t  reserved :3;
		};
	};
}prType_t,*prType_p;


// type:5bit/ and 3 bit short address to call primitive set registered in special set?
typedef  struct __packed  {
	union{
		uint8_t  TT;
		struct {
			uint8_t  T :5;
			uint8_t  shrtAddres :3;
		};
	};
}prSys_t,*prSys_p;

// End of sequence
typedef  struct __packed  {
	union{
		uint8_t  TT;
		struct {
			uint8_t  T :5;
			uint8_t  reserved :3;
		};
	};
}prEOS_t,*prEOS_p;

// type:5bit/x direction 1 bit /x:10bit/palette:5bit/ direction 1 bit/y:10bit is packed into uint32
// first byte must be type-byte, because not all type records has more than one byte,
// if machine bytes/Words organized by other way please make it correct

//Pixel with color from palette
typedef struct  __packed  {
	union{
		uint16_t T_X;
		struct {
			uint16_t T : 5;
			uint16_t XD: 1;
			uint16_t X :10;
		};
	};
	union{
		uint16_t P_Y;
		struct {
			uint16_t P : 5;
			uint16_t YD: 1;
			uint16_t Y :10;
		};
	};
} prPix_t, * prPix_p;

// pixel with color
typedef  struct __packed  {
	union{
		uint16_t T_X;
		struct {
			uint16_t T : 5;
			uint16_t XD: 1;
			uint16_t X :10;
		};
	};
	union{
		uint16_t P_Y;
		struct {
			uint16_t P : 5;
			uint16_t YD: 1;
			uint16_t Y :10;
		};
	};
	uint16_t color;
} prPixColor_t, * prPixColor_p;

// filled rectangle with color from palette
typedef struct  __packed  {
	union{
		uint16_t T_X;
		struct {
			uint16_t T : 5;
			uint16_t XD: 1;
			uint16_t X :10;
		};
	};
	union{
		uint16_t P_Y;
		struct {
			uint16_t P : 5;
			uint16_t YD: 1;
			uint16_t Y :10;
		};
	};
	union{
		uint16_t Res_X2;
		struct {
			uint16_t Res01 : 5;
			uint16_t XD2: 1;
			uint16_t X2 :10;
		};
	};
	union{
		uint16_t Res_Y2;
		struct {
			uint16_t Res02 : 5;
			uint16_t YD2: 1;
			uint16_t Y2 :10;
		};
	};
} prRectFill_t, * prRectFill_p;

// filled rectangle with color
typedef struct  __packed  {
	union{
		uint16_t T_X;
		struct {
			uint16_t T : 5;
			uint16_t XD: 1;
			uint16_t X :10;
		};
	};
	union{
		uint16_t P_Y;
		struct {
			uint16_t P : 5;
			uint16_t YD: 1;
			uint16_t Y :10;
		};
	};
	union{
		uint16_t Res_X2;
		struct {
			uint16_t Res01 : 5;
			uint16_t XD2: 1;
			uint16_t X2 :10;
		};
	};
	union{
		uint16_t Res_Y2;
		struct {
			uint16_t Res02 : 5;
			uint16_t YD2: 1;
			uint16_t Y2 :10;
		};
	};
	uint16_t Color;
} prRectFillColor_t, * prRectFillColor_p;

// image internal/external
typedef struct  __packed  {
	union{
		uint16_t T_X;
		struct {
			uint16_t T : 5;
			uint16_t XD: 1;
			uint16_t X :10;
		};
	};
	union{
		uint16_t P_Y;
		struct {
			uint16_t P : 5;
			uint16_t YD: 1;
			uint16_t Y :10;
		};
	};
	union{
		uint16_t Res_X2;
		struct {
			uint16_t Res01 : 5;
			uint16_t XD2: 1;
			uint16_t X2 :10;
		};
	};
	union{
		uint16_t Res_Y2;
		struct {
			uint16_t Res02 : 5;
			uint16_t YD2: 1;
			uint16_t Y2 :10;
		};
	};
	uint32_t ImgAddr;
} prImage_t, * prImage_p;

// Alpha numeric symbol  up to 2 char (ch2 =#0 if not used), X up to 64, Y up to 32
typedef struct  __packed  {
	union{
		uint16_t T_X_Y;
		struct {
			uint16_t T : 5;
			uint16_t X : 6;
			uint16_t Y : 5;
		};
	};
	uint8_t ch1,ch2;
} prAlpha2_t, * prAlpha2_p;

#define prList \
	PR_LIST_XMACRO(prSys)\
	PR_LIST_XMACRO(prEOS)\
	PR_LIST_XMACRO(prPix)\
	PR_LIST_XMACRO(prPixColor)\
	PR_LIST_XMACRO(prRectFill)\
	PR_LIST_XMACRO(prRectFillColor)\
	PR_LIST_XMACRO(prImage)\
	PR_LIST_XMACRO(prAlpha2)

// Enum type Id`s
#define PR_LIST_XMACRO(name) name##_Id,

enum prTypeId {
	prList
	prMax_Id
};
#undef PR_LIST_XMACRO

#define  PR_TYPE_CNT   prMax_Id

extern const uint8_t  prSizes[PR_TYPE_CNT] ;

#ifdef __cplusplus
}
#endif

#endif /* __PRIMITIV_H */
