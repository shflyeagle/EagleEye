/***********************************************************************************/
/*!
* @file buffer_manage_internal.h
*
* @brief
*    Fn for buffer management.
*
* Description:
*    Don't include in any other files,just for buffer management interally
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

#ifndef __BUFFER_MANAGER_INTERNAL_INCLUDE__
#define __BUFFER_MANAGER_INTERNAL_INCLUDE__

#include "buffer_manage.h"
#include "buffer_manage_hal.h"

#define TRY_BEST_MALLOC          0

#define THREAD_LOCK_ENABLE         1
// Turn on to help to decide how much memory need
// Off is recommended for site version
#define DETECT_MAX_MEMORY_COST   1

#define DETECT_ALLOC_FREQUENCE   1

// Both direct/cascade pool support cache.Cache is thread private.
#define SUPPORT_PER_THREAD_CACHE 1
#define SUPPORT_DIRECT_POOL_CACHE_LINE 1

// If switch on, magic words will be put before & behind the allocated part to detect overwriting
// It consts extra 8 bytes. 
// To avoid memory capacity decrease when enable,only pad magic words if remain space is enough
#define SUPPORT_OVERWRITE_CHECK  1

// If switch on, log errors and warnings, 
#define LOG_ERROR_AND_WARNING    1
#define LOG_DEPTH              128
// If switch on, print error/warning when happen
#define REALTIME_PRINT_ERROR_WARNING  1

#define MAX_CACHE_STACK_NUM 128
// If the free buffer number in cache reaches MAX_WATER_LEVEL,decrease cache to MIN_WATER_LEVEL
#define MAX_DIRECT_BUFFER_CACHE_NUM 128
#define DIRECT_POOL_CACHE_DEFAULT_MAX_WATER_LEVEL 128
#define DIRECT_POOL_CACHE_DEFAULT_RELEASE_WATER_LEVEL  120
#define DIRECT_POOL_CACHE_DEFAULT_RELOAD_WATER_LEVEL 32
#if MAX_DIRECT_BUFFER_CACHE_NUM>MAX_CACHE_STACK_NUM || \
	DIRECT_POOL_CACHE_DEFAULT_MAX_WATER_LEVEL > MAX_DIRECT_BUFFER_CACHE_NUM
#error Please Check Config
#endif

#define MAX_CASCADE_BUFFER_CACHE_NUM 64
#define CASCADE_POOL_CACHE_DEFAULT_MAX_WATER_LEVEL 64
#define CASCADE_POOL_CACHE_DEFAULT_RELEASE_WATER_LEVEL 56
#define CASCADE_POOL_CACHE_DEFAULT_RELOAD_WATER_LEVEL 8
#if MAX_CASCADE_BUFFER_CACHE_NUM>MAX_CACHE_STACK_NUM || \
	CASCADE_POOL_CACHE_DEFAULT_MAX_WATER_LEVEL > MAX_CASCADE_BUFFER_CACHE_NUM
#error Please Check Config
#endif


#define MAX_SUPPORT_THREAD_NUM 16
//---------------DON'T CHANGE THE FOLLOWING UNLESS YOU REALLY KNOW WHAT YOU DO---------
#if LOG_ERROR_AND_WARNING > 0
#if LOG_DEPTH&(LOG_DEPTH-1)
#error LOG_DEPTH must be the power of 2
#endif
#endif

#if SUPPORT_DIRECT_POOL_CACHE_LINE > 0
#if SUPPORT_PER_THREAD_CACHE == 0 || THREAD_LOCK_ENABLE == 0
#error Must turn on cache when using cache line
#endif
#endif

#define MEM_RESERVED_GRANULARITY (1<<MEM_RESERVED_GRANULARITY_ORDER)
#define BYTE_TO_MEM_RESERVED_GRANULARITY(size) (((size)+MEM_RESERVED_GRANULARITY-1)>>MEM_RESERVED_GRANULARITY_ORDER)

#define LIST_NODE_DEF   struct slist_node node;
#define DLIST_NODE_DEF  struct dlist_node node;
#define THREAD_LOCK_DEF   ThreadLock_t lock;


#if SUPPORT_PER_THREAD_CACHE > 0
#define PER_THREAD_KEY_DEF PerThreadKey_t threadKey;
#define ATTACH_PER_THREAD_KEY_FOR_CACHE(pObj) CREATE_PER_THREAD_KEY((pObj)->threadKey)
#else
#define PER_THREAD_KEY_DEF
#define ATTACH_PER_THREAD_KEY_FOR_CACHE(pObj) (void)0
#endif

#define PER_THREAD_KEY(pObj) ((pObj)->threadKey)
#define NODE_OF_LIST(pObject) ((struct slist_node*)&((pObject)->node))
#define NODE_OF_DLIST(pObject)((struct dlist_node*)&((pObject)->node))
#define TRANS(type, ptr)   (type*)((const char*)(ptr) - (const char*)0)

struct slist_node
{
	struct slist_node* next;
};
struct dlist_node
{
	struct dlist_node* next;
	struct dlist_node* prev;
};
typedef struct
{
	void* ptrStack[MAX_CACHE_STACK_NUM];
	u32 top;
	u32 preLoadWaterLevel;
	u32 maxWaterLevel;
	u32 releaseWaterLevel;
}BufferCache_t;

//Ensure sizeof(MemoryAllocInfor_t) is the power of 2
typedef struct
{
	LIST_NODE_DEF  //Disable to refer directly. 
	//Don't doublt my intelligence.
	//MACRO make editor blind,there will be no tips of this field.
	u8* buffer;
	u32 referCount;
	u32 time;
	u32 tagOwner;
	u32 paramAndLine;
	const char* szFuncName;
	u16 size;
	u16 reserved;
}MemoryAllocInfor_t;


struct CascadeLogBufPool_s;
typedef struct
{
#if THREAD_LOCK_ENABLE > 0
	DLIST_NODE_DEF
	u32 freeBitmap;
#else
	LIST_NODE_DEF
	u32 referCount;
#endif

	u32 time;
	struct CascadeLogBufPool_s* pLogBufPool;
	MemoryAllocInfor_t* pCascadeBuffer;
	void* buffer;
	u32 reserved[2];
}CascadePhyBufContext_t;

typedef struct
{
	struct slist_node* freeListHead;
	u8* bufBaseAddr;
	u8* bufLimitAddr;
	u8 minCascadeBufSizeOrder;
	u8 perBufSizeOrder;
	u32 perBufAddrMask; //
	CascadePhyBufContext_t* pPhyBufMeta;
	MemoryAllocInfor_t * pLogBufMeta;
	u32 freeBufferCount;
	u32 totalBufferCount;
#if DETECT_MAX_MEMORY_COST  > 0
	u32 minFreeBufferCount;
#endif
}CascadePhyBufPool_t;

typedef struct CascadeLogBufPool_s
{
	PER_THREAD_KEY_DEF
#if THREAD_LOCK_ENABLE > 0
	THREAD_LOCK_DEF
	struct dlist_node* freeListHead;
	u32 fullMask;
#else
	struct slist_node* freeListHead;
#endif
	CascadePhyBufPool_t * pPhyBufPool;
	u32 freeBufferCount;
	u32 perBufferSize;
	u8 perBufSizeOrder;
	u8 nbLogBufPerPhyBuf;
	u8 metaStep;

#if DETECT_ALLOC_FREQUENCE  > 0
	u32 callCount;
	u32 cacheMissCount;
#endif
}CascadeLogBufPool_t;

typedef struct
{
	LIST_NODE_DEF
	void* data[1];//Not 1,variable size
}CacheLine_t;
#define CACHE_LINE_HEAD_SIZE ((char*)(((CacheLine_t*)0)->data) - (char*)0)

typedef struct
{
	PER_THREAD_KEY_DEF
#if SUPPORT_DIRECT_POOL_CACHE_LINE > 0
	THREAD_LOCK_DEF
	MemoryAllocInfor_t ** freeArray;
#else
	struct slist_node* freeListHead;
#endif
	u8* bufBaseAddr;
	u8* bufLimitAddr;
	MemoryAllocInfor_t *metaArray;
	u16 perBufSizeOrder;
	u32 bufTotalCount;
	u32 freeBufCount;

#if DETECT_MAX_MEMORY_COST  > 0
	u32 minFreeBufferCount;
#endif

#if DETECT_ALLOC_FREQUENCE  > 0
	u32 callCount;
	u32 cacheMissCount;
#endif
}DirectBufPool_t;

typedef struct
{
	const char* szBufFunc;
	const char* szCaller;
	u16 line;
	s16 error;
	u32 param;
}BufErrorLog;

typedef struct
{
	char szName[8];
	u8* pPhyBufBaseAddr;
	u8* pPhyBufLimitAddr;
	u8 directPoolNum;
	u8 cascadeLogPoolNum;
	u8 cascadePhyPoolNum;
	DirectBufPool_t directPool[MAX_DIRECT_BUFFER_POOL_NUM];
	CascadeLogBufPool_t cascadeLogPool[MAX_CASCADE_LOG_BUFFER_POOL_NUM];
	CascadePhyBufPool_t cascadePhyPool[MAX_CASCADE_PHY_BUFFER_POOL_NUM];
	const u8*sizeToLogPoolIndex;
	const u8*offsetToPhyPoolIndex;
	u32 maxBufferSize;
#if LOG_ERROR_AND_WARNING > 0
	BufErrorLog errorLog[LOG_DEPTH];
	u32 errorLogIndex;
#endif
	u32 unallocationCounter;
	u32 overWriteCounter;
	u32 overSizeCounter;
	u32 nullPointerCounter;
	u32 invalidPointerCounter;
	u32 depleteCounter;
}BufferManager_t;

#if DETECT_ALLOC_FREQUENCE  > 0
#define MALLOC_COUNT(pPool) (++(pPool)->callCount)
#define CACHE_MISS_COUNT(pPool) (++(pPool)->cacheMissCount)
#define GET_MALLOC_COUNT(pPool)((pPool)->callCount)
#define GET_CACHE_MISS(pPool) ((pPool)->cacheMissCount)
#else
#define MALLOC_COUNT(pPool) (void)0
#define CACHE_MISS_COUNT(pPool) (void)0
#define GET_MALLOC_COUNT(pPool)0
#define GET_CACHE_MISS(pPool) 0
#endif

#endif
