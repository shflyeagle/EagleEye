/***********************************************************************************/
/*!
* @file buffer_manage_hal.h
*
* @brief
*    define platform dependency interfaces needed by buffer management.
*    Hardware abstraction level, eliminate platform difference
* Description:
*
*
* Content :
*
*
*
*
* @section history_sec History
* @code
|----------------|-----------------------------------------|-----------|----------|
|   Name         |         Description                     |   Date    | Version  |
|----------------|-----------------------------------------|-----------|----------|
| yuquanz        | Creation                                | JULY-1-14 | NO VER   |
* @endcode
*/

#ifndef __BUFFER_MANAGER_AL_INCLUDE__
#define __BUFFER_MANAGER_AL_INCLUDE__


#define ADDR_2_U32(ptr)  ((const char*)(ptr)-(const char*)0)


// Trace & Debug
#ifdef WIN32
#include <stdio.h>
#define BUF_BUG   printf //print bug/warning
#define BUF_TRACE printf //print normal log

#define BUF_ASSERT(exp)  do{if(!(exp)){printf("error:" #exp);for(;;);}}while(0)

#define BUF_ASSERT_DBG(exp) do\
{\
if (!(exp)){printf("error: " #exp); \
while (1);}\
}while (0)

#elif defined(HOST)
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#define BUF_BUG printf    //print bug/warning
#define BUF_TRACE printf  //print normal trace
#define BUF_ASSERT(exp) do{if(!(exp)){BUF_BUG("error:" #exp);*(int*)0 = 0;}}while(0)
#define BUF_ASSERT_DBG(exp) do{if(!(exp)){BUF_BUG("error:" #exp);*(int*)0 = 0;}}while(0)

#else
#include <memory.h>
#include <stdarg.h>
#include <stdio.h>
#include "design_traces.h"
//#include "UPA_ASSERT.h"
extern void BUF_Assert_Error(const char* szFile, int line);
static inline void buf_printf(const char*fmt, ...)
{
	char str[0x200];
	va_list args;
	va_start(args, fmt);
	vsprintf(str, fmt, args);
	CT_PRINTF(CT_SYSTR, str, 0, 0, 0, 0, 0, 0, 0);
}
#define BUF_BUG   buf_printf//print bug/warning
#define BUF_TRACE(...) (void)0//print normal trace
#define BUF_ASSERT(exp)  if(!(exp)){buf_printf(#exp);BUF_Assert_Error(__FILE__,__LINE__);}
#define BUF_ASSERT_DBG(exp)  if(!(exp)){buf_printf(#exp);BUF_Assert_Error(__FILE__,__LINE__);}
#endif

// atomic operations
#ifdef WIN32

#define ATOMIC_DEC(ptr) (--(*ptr))
#define ATOMIC_INC(ptr) (++(*ptr))
#define ATOMIC_ADD(ptr,var) (*(ptr) += var)
#define ATOMIC_SUB(ptr,var) (*(ptr) -= var)
#define ATOMIC_DEC_AND_FETCH(ptr) ATOMIC_DEC(ptr)
#define ATOMIC_FETCH_AND_INC(ptr) ((*(ptr))++)
inline u32 ATOMIC_FETCH_AND_CLR(u32* ptr)
{
	u32 prev = *ptr;
	*ptr = 0;
	return prev;
}
#define ATOMIC_COMPARE_AND_SET(ptr, compareVal,newVal) (*(ptr)==(compareVal)? (*(ptr)=(newVal),1):0)

#elif defined(HOST)
#include <pthread.h>   
#include <atomic.h>
#define ATOMIC_DEC(ptr) atomic_dec_32(ptr)//(*(ptr) -= var)//(--(*ptr))
#define ATOMIC_INC(ptr) atomic_inc_32(ptr)
#define ATOMIC_ADD(ptr,delta) atomic_add_32(ptr,delta)
#define ATOMIC_SUB(ptr,delta)   atomic_sub_32(ptr,delta)
#define ATOMIC_DEC_AND_FETCH(ptr) atomic_dec_32_nv(ptr)
#define ATOMIC_FETCH_AND_INC(ptr) (atomic_add_32_nv(ptr,1)-1)
#define ATOMIC_FETCH_AND_CLR(ptr) atomic_swap_32(ptr,0)
#define ATOMIC_COMPARE_AND_SET(ptr, compareVal,newVal) (ADDR_2_U32(compareVal) == atomic_cas_32((volatile u32*)(ptr),ADDR_2_U32(compareVal), ADDR_2_U32(newVal)))
#else //TARGET 
#include "hlxbase/lxbase_atomic.h"
#define ATOMIC_DEC(ptr) lxb_atomic_sub_and_fetch_ui(ptr,1)
#define ATOMIC_INC(ptr) lxb_atomic_add_and_fetch_ui(ptr,1)
#define ATOMIC_ADD(ptr,delta) lxb_atomic_add_and_fetch_ui(ptr,delta)
#define ATOMIC_SUB(ptr,delta) lxb_atomic_sub_and_fetch_ui(ptr,delta)
#define ATOMIC_DEC_AND_FETCH(ptr) lxb_atomic_sub_and_fetch_ui(ptr,1)
#define ATOMIC_FETCH_AND_INC(ptr) lxb_atomic_fetch_and_add_ui(ptr,1)
#define ATOMIC_FETCH_AND_CLR(ptr) lxb_atomic_fetch_and_set_ui(ptr,0)
#define ATOMIC_COMPARE_AND_SET(ptr, compareVal,newVal) lxb_atomic_cas((volatile u32*)(ptr),ADDR_2_U32(compareVal), ADDR_2_U32(newVal))
#endif

// per-thread variable
#ifdef WIN32
typedef u32* PerThreadKey_t;
#define GET_CUR_THREAD_VAR(key)  *(key)
#define SET_CUR_THREAD_VAR(key,var)  *(key)=(u32)(var)
#define CREATE_PER_THREAD_KEY(saveKey) do\
{\
	saveKey = (u32*)MALLOC(sizeof(u32)); \
	saveKey[0] = 0; \
}while (0)
#else
#include <pthread.h>
typedef pthread_key_t PerThreadKey_t;
#define GET_CUR_THREAD_VAR(key)  pthread_getspecific(key)
#define SET_CUR_THREAD_VAR(key,var)  pthread_setspecific(key, var)
#define CREATE_PER_THREAD_KEY(saveKey) pthread_key_create(&saveKey,NULL)
#endif

// lock
#ifdef WIN32
typedef u32 ThreadLock_t;
#define THREAD_LOCK_INIT(pLock) *(pLock) = 0
#define THREAD_LOCK(pLock) (*(pLock))++
#define THREAD_UNLOCK(pLock) *(pLock) = 0
#else
typedef pthread_mutex_t ThreadLock_t;
#define THREAD_LOCK_INIT(pLock) pthread_mutex_init(pLock,NULL)
#define THREAD_LOCK(pLock) pthread_mutex_lock(pLock)
#define THREAD_UNLOCK(pLock) pthread_mutex_unlock(pLock)
#endif

#ifndef MALLOC
#define MALLOC malloc
#endif

#ifndef FREE
#define FREE free
#endif

#ifndef MEMSET
#define MEMSET memset
#endif

#endif//__BUFFER_MANAGER_AL_INCLUDE__

