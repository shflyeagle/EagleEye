/***********************************************************************************/
/*!
* @file buffer_manage.h
*
* @brief
*    Fn for buffer management.
*
* Description:
*    Fn for buffer management.
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



#ifndef __BUF_MANAGER_INCLUDE__
#define __BUF_MANAGER_INCLUDE__

//error codes
enum
{//!!! If you change any code, please modify buf_errorFmt synchronously
	BUF_ERR_NO_ERROR,          //0
	BUF_ERR_NULL_PTR,          //1
	BUF_ERR_UNMALLOC_MEMORY,   //2
	BUF_ERR_INVALID_PTR,       //3
	BUF_ERR_SIZE_OUT_RANGE,    //4
	BUF_ERR_OVER_WRITE,        //5
	BUF_WARN_MEMORY_SHORTAGE,  //6
	BUF_ERR_WARNING_NUM
};

#ifdef WIN32
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#define __func__ __FILE__
#define BUF_LOCAL_TIME 0
#elif defined(HOST)
#include "l2_common_types.h"
extern u32 UPA_Main_Cnt;
#define BUF_LOCAL_TIME UPA_Main_Cnt
#else
#include "l2_common_types.h"
extern u32 UPA_Main_Cnt;
#define BUF_LOCAL_TIME UPA_Main_Cnt
#endif


#ifdef __cplusplus
extern "C" {
#endif

	// If switch on,direct buffer is also select automatically according requested size
	// If switch on,no C/N/D buffer conception
	// If switch on,please ensure the size of direct pools are different
#define AUTO_MALLOC_DIRECT_BUFFER         1

	// If switch on, look-up tables will be const table,this will improve robusty but need to preset
#define HARD_CODE_LOOK_UP_TABLE           0

#define MAX_CASCADE_PHY_BUFFER_POOL_NUM   4
#define MAX_DIRECT_BUFFER_POOL_NUM        16
#define MAX_CASCADE_LOG_BUFFER_POOL_NUM   8

	// The unit size order of memory allocated to physical pool,related to loop-up table
#define MEM_RESERVED_GRANULARITY_ORDER   20  //1M Bytes
	// The unit size order of logical memory,related to look-up table
#define MEM_APP_MALLOC_GRANULARITY_ORDER  5  //32 Bytes

	//===========================DON'T CHANGE THE FOLLOWING =================================
#if AUTO_MALLOC_DIRECT_BUFFER == 0
#define DIRECT_BUFFER_ID_TAG 0xABC00000
#define IsDirectBufferWanted(size) (((size)&0xFFF00000)==DIRECT_BUFFER_ID_TAG)
#define DIRECT_BUFFER_ID(size) ((u8)(((size)>>16)&0x0F))
#define DIRECT_BUFFER_WANTED_SIZE(size) ((u16)(size))
#define DIRECT_MALLOC_REGION(size,region)  (DIRECT_BUFFER_ID_TAG|(((u32)region)<<16)|(size))
#else
#define DIRECT_MALLOC_REGION(size,region)  size
#endif

#define BYTE_TO_GRANULARITY(size)  (((size)+(1<<MEM_RESERVED_GRANULARITY_ORDER)-1)>>MEM_RESERVED_GRANULARITY_ORDER)

#define DIRECT_BUF_POOL    0
#define CASECADE_BUF_POOL  1

	typedef struct
	{
		u8 poolType;
		u32 phyBufSizeOrder;
		u32 totalSizeInGranularity;
		u32 logBufPoolMapBitmap;//meaningless for direct pool
	}PhyBufPoolConfig_t;

	typedef const void* BufManHandle_t;

	// !!!!!! App can't call any interfaces with prefix "__" directly
	// !!!!!! Middle level should wrap these interfaces
	// About return value: 
	//    Like standard libraray: most functions return "int" type, error if ret < 0, result if ret>=0
	//


#if HARD_CODE_LOOK_UP_TABLE > 0
	BufManHandle_t __BUF_CreateManager(const PhyBufPoolConfig_t* in_pConfig, const char* in_szName, const u8*offsetToPhyPoolIndex, const u8*sizeToLogPoolIndex);
#else
	BufManHandle_t __BUF_CreateManager(const PhyBufPoolConfig_t* in_pConfig, const char* in_szName);
#endif
	void* __BUF_Malloc(BufManHandle_t in_handle, u32 in_size, const char* in_szFunc, u32 in_paramAndLine, u32 in_tagOwner);
	int  __BUF_Free(BufManHandle_t in_handle, u8* in_ptr, const char* in_szFunc, u32 in_line);


	//================================ Interface for Middle Level ==============================
	// { Basic interface: initialize/malloc/free/query free 
#if HARD_CODE_LOOK_UP_TABLE > 0
#define BUF_CreateManager(in_szName,in_pConfig, offsetToPhyPoolIndex,sizeToLogPoolIndex) __BUF_CreateManager(in_pConfig, in_szName,offsetToPhyPoolIndex,sizeToLogPoolIndex)
#else
#define BUF_CreateManager(in_szName,in_pConfig, offsetToPhyPoolIndex,sizeToLogPoolIndex) __BUF_CreateManager(in_pConfig, in_szName)
#endif

#define __BUF_Alloc(handle,size,tag32,param) __BUF_Malloc(handle,size,__func__, (((u32)(param))<<16)|__LINE__, tag32)

#define __BUF_Dealloc(handle,ptr)  __BUF_Free(handle,(u8*)ptr,__func__,__LINE__)
	//I recommend to use this one because it forces deallacted pointer to NULL
	//#define __BUF_Dealloc(handle,ptr)  if(__BUF_Free(handle,(u8*)ptr,__func__,__LINE__)>=0)(ptr)=NULL


	static  inline void  __BUF_BatchFree(BufManHandle_t in_handle, void** in_out_list, u32 in_num)
	{
		u32 i;
		for (i = 0; i<in_num; i++)
		{
			__BUF_Dealloc(in_handle, (u8*)in_out_list[i]);
			in_out_list[i] = NULL;// Automatically set to NULL
		}
	}
	u32 __BUF_GetFreeBufferNum(BufManHandle_t in_handle, u32 in_size);

	void __BUF_FlushCache(BufManHandle_t in_handle);

	//}

	//{   !!!!!! DON'T Call These Functions In New Code. 
	//    They are out of memory bufferment,APPs should manage by themself.Implement just because of history calling
	u32 __BUF_GetAllocatedBufferSize(BufManHandle_t in_handle, u8* in_ptr, const char* in_szFunc, u32 in_line);
	int __BUF_IncreaseRefer(BufManHandle_t in_handle, u8* in_ptr, const char* in_szFunc, u32 in_line);
	int __BUF_DecreaseRefer(BufManHandle_t in_handle, u8* in_ptr, const char* in_szFunc, u32 in_line);
	u8* __BUF_GetAllocatedBufferBaseAddr(BufManHandle_t in_handle, u8* in_ptr, const char* in_szFunc, u32 in_line);
	void  __BUF_BatchFreeWithAttr(BufManHandle_t in_handle, void** in_out_list, u32 in_num, const u32* in_attr, u32 in_nbAttr, const char* in_szFunc, u32 in_line);
	//}


	//{ diagnose functions
	void __BUF_PrintStatistic(char* out_str, BufManHandle_t in_handle);
	void __BUF_PrintOneBufferAllocInfor(char* out_str, BufManHandle_t in_handle, u8* in_ptr);
	// print allocation information for all buffers, print too much, to be defined
	void __BUF_PrintAllBufferAllocInfor(BufManHandle_t in_handle);
	// print saved error/warngin information, maybe print too much, to be defined
	void __BUF_PrintRuntimeErrorLog(BufManHandle_t in_handle);
	//}

	//{ safeguard fuctions,detect overwriting/memory leak...
	// To be define. 
	// A good architecture is let a daemon thread with lowest priority to do this task periodically
	// If can't add a thread, should split the task into many slices because it takes lone time...
	int __BUF_SanityCheckAndRestore(BufManHandle_t in_handle);
	//}
#ifdef __cplusplus
}
#endif

#endif
