
#include <stdint.h>
#include "assert.h"
#include "primitiv.h"


// primitive size by type;
#define PR_LIST_XMACRO(name) sizeof(name##_t),
const uint8_t  prSizes[PR_TYPE_CNT] ={
		prList
};
#undef PR_LIST_XMACRO
