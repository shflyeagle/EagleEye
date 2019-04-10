/***********************************************************************************/
/*!
* @file buffer_manage_drv.c
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
----------------|-----------------------------------------|-----------|----------
|   Name         |         Description                     |   Date    | Version  |
|----------------|-----------------------------------------|-----------|----------|
| yuquanz        | Creation                                | JULY-1-14 | NO VER   |
* @endcode
*/


//===================== WARNING: Don't Change Anything UNLESS You Really Know==========
#include "buffer_manage_internal.h"
#include <stdio.h>
#include <string.h>

#define BUF_MOD_TAG "[BUF]"

#define DIRECT_BUF_TAG 0x80
#define HEAD_MAGIC_WORD 0x48454144 //ascii "HEAD"
#define TAIL_MAGIC_WORD 0x5441494C //ascii "TAIL"

#define OBJECT_OFFSET(type, ptr, size, offset) ((type*)((char*)(ptr)+((size)*(offset))))
#define OBJECT_NEXT(type,ptr,size) OBJECT_OFFSET(type,ptr,size,1)
#define OBJECT_PREV(type,ptr,size) OBJECT_OFFSET(type,ptr,size,-1)

#define CEILING_TO_4(var) (((var)+3)&~0x03)
#define FILL_MAGIC_WORD(baseAddr,size) *(u32*)(baseAddr)=HEAD_MAGIC_WORD,*(u32*)((u8*)(baseAddr)+CEILING_TO_4(size+4))=TAIL_MAGIC_WORD
#define CHECK_MAGIC_WORD(baseAddr,size) (*(u32*)(baseAddr)==HEAD_MAGIC_WORD && *(u32*)((u8*)(baseAddr)+CEILING_TO_4(size+4))==TAIL_MAGIC_WORD)

#define BUF_UNUSED_PARAM(param) (param)=(param)
#define FILL_MEM_MALLOC_INFOR(pObj) do\
{\
	(pObj)->time = BUF_LOCAL_TIME; \
	(pObj)->tagOwner = tagOwner; \
	(pObj)->size = size; \
	(pObj)->referCount = 1; \
	(pObj)->paramAndLine = paramAndLine; \
	(pObj)->szFuncName = szFuncName; \
}while (0)

static const u8 first_1_pos_table[256] =
{
	8, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0
};
static const u8 count_1_num_table[256] =
{
	0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
	4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
};
static const char * buf_errorFmt[BUF_ERR_WARNING_NUM] =
{
	BUF_MOD_TAG "Error %s-%d: call %s no error, param=%08x\n",                       //BUF_ERR_NO_ERROR,          //0
	BUF_MOD_TAG "Error %s-%d: call %s with NULL pointer, ptr=%08x\n",                //BUF_ERR_NULL_PTR,          //1
	BUF_MOD_TAG "Error %s-%d: call %s with not allocated bufer, ptr=%08x\n",         //BUF_ERR_UNMALLOC_MEMORY,   //2
	BUF_MOD_TAG "Error %s-%d: call %s with address out of range , ptr=%08x\n",       //BUF_ERR_INVALID_PTR,       //3
	BUF_MOD_TAG "Error %s-%d: call %s with size out of range , size=%d\n",           //BUF_ERR_SIZE_OUT_RANGE,    //4
	BUF_MOD_TAG "Error %s-%d: call %s memory over write , ptr=%8x\n",                //BUF_ERR_OVER_WRITE,        //5
	BUF_MOD_TAG "Warning %s-%d: call %s fail because of memory shortage , size=%d\n" //BUF_WARN_MEMORY_SHORTAGE,  //6
};

#if LOG_ERROR_AND_WARNING > 0
inline void BUF_LogErrorWarning(BufferManager_t* pMemoryContext, const char* szBufFunc, const char* szCallerName, u16 line, s16 errCode, u32 extParam)
{
	u32 index = ATOMIC_FETCH_AND_INC(&pMemoryContext->errorLogIndex);
	index &= (LOG_DEPTH - 1);
	pMemoryContext->errorLog[index].szCaller = szCallerName;
	pMemoryContext->errorLog[index].line = line;
	pMemoryContext->errorLog[index].szBufFunc = szBufFunc;
	pMemoryContext->errorLog[index].param = extParam;
	pMemoryContext->errorLog[index].error = errCode;
}
#else
#define BUF_LogErrorWarning(...) (void)0
#endif

#if REALTIME_PRINT_ERROR_WARNING > 0
#define BUF_BUG_PRINT BUF_BUG
#else
#define BUF_BUG_PRINT(...) (void)0
#endif

inline void BUF_ERROR_STATISTIC(BufferManager_t* pMemoryContext, int errCode)
{
	//Strictly speaking,atomic operation should be used
	//However, atomic is not used based performance consideration
	//That means the counter maybe less than the real value
	switch (-errCode)
	{
	case BUF_ERR_NULL_PTR:
		ATOMIC_INC(&pMemoryContext->nullPointerCounter);
		break;
	case BUF_ERR_UNMALLOC_MEMORY:
		ATOMIC_INC(&pMemoryContext->unallocationCounter);
		break;
	case BUF_ERR_INVALID_PTR:
		ATOMIC_INC(&pMemoryContext->invalidPointerCounter);
		break;
	case BUF_ERR_SIZE_OUT_RANGE:
		ATOMIC_INC(&pMemoryContext->overSizeCounter);
		break;
	case BUF_ERR_OVER_WRITE:
		ATOMIC_INC(&pMemoryContext->overWriteCounter);
		break;
	case BUF_WARN_MEMORY_SHORTAGE:
		ATOMIC_INC(&pMemoryContext->depleteCounter);
		break;
	default:
		break;
	}
}

#define BUG_REPORT(pManager,callerName, callLine, errCode, extParam) do\
{\
	BUF_ERROR_STATISTIC(pManager, errCode); \
	BUF_BUG_PRINT(buf_errorFmt[-(errCode)], callerName, callLine, __func__, extParam); \
	BUF_LogErrorWarning(pManager, __func__, callerName, callLine, (s16)errCode, extParam); \
}while (0)

#define CUR_THREAD_CACHE_OF_DIRECT_POOL(pPool)  get_cache_by_thread_key(PER_THREAD_KEY(pPool),\
	DIRECT_POOL_CACHE_DEFAULT_RELOAD_WATER_LEVEL, \
	DIRECT_POOL_CACHE_DEFAULT_MAX_WATER_LEVEL, \
	DIRECT_POOL_CACHE_DEFAULT_RELEASE_WATER_LEVEL\
	)

#define CUR_THREAD_CACHE_OF_CASCADE_POOL(pPool)  get_cache_by_thread_key(PER_THREAD_KEY(pPool),\
	CASCADE_POOL_CACHE_DEFAULT_RELOAD_WATER_LEVEL, \
	CASCADE_POOL_CACHE_DEFAULT_MAX_WATER_LEVEL, \
	CASCADE_POOL_CACHE_DEFAULT_RELEASE_WATER_LEVEL\
	)

inline BufferCache_t* get_cache_by_thread_key(PerThreadKey_t in_Key, u32 preLoadWaterLevel, u32 maxWaterLevel, u32 releaseWaterLevel)
{
	BufferCache_t* pCache = (BufferCache_t*)GET_CUR_THREAD_VAR(in_Key);
	if (pCache == NULL)
	{
		pCache = (BufferCache_t*)MALLOC(sizeof(BufferCache_t));
		pCache->top = 0;
		pCache->preLoadWaterLevel = preLoadWaterLevel;
		pCache->maxWaterLevel = maxWaterLevel;
		pCache->releaseWaterLevel = releaseWaterLevel;
		BUF_ASSERT(pCache != NULL);
		SET_CUR_THREAD_VAR(in_Key, pCache);
	}
	return pCache;
}

inline void* cache_stack_pop(BufferCache_t* pCache)
{
	if (pCache->top)return pCache->ptrStack[--pCache->top];
	else return NULL;
}

inline void cache_stack_push(BufferCache_t* pCache, void* val)
{
	pCache->ptrStack[pCache->top++] = val;
}

inline void atomic_list_add_list_to_head(struct slist_node** destHead, struct slist_node* addListHead, struct slist_node* addListTail)
{
	do
	{
		addListTail->next = *destHead; // Do computation
	} while (!ATOMIC_COMPARE_AND_SET(destHead, addListTail->next, addListHead));
}


inline struct slist_node* atomic_list_take_head(struct slist_node** listHead)
{
	struct slist_node* node;
	do
	{
		node = *listHead;
		if (node == NULL)return NULL;
	} while (!ATOMIC_COMPARE_AND_SET(listHead, node, node->next));
	node->next = NULL;
	return node;
}

inline void buf_spin_lock(volatile u32* lock)
{
	u32 i;
	do
	{
		for (i = 0; i<10; i++);//nop
	} while (!ATOMIC_COMPARE_AND_SET(lock, 0, 1));
}

inline void buf_un_spin_lock(volatile u32* lock)
{
	BUF_ASSERT(*lock == 1);
	*lock = 0;
}
#define BUF_SPIN_LOCK(pObj) THREAD_LOCK((&(pObj)->lock))
#define BUF_UN_SPIN_LOCK(pObj) THREAD_UNLOCK((&(pObj)->lock))

inline void atomic_list_add_head(struct slist_node** listHead, struct slist_node* node)
{
	do
	{
		node->next = *listHead; // Do computation
	} while (!ATOMIC_COMPARE_AND_SET(listHead, node->next, node));
}

inline void dlist_add_head(struct dlist_node** listHead, struct dlist_node* node)
{
	node->next = *listHead;
	node->prev = NULL;
	if (*listHead != NULL) (*listHead)->prev = node;
	*listHead = node;
}

inline struct dlist_node* dlist_take_head(struct dlist_node** listHead)
{
	struct dlist_node* node;
	if (*listHead == NULL)return NULL;

	node = (*listHead);
	if (node->next)node->next->prev = NULL;
	*listHead = node->next;
	return node;
}

inline void dlist_delete_node(struct dlist_node** listHead, struct dlist_node* node)
{
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	if (node == *listHead)*listHead = node->next;
}

inline u32 LSB_1_POS_OF_U32(u32 val)
{
	if (val & 0x0000FFFF)
	{
		if (val & 0x00FF)return first_1_pos_table[(u8)val];
		else return 8 + first_1_pos_table[(u8)(val >> 8)];
	}
	else
	{
		if (val & 0x00FF0000)return 16 + first_1_pos_table[(u8)(val >> 16)];
		else return 24 + first_1_pos_table[(u8)(val >> 24)];
	}
}
inline u32 COUNT_ONE_NUM_OF_U32(u32 val)
{
	return count_1_num_table[(u8)val] + count_1_num_table[(u8)(val >> 8)] + count_1_num_table[(u8)(val >> 16)] + count_1_num_table[(u8)(val >> 24)];
}

void DirectBufPoolInit(DirectBufPool_t *pDirectPool, u8* pBaseMemory, const PhyBufPoolConfig_t* pConfig)
{
	u32 i;
	u8* p;
	u16 perBuffeSize = (1 << pConfig->phyBufSizeOrder);
	ATTACH_PER_THREAD_KEY_FOR_CACHE(pDirectPool);
	pDirectPool->bufBaseAddr = pBaseMemory;
	pDirectPool->bufLimitAddr = pBaseMemory + (pConfig->totalSizeInGranularity << 20);
	pDirectPool->bufTotalCount = (pConfig->totalSizeInGranularity << (20 - pConfig->phyBufSizeOrder));
	pDirectPool->perBufSizeOrder = pConfig->phyBufSizeOrder;
	pDirectPool->metaArray = (MemoryAllocInfor_t*)MALLOC(sizeof(MemoryAllocInfor_t)*pDirectPool->bufTotalCount);
	MEMSET(pDirectPool->metaArray, 0x00, sizeof(MemoryAllocInfor_t)*pDirectPool->bufTotalCount);
	pDirectPool->freeBufCount = pDirectPool->bufTotalCount;
#if DETECT_MAX_MEMORY_COST  > 0
	pDirectPool->minFreeBufferCount = pDirectPool->bufTotalCount;
#endif
#if SUPPORT_DIRECT_POOL_CACHE_LINE == 0
	pDirectPool->freeListHead = NODE_OF_LIST(&pDirectPool->metaArray[0]);
	p = pBaseMemory;
	for (i = 0; i<pDirectPool->bufTotalCount - 1; i++)
	{
		NODE_OF_LIST(&pDirectPool->metaArray[i])->next = NODE_OF_LIST(&pDirectPool->metaArray[i + 1]);
		pDirectPool->metaArray[i].buffer = p;
		p += perBuffeSize;
	}
	NODE_OF_LIST(&pDirectPool->metaArray[i])->next = NULL;
	pDirectPool->metaArray[i].buffer = p;
#else
	pDirectPool->freeArray = (MemoryAllocInfor_t**)MALLOC(sizeof(MemoryAllocInfor_t*)*pDirectPool->bufTotalCount);
	BUF_ASSERT(pDirectPool->freeArray != NULL);
	p = pBaseMemory;
	for (i = 0; i<pDirectPool->bufTotalCount; i++)
	{
		pDirectPool->freeArray[i] = &pDirectPool->metaArray[i];
		pDirectPool->metaArray[i].buffer = p;
		p += perBuffeSize;
	}
#endif
}

void CascadeLogBufPoolInit(CascadeLogBufPool_t* pLogPool, u8 bufSizeShiftBitNum, CascadePhyBufPool_t* pPhyPool)
{
	ATTACH_PER_THREAD_KEY_FOR_CACHE(pLogPool);
	pLogPool->pPhyBufPool = pPhyPool;
	pLogPool->perBufSizeOrder = bufSizeShiftBitNum;
	pLogPool->perBufferSize = (0x01 << bufSizeShiftBitNum);
	pLogPool->nbLogBufPerPhyBuf = (0x01 << (pPhyPool->perBufSizeOrder - pLogPool->perBufSizeOrder));
	pLogPool->metaStep = (0x01 << (pLogPool->perBufSizeOrder - pPhyPool->minCascadeBufSizeOrder));
	pLogPool->freeBufferCount = 0;
	pLogPool->freeListHead = NULL;
#if THREAD_LOCK_ENABLE > 0
	{
		u32 i;
		for (i = 0; i<pLogPool->nbLogBufPerPhyBuf; i++)
		{
			pLogPool->fullMask |= 0x01 << (i*pLogPool->metaStep);
		}
		THREAD_LOCK_INIT(&pLogPool->lock);
	}
#endif
	BUF_ASSERT(pLogPool->nbLogBufPerPhyBuf <= MAX_CACHE_STACK_NUM);
}


void CascadePhyBufPoolInit(CascadePhyBufPool_t* pContext, u8* pBaseMemory, const PhyBufPoolConfig_t* pConfig)
{
	u32 i;
	u8* p;
	int perBufferSizeInByte = (0x01 << pConfig->phyBufSizeOrder);
	u8 maxLogBufPerPhyBuf;
	u32 totalNum = (pConfig->totalSizeInGranularity << (20 - pConfig->phyBufSizeOrder));

	pContext->perBufAddrMask = perBufferSizeInByte - 1;
	pContext->perBufSizeOrder = pConfig->phyBufSizeOrder;
	pContext->bufBaseAddr = pBaseMemory;
	pContext->bufLimitAddr = pBaseMemory + (pConfig->totalSizeInGranularity << 20);
	pContext->totalBufferCount = totalNum;
	pContext->pPhyBufMeta = (CascadePhyBufContext_t*)MALLOC(sizeof(CascadePhyBufContext_t)*totalNum);
	MEMSET(pContext->pPhyBufMeta, 0x00, sizeof(CascadePhyBufContext_t)*totalNum);

	//get maximum logic block number in one physical buffer
	for (i = 0; i <= pConfig->phyBufSizeOrder; i++)
	{
		if (pConfig->logBufPoolMapBitmap&(0x01 << i))break;
	}
	pContext->minCascadeBufSizeOrder = i;
	maxLogBufPerPhyBuf = (1 << (pConfig->phyBufSizeOrder - pContext->minCascadeBufSizeOrder));

	pContext->pLogBufMeta = (MemoryAllocInfor_t*)MALLOC(sizeof(MemoryAllocInfor_t)*totalNum*maxLogBufPerPhyBuf);
	MEMSET(pContext->pLogBufMeta, 0x00, sizeof(MemoryAllocInfor_t)*totalNum*maxLogBufPerPhyBuf);
	pContext->freeBufferCount = totalNum;
#if DETECT_MAX_MEMORY_COST  > 0
	pContext->minFreeBufferCount = totalNum;
#endif
	//initialize free physical buffer list
	p = (u8*)pContext->bufBaseAddr;
	pContext->freeListHead = NODE_OF_LIST(&pContext->pPhyBufMeta[0]);
	for (i = 0; i<totalNum - 1; i++)
	{
		NODE_OF_LIST(&pContext->pPhyBufMeta[i])->next = NODE_OF_LIST(&pContext->pPhyBufMeta[i + 1]);
		pContext->pPhyBufMeta[i].buffer = p;
		pContext->pPhyBufMeta[i].pCascadeBuffer = pContext->pLogBufMeta + i*maxLogBufPerPhyBuf;
		p += perBufferSizeInByte;
	}
	pContext->pPhyBufMeta[i].buffer = p;
	pContext->pPhyBufMeta[i].pCascadeBuffer = pContext->pLogBufMeta + i*maxLogBufPerPhyBuf;

	//initialize meta
	p = (u8*)pContext->bufBaseAddr;
	perBufferSizeInByte >>= (pConfig->phyBufSizeOrder - pContext->minCascadeBufSizeOrder);
	for (i = 0; i<totalNum*maxLogBufPerPhyBuf; i++)
	{
		pContext->pLogBufMeta[i].buffer = p;
		p += perBufferSizeInByte;
	}
}

#if HARD_CODE_LOOK_UP_TABLE > 0
BufManHandle_t __BUF_CreateManager(const PhyBufPoolConfig_t* pConfig, const char* szName, const u8*offsetToPhyPoolIndex, const u8*sizeToLogPoolIndex)
#else
BufManHandle_t __BUF_CreateManager(const PhyBufPoolConfig_t* pConfig, const char* szName)
#endif
{
	u32 i, j, directPoolIndex = 0, phyPoolIndex = 0, cascadePoolIndex = 0;
	u32 totalSize = 0;
	u32 endOffset;
	u8* pBase = NULL;
	BufferManager_t* pMemoryContext;
#if HARD_CODE_LOOK_UP_TABLE == 0    
	u8*offsetToPhyPoolIndex = NULL;
	u8*sizeToLogPoolIndex = NULL;
	u32 offsetTableSize;
#endif    
	struct
	{
		u32 endOffset;
		u8  regionInfor;
	}memRegionMap[MAX_DIRECT_BUFFER_POOL_NUM + MAX_CASCADE_PHY_BUFFER_POOL_NUM];
	struct
	{
		u16 maxSize;
		u8   poolInfor;
	}sizeRangeMap[MAX_DIRECT_BUFFER_POOL_NUM + MAX_CASCADE_LOG_BUFFER_POOL_NUM];
	BUF_ASSERT(szName != NULL);
	pMemoryContext = (BufferManager_t*)MALLOC(sizeof(BufferManager_t));
	MEMSET(pMemoryContext, 0x00, sizeof(BufferManager_t));
	BUF_ASSERT(pMemoryContext != NULL);
	strncpy(pMemoryContext->szName, szName, sizeof(pMemoryContext->szName) - 1);
	MEMSET(memRegionMap, 0x00, sizeof(memRegionMap));
	MEMSET(sizeRangeMap, 0x00, sizeof(sizeRangeMap));

	//alloc large continuous memory block
	for (i = 0; pConfig[i].totalSizeInGranularity != 0; i++)
	{
		totalSize += pConfig[i].totalSizeInGranularity;
	}

	offsetTableSize = totalSize;

	pMemoryContext->pPhyBufBaseAddr = (u8*)MALLOC(totalSize << MEM_RESERVED_GRANULARITY_ORDER);
	BUF_ASSERT(NULL != pMemoryContext->pPhyBufBaseAddr);
	pMemoryContext->pPhyBufLimitAddr = pMemoryContext->pPhyBufBaseAddr + (totalSize << MEM_RESERVED_GRANULARITY_ORDER);

	//    Initialize physical pools. Direct pool is physical pool, also it is logic pool
	pBase = pMemoryContext->pPhyBufBaseAddr;
	endOffset = 0;
	directPoolIndex = 0;
	phyPoolIndex = 0;
	for (i = 0; pConfig[i].phyBufSizeOrder != 0; i++)
	{
		if (pConfig[i].poolType == DIRECT_BUF_POOL)
		{
			memRegionMap[i].regionInfor = DIRECT_BUF_TAG | directPoolIndex;
#if AUTO_MALLOC_DIRECT_BUFFER > 0          
			sizeRangeMap[i].maxSize = (0x01 << pConfig[i].phyBufSizeOrder);
			sizeRangeMap[i].poolInfor = (DIRECT_BUF_TAG | directPoolIndex);
#endif           
			pMemoryContext->maxBufferSize = (0x01 << pConfig[i].phyBufSizeOrder);
			DirectBufPoolInit(&pMemoryContext->directPool[directPoolIndex], pBase, &pConfig[i]);
			++directPoolIndex;
		}
		else if (pConfig[i].poolType == CASECADE_BUF_POOL)
		{
			memRegionMap[i].regionInfor = phyPoolIndex;
			CascadePhyBufPoolInit(&pMemoryContext->cascadePhyPool[phyPoolIndex], pBase, &pConfig[i]);
			++phyPoolIndex;
		}
		endOffset += pConfig[i].totalSizeInGranularity;
		memRegionMap[i].endOffset = endOffset;
		pBase += (pConfig[i].totalSizeInGranularity << MEM_RESERVED_GRANULARITY_ORDER);
	}
	BUF_ASSERT(directPoolIndex <= MAX_DIRECT_BUFFER_POOL_NUM);
	BUF_ASSERT(phyPoolIndex <= MAX_CASCADE_PHY_BUFFER_POOL_NUM);
	pMemoryContext->directPoolNum = directPoolIndex;
	pMemoryContext->cascadePhyPoolNum = phyPoolIndex;
	// To enhance robustness, look-up tables are hard-coded though they can be generated dynamically 
#if HARD_CODE_LOOK_UP_TABLE > 0
#ifdef WIN32 //In PC, generate look-up table,the paste into souce code
	{
		int offset = 0;
		int loop;
		printf("const u8 offsetToPhyPoolIndex[]={\n");
		for (loop = 0; loop<directPoolIndex + phyPoolIndex; loop++)
		{
			while (offset < memRegionMap[loop].endOffset)
			{
				printf("0x%02x, ", memRegionMap[loop].regionInfor);
				if ((offset & 0x0F) == 0x0F)printf("\n");
				offset++;
			}
		}
		printf("\n}\n");
	}
#endif
	//   compare to check
	{
		u32 offset = 0;
		u32 loop;
		for (loop = 0; loop<directPoolIndex + phyPoolIndex; loop++)
		{
			while (offset < memRegionMap[loop].endOffset)
			{
				BUF_ASSERT(offsetToPhyPoolIndex[offset] == memRegionMap[loop].regionInfor);
				offset++;
			}
		}
	}

#else
	offsetToPhyPoolIndex = (u8*)MALLOC(offsetTableSize);
	{

		u32 offset = 0;
		u32 loop;

		for (loop = 0; loop<directPoolIndex + phyPoolIndex; loop++)
		{
			while (offset < memRegionMap[loop].endOffset)
			{
				offsetToPhyPoolIndex[offset] = memRegionMap[loop].regionInfor;
				offset++;
			}
		}
		BUF_ASSERT(offset == offsetTableSize);
	}
#endif
	pMemoryContext->offsetToPhyPoolIndex = offsetToPhyPoolIndex;


#if AUTO_MALLOC_DIRECT_BUFFER == 0
	directPoolIndex = 0;
#endif
	j = 0;
	cascadePoolIndex = 0;
	phyPoolIndex = 0;

	for (i = 0; pConfig[i].phyBufSizeOrder != 0; i++)
	{
		if (pConfig[i].poolType != DIRECT_BUF_POOL)
		{
			for (; j <= pConfig[i].phyBufSizeOrder; j++)
			{
				if (pConfig[i].logBufPoolMapBitmap&(1 << j))
				{
					CascadeLogBufPoolInit(&pMemoryContext->cascadeLogPool[cascadePoolIndex],
						j,
						&pMemoryContext->cascadePhyPool[phyPoolIndex]);
					pMemoryContext->maxBufferSize = (0x01 << j);
					sizeRangeMap[directPoolIndex + cascadePoolIndex].maxSize = (0x01 << j);
					sizeRangeMap[directPoolIndex + cascadePoolIndex].poolInfor = cascadePoolIndex;
					cascadePoolIndex++;
				}
			}
			phyPoolIndex++;
		}
	}
	pMemoryContext->cascadeLogPoolNum = cascadePoolIndex;
	// To enhance robustness, look-up tables are hard-coded though they can be generated dynamically 
#if HARD_CODE_LOOK_UP_TABLE > 0
#ifdef WIN32 //In PC, generate look-up table,the paste into souce code
	{
		u32 index = 0;
		u32 loop;
		printf("const u8 sizeToLogPoolIndex[]={\n");
		for (loop = 0; loop<directPoolIndex + cascadePoolIndex; loop++)
		{
			while ((index << MEM_APP_MALLOC_GRANULARITY_ORDER) <= sizeRangeMap[loop].maxSize)
			{
				printf("0x%02x, ", sizeRangeMap[loop].poolInfor);
				if ((index & 0x0F) == 0x0F)printf("\n");
				index++;
			}
		}
		printf("\n}\n");
	}
#endif 
	//In target, compare to check
	{
		u32 index = 0;
		u32 loop;
		for (loop = 0; loop<directPoolIndex + cascadePoolIndex; loop++)
		{
			while (index <= (sizeRangeMap[loop].maxSize >> MEM_APP_MALLOC_GRANULARITY_ORDER))
			{
				BUF_ASSERT(sizeToLogPoolIndex[index] == sizeRangeMap[loop].poolInfor);
				index++;
			}
		}
	}
#else
	sizeToLogPoolIndex = (u8*)MALLOC((pMemoryContext->maxBufferSize >> MEM_APP_MALLOC_GRANULARITY_ORDER) + 1);
	{
		u32 index = 0;
		u32 loop;

		for (loop = 0; loop<directPoolIndex + cascadePoolIndex; loop++)
		{
			while (index <= (sizeRangeMap[loop].maxSize >> MEM_APP_MALLOC_GRANULARITY_ORDER))
			{
				sizeToLogPoolIndex[index] = sizeRangeMap[loop].poolInfor;
				index++;
			}
		}
		BUF_ASSERT(index == (pMemoryContext->maxBufferSize >> MEM_APP_MALLOC_GRANULARITY_ORDER) + 1);
	}
#endif
	pMemoryContext->sizeToLogPoolIndex = sizeToLogPoolIndex;
	return pMemoryContext;
}

void __BUF_ConfigCache(BufManHandle_t handle, u32 size, u32 preLoadWaterLevel, u32 maxWaterLevel, u32 releaseWaterLevel)
{
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, handle);
	u8 poolIndex;
	BufferCache_t* pCache = NULL;
#if AUTO_MALLOC_DIRECT_BUFFER == 0
	if (IsDirectBufferWanted(size))
	{
		BUF_ASSERT(DIRECT_BUFFER_WANTED_SIZE(size) != 0);
		BUF_ASSERT(DIRECT_BUFFER_WANTED_SIZE(size) <= (1 << pMemoryContext->directPool[DIRECT_BUFFER_ID(size)].perBufSizeOrder));
		poolIndex = DIRECT_BUFFER_ID(size)] | DIRECT_BUF_TAG;
	}
	else
	{
		BUF_ASSERT(size != 0);
		BUF_ASSERT(size <= pMemoryContext->maxBufferSize);
		poolIndex = pMemoryContext->sizeToLogPoolIndex[(size + (1 << MEM_APP_MALLOC_GRANULARITY_ORDER) - 1) >> MEM_APP_MALLOC_GRANULARITY_ORDER];
	}
#else  
	BUF_ASSERT(size == 0 || size> pMemoryContext->maxBufferSize);
	poolIndex = pMemoryContext->sizeToLogPoolIndex[(size + (1 << MEM_APP_MALLOC_GRANULARITY_ORDER) - 1) >> MEM_APP_MALLOC_GRANULARITY_ORDER];
#endif

	if (poolIndex&DIRECT_BUF_TAG)
		pCache = (BufferCache_t*)GET_CUR_THREAD_VAR(PER_THREAD_KEY(&pMemoryContext->directPool[poolIndex&~DIRECT_BUF_TAG]));
	else
		pCache = (BufferCache_t*)GET_CUR_THREAD_VAR(PER_THREAD_KEY(&pMemoryContext->cascadeLogPool[poolIndex]));

	if (pCache == NULL)
	{
		pCache = (BufferCache_t*)MALLOC(sizeof(BufferCache_t));
		BUF_ASSERT(pCache != NULL);
		pCache->top = 0;
		if (poolIndex&DIRECT_BUF_TAG)SET_CUR_THREAD_VAR(PER_THREAD_KEY(&pMemoryContext->directPool[poolIndex&~DIRECT_BUF_TAG]), pCache);
		else SET_CUR_THREAD_VAR(PER_THREAD_KEY(&pMemoryContext->cascadeLogPool[poolIndex]), pCache);
	}

	pCache->preLoadWaterLevel = preLoadWaterLevel;
	pCache->maxWaterLevel = maxWaterLevel;
	pCache->releaseWaterLevel = releaseWaterLevel;
}


#if SUPPORT_DIRECT_POOL_CACHE_LINE > 0
inline void DirectBufferReleaseCache(DirectBufPool_t* pPool, BufferCache_t* pCache, u32 freeCount)
{
	void** pSrc;
	void** pDest;
	u32 i;
	BUF_ASSERT(pCache->top >= freeCount);

	pSrc = &pCache->ptrStack[pCache->top - freeCount];
	BUF_SPIN_LOCK(pPool);
	pDest = (void**)&pPool->freeArray[pPool->freeBufCount];
	for (i = 0; i<freeCount; i++)
		*pDest++ = *pSrc++;
	pPool->freeBufCount += freeCount;
	BUF_UN_SPIN_LOCK(pPool);

	pCache->top -= freeCount;
}
#else
inline void DirectBufferReleaseCache(DirectBufPool_t* pPool, BufferCache_t* pCache, u32 freeCount)
{
	u32 i;
	for (i = pCache->top - freeCount; i<pCache->top - 1; i++)
	{
		NODE_OF_LIST((MemoryAllocInfor_t*)pCache->ptrStack[i])->next = NODE_OF_LIST((MemoryAllocInfor_t*)pCache->ptrStack[i + 1]);
	}

	atomic_list_add_list_to_head(&pPool->freeListHead,
		NODE_OF_LIST((MemoryAllocInfor_t*)pCache->ptrStack[pCache->top - freeCount]),
		NODE_OF_LIST((MemoryAllocInfor_t*)pCache->ptrStack[pCache->top - 1])
		);
	ATOMIC_ADD(&pPool->freeBufCount, freeCount);
	pCache->top -= freeCount;
}
#endif


inline void* DirectBufferMalloc(DirectBufPool_t* pDirectPool, u32 size, const char* szFuncName, u32 paramAndLine, u32 tagOwner)
{
	MemoryAllocInfor_t* pBufferContext = NULL;

#if SUPPORT_PER_THREAD_CACHE > 0
	BufferCache_t* pCache = CUR_THREAD_CACHE_OF_DIRECT_POOL(pDirectPool);
	pBufferContext = (MemoryAllocInfor_t*)cache_stack_pop(pCache);
#endif

	MALLOC_COUNT(pDirectPool);
	BUF_ASSERT(size <= (u32)(1 << pDirectPool->perBufSizeOrder));
	if (pBufferContext == NULL)
	{
#if SUPPORT_DIRECT_POOL_CACHE_LINE > 0
		u32 i;
		u32 insertCount = 0;
		void**pSrc;
		void**pDest;

		pDest = pCache->ptrStack;

		BUF_SPIN_LOCK(pDirectPool);
		if (pDirectPool->freeBufCount > 0)
		{
			insertCount = pCache->preLoadWaterLevel < pDirectPool->freeBufCount ? pCache->preLoadWaterLevel : pDirectPool->freeBufCount;
			pSrc = (void**)&pDirectPool->freeArray[pDirectPool->freeBufCount - insertCount];
			for (i = 0; i<insertCount - 1; i++)
				*pDest++ = *pSrc++;
			pDirectPool->freeBufCount -= insertCount;
		}
		BUF_UN_SPIN_LOCK(pDirectPool);

		if (insertCount)
		{
			pBufferContext = (MemoryAllocInfor_t*)*pSrc;
			pCache->top = insertCount - 1;
		}
#else
		pBufferContext = (MemoryAllocInfor_t*)atomic_list_take_head(&pDirectPool->freeListHead);
		if (pBufferContext != NULL)
		{
			ATOMIC_DEC(&pDirectPool->freeBufCount);
		}
#endif

#if DETECT_MAX_MEMORY_COST  > 0
		if (pDirectPool->freeBufCount < pDirectPool->minFreeBufferCount)
			pDirectPool->minFreeBufferCount = pDirectPool->freeBufCount;
#endif
		CACHE_MISS_COUNT(pDirectPool);
	}

	if (pBufferContext != NULL)
	{
		BUF_ASSERT(pBufferContext->referCount == 0);
		FILL_MEM_MALLOC_INFOR(pBufferContext);
#if SUPPORT_OVERWRITE_CHECK > 0
		if (size <= (u32)((1 << pDirectPool->perBufSizeOrder) - 8))
		{
			*(u32*)pBufferContext->buffer = HEAD_MAGIC_WORD;
			*(u32*)(pBufferContext->buffer + CEILING_TO_4(size + 4)) = TAIL_MAGIC_WORD;
			return pBufferContext->buffer + 4;
		}
		else
#endif
			return pBufferContext->buffer;
	}
	else
	{
		return NULL;
	}
}

inline int DirectBufferFree(DirectBufPool_t* pContext, u8* ptr)
{
	u32 index;
	u32 prevCount;
	int err = 0;
#if SUPPORT_PER_THREAD_CACHE > 0
	BufferCache_t* pCache = CUR_THREAD_CACHE_OF_DIRECT_POOL(pContext);
#endif
	index = ((ptr - pContext->bufBaseAddr) >> pContext->perBufSizeOrder);
	BUF_ASSERT_DBG(index<pContext->bufTotalCount);

	prevCount = ATOMIC_FETCH_AND_CLR(&pContext->metaArray[index].referCount);
	if (prevCount != 0)//more likely
	{
#if SUPPORT_OVERWRITE_CHECK > 0
		if (pContext->metaArray[index].size <= (1 << pContext->perBufSizeOrder) - 8)
		{
			if (!CHECK_MAGIC_WORD(pContext->metaArray[index].buffer, pContext->metaArray[index].size))
			{
				err = -BUF_ERR_OVER_WRITE;
				BUF_ASSERT_DBG(BUF_ERR_OVER_WRITE == 0);//equals BUF_ASSERT_DBG(0) but better
			}
		}
#endif

#if SUPPORT_PER_THREAD_CACHE > 0
		cache_stack_push(pCache, &pContext->metaArray[index]);
		if (pCache->top == pCache->maxWaterLevel)
		{
			DirectBufferReleaseCache(pContext, pCache, pCache->maxWaterLevel - pCache->releaseWaterLevel);
		}
#else
		atomic_list_add_head(&pContext->freeListHead, NODE_OF_LIST(&pContext->metaArray[index]));
		ATOMIC_INC(&pContext->freeBufCount);
#endif
	}
	else
	{
		err = -BUF_ERR_UNMALLOC_MEMORY;
	}
	return err;
}



#if THREAD_LOCK_ENABLE > 0

inline void CascadeBufferBatchReturn(CascadePhyBufPool_t* pPhyPool, CascadePhyBufContext_t**pPhyBufToFreeArray, u32 count)
{
	if (count > 1)
	{
		u32 i;
		for (i = 0; i<count - 1; i++)
		{
			NODE_OF_LIST(pPhyBufToFreeArray[i])->next = NODE_OF_LIST(pPhyBufToFreeArray[i + 1]);
		}
		NODE_OF_LIST(pPhyBufToFreeArray[i])->next = 0;
		atomic_list_add_list_to_head(&pPhyPool->freeListHead, NODE_OF_LIST(pPhyBufToFreeArray[0]), NODE_OF_LIST(pPhyBufToFreeArray[i]));
	}
	else
	{
		atomic_list_add_head(&pPhyPool->freeListHead, NODE_OF_LIST(pPhyBufToFreeArray[0]));
	}
	ATOMIC_ADD(&pPhyPool->freeBufferCount, count);
}

inline void CascadeBufferReleaseCache(CascadeLogBufPool_t* pLogPool, BufferCache_t* pCache, u32 freeCount)
{
	CascadePhyBufPool_t* pPhyPool = pLogPool->pPhyBufPool;
	CascadePhyBufContext_t* pPhyBufToFree[MAX_CASCADE_BUFFER_CACHE_NUM];
	CascadePhyBufContext_t* pPhyMeta;
	MemoryAllocInfor_t* pLogMeta;
	u32 logIndex;
	u32 shift;
	u16 freePhyBufCount = 0;
	u16 i;
	BUF_ASSERT_DBG(pCache->top >= freeCount);
	shift = pPhyPool->perBufSizeOrder - pPhyPool->minCascadeBufSizeOrder;
	if (pLogPool->nbLogBufPerPhyBuf > 1)
	{
		BUF_SPIN_LOCK(pLogPool);
		pLogPool->freeBufferCount += freeCount;
		for (i = pCache->top - freeCount; i<pCache->top; i++)
		{
			pLogMeta = (MemoryAllocInfor_t*)pCache->ptrStack[i];
			logIndex = pLogMeta - pPhyPool->pLogBufMeta;
			pPhyMeta = pPhyPool->pPhyBufMeta + (logIndex >> shift);
			pPhyMeta->freeBitmap |= (1 << (logIndex&((1 << shift) - 1)));
			if (pPhyMeta->freeBitmap == (u32)(1 << (logIndex&((1 << shift) - 1))))//need to add logic list
			{
				dlist_add_head(&pLogPool->freeListHead, NODE_OF_DLIST(pPhyMeta));
			}
			else if (pPhyMeta->freeBitmap == pLogPool->fullMask)//need to back to physical
			{
				dlist_delete_node(&pLogPool->freeListHead, NODE_OF_DLIST(pPhyMeta));
				pPhyBufToFree[freePhyBufCount++] = pPhyMeta;//To decrease lock time,just record
				pLogPool->freeBufferCount -= pLogPool->nbLogBufPerPhyBuf;
			}
		}
		BUF_UN_SPIN_LOCK(pLogPool);
	}
	else//if log:phy = 1:1,return to physical pool directly
	{
		for (i = pCache->top - freeCount; i<pCache->top; i++)
		{
			pLogMeta = (MemoryAllocInfor_t*)pCache->ptrStack[i];
			logIndex = pLogMeta - pPhyPool->pLogBufMeta;
			pPhyBufToFree[freePhyBufCount++] = pPhyPool->pPhyBufMeta + (logIndex >> shift);
		}
	}

	if (freePhyBufCount > 0)CascadeBufferBatchReturn(pPhyPool, pPhyBufToFree, freePhyBufCount);
	pCache->top = pCache->top - freeCount;
}
#else
inline void CascadeBufferReleaseCache(CascadeLogBufPool_t* pLogPool, BufferCache_t* pCache, u32 freeCount)
{
	u32 i;
	u8* ptr;
	for (i = 0; i<freeCount; i++)
	{
		ptr = (u8*)CascadeBufferMalloc(pLogPool, pLogPool->perBufferSize, NULL, 0, 0);
		CascadeBufferFree(pLogPool, ptr - pLogPool->pPhyBufPool->bufBaseAddr);
	}
}
#endif
void* CascadeBufferMalloc(CascadeLogBufPool_t* pLogPool, u32 size, const char* szFuncName, int paramAndLine, u32 tagOwner)
{
	CascadePhyBufContext_t* pPhyBufferContext = NULL;
	MemoryAllocInfor_t* pCascadeMeta;

#if SUPPORT_PER_THREAD_CACHE > 0
	BufferCache_t* pCache = CUR_THREAD_CACHE_OF_CASCADE_POOL(pLogPool);
	BUF_ASSERT_DBG(size <= pLogPool->perBufferSize);
	pCascadeMeta = (MemoryAllocInfor_t*)cache_stack_pop(pCache);
#else
	struct slist_node* list_head;
	struct slist_node* list_tail;
	BUF_ASSERT_DBG(size <= pLogPool->perBufferSize);
	pCascadeMeta = (MemoryAllocInfor_t*)atomic_list_take_head(&pLogPool->freeListHead);
#endif
	MALLOC_COUNT(pLogPool);
	if (pCascadeMeta == NULL)
	{
#if THREAD_LOCK_ENABLE > 0
		u32 i, pos;
		u32 bitmap;
		u32 count = 0;
		CascadePhyBufContext_t* arPhyBuffer[MAX_CASCADE_BUFFER_CACHE_NUM];
		u32 phyBufferCount = 0;
		if (pLogPool->nbLogBufPerPhyBuf > 1)
		{
			BUF_SPIN_LOCK(pLogPool);//try to get from logic pool
			do
			{
				arPhyBuffer[phyBufferCount] = (CascadePhyBufContext_t*)dlist_take_head(&pLogPool->freeListHead);
				if (arPhyBuffer[phyBufferCount] == NULL)break;

				BUF_ASSERT_DBG(arPhyBuffer[phyBufferCount]->freeBitmap != 0);
				count += COUNT_ONE_NUM_OF_U32(arPhyBuffer[phyBufferCount]->freeBitmap);

				phyBufferCount++;
			} while (count < pCache->preLoadWaterLevel);
			pLogPool->freeBufferCount -= count;
			BUF_UN_SPIN_LOCK(pLogPool);
		}

		if (phyBufferCount)//move to cache
		{
			for (i = 0; i<phyBufferCount; i++)
			{
				bitmap = arPhyBuffer[i]->freeBitmap;
				arPhyBuffer[i]->freeBitmap = 0;
				while (bitmap)
				{
					pos = LSB_1_POS_OF_U32(bitmap);
					bitmap &= ~(1 << pos);
					cache_stack_push(pCache, &arPhyBuffer[i]->pCascadeBuffer[pos]);
				}
			}
		}
		else//logic pool is deplete, get from physical pool
		{
			pPhyBufferContext = (CascadePhyBufContext_t*)atomic_list_take_head(&pLogPool->pPhyBufPool->freeListHead);
			if (pPhyBufferContext != NULL)
			{
				ATOMIC_DEC(&pLogPool->pPhyBufPool->freeBufferCount);
#if DETECT_MAX_MEMORY_COST  > 0
				if (pLogPool->pPhyBufPool->freeBufferCount < pLogPool->pPhyBufPool->minFreeBufferCount)
					pLogPool->pPhyBufPool->minFreeBufferCount = pLogPool->pPhyBufPool->freeBufferCount;
#endif  
				pPhyBufferContext->freeBitmap = 0;
				pPhyBufferContext->pLogBufPool = pLogPool;
				for (i = 0; i<(u32)pLogPool->nbLogBufPerPhyBuf; i++)
				{
					cache_stack_push(pCache, &pPhyBufferContext->pCascadeBuffer[i*pLogPool->metaStep]);
				}
			}
		}

		pCascadeMeta = (MemoryAllocInfor_t*)cache_stack_pop(pCache);

#else
		pPhyBufferContext = (CascadePhyBufContext_t*)atomic_list_take_head(&pLogPool->pPhyBufPool->freeListHead);
		if (pPhyBufferContext)
		{
			u32 i;

			BUF_ASSERT(pPhyBufferContext->referCount == 0);
			ATOMIC_DEC(&pLogPool->pPhyBufPool->freeBufferCount);
#if DETECT_MAX_MEMORY_COST  > 0
			if (pLogPool->pPhyBufPool->freeBufferCount < pLogPool->pPhyBufPool->minFreeBufferCount)
				pLogPool->pPhyBufPool->minFreeBufferCount = pLogPool->pPhyBufPool->freeBufferCount;
#endif         
			pPhyBufferContext->pLogBufPool = pLogPool;
			pPhyBufferContext->referCount = pLogPool->nbLogBufPerPhyBuf;
			pPhyBufferContext->time = BUF_LOCAL_TIME;
#if SUPPORT_PER_THREAD_CACHE > 0
			pCascadeMeta = pPhyBufferContext->pCascadeBuffer + pLogPool->metaStep;
			for (i = 1; i<(u32)(pLogPool->nbLogBufPerPhyBuf); i++)
			{
				cache_stack_push(pCache, pCascadeMeta);
				pCascadeMeta = pCascadeMeta + pLogPool->metaStep;
			}
#else
			pCascadeMeta = pPhyBufferContext->pCascadeBuffer + pLogPool->metaStep;
			list_head = NODE_OF_LIST(pCascadeMeta);
			for (i = 1; i<(u32)(pLogPool->nbLogBufPerPhyBuf - 1); i++)
			{
				pCascadeMeta->next = NODE_OF_LIST(pCascadeMeta + pLogPool->metaStep);
				pCascadeMeta = pCascadeMeta + pLogPool->metaStep;
			}
			list_tail = NODE_OF_LIST(pCascadeMeta);

			if (pLogPool->nbLogBufPerPhyBuf - 1 > 0)//insert
			{
				atomic_list_add_list_to_head(&pLogPool->freeListHead, list_head, list_tail);
			}
#endif         
			ATOMIC_ADD(&pLogPool->freeBufferCount, pLogPool->nbLogBufPerPhyBuf - 1);
			pCascadeMeta = pPhyBufferContext->pCascadeBuffer;
		}
#endif
		CACHE_MISS_COUNT(pLogPool);
	}
	else
	{
#if THREAD_LOCK_ENABLE == 0  
		ATOMIC_DEC(&pLogPool->freeBufferCount);
#endif
	}
	if (pCascadeMeta != NULL)
	{
		BUF_ASSERT(pCascadeMeta->referCount == 0);
		FILL_MEM_MALLOC_INFOR(pCascadeMeta);
#if SUPPORT_OVERWRITE_CHECK > 0
		if (size <= (u32)(pLogPool->perBufferSize - 8))
		{
			FILL_MAGIC_WORD(pCascadeMeta->buffer, size);
			return pCascadeMeta->buffer + 4;
		}
		else
#endif   
			return pCascadeMeta->buffer;
	}
	else
	{
		return NULL;
	}
}

int CascadeBufferFree(CascadeLogBufPool_t* pLogPool, u32 offset)
{
	u8 logBufferIndex;
	u32 prevCount;
	int err = 0;
	CascadePhyBufPool_t* pPhyPool = pLogPool->pPhyBufPool;
	CascadePhyBufContext_t* pPhyBufferContext = NULL;
	MemoryAllocInfor_t* pAllocMeta;
	pPhyBufferContext = &pPhyPool->pPhyBufMeta[offset >> pPhyPool->perBufSizeOrder];
	logBufferIndex = ((offset&pPhyPool->perBufAddrMask) >> pLogPool->perBufSizeOrder);
	pAllocMeta = pPhyBufferContext->pCascadeBuffer + logBufferIndex*pLogPool->metaStep;
	prevCount = ATOMIC_FETCH_AND_CLR(&pAllocMeta->referCount);
	if (prevCount != 0)//more likely
	{
#if SUPPORT_OVERWRITE_CHECK > 0
		if (pAllocMeta->size <= pLogPool->perBufferSize - 8)
		{
			if (!CHECK_MAGIC_WORD(pAllocMeta->buffer, pAllocMeta->size))
			{
				err = -BUF_ERR_OVER_WRITE;
				//        BUF_TRACE("allocated by %s-%d size=%d, head=%x,tail=%08x\n",
				//            pAllocMeta->szFuncName,pAllocMeta->paramAndLine&0xffff,pAllocMeta->size,
				//            *(u32*)pAllocMeta->buffer,*(u32*)(pAllocMeta->buffer+CEILING_TO_4(4+pAllocMeta->size)));

				BUF_ASSERT_DBG(BUF_ERR_OVER_WRITE == 0);
			}
		}
#endif

#if THREAD_LOCK_ENABLE > 0
		{
			BufferCache_t* pCache = CUR_THREAD_CACHE_OF_CASCADE_POOL(pLogPool);
			cache_stack_push(pCache, pAllocMeta);
			if (pCache->top == pCache->maxWaterLevel)
				CascadeBufferReleaseCache(pLogPool, pCache, pCache->maxWaterLevel - pCache->releaseWaterLevel);
		}
#else
		ATOMIC_DEC(&pPhyBufferContext->referCount);
		if (pPhyBufferContext->referCount == 0)
		{
			atomic_list_add_head(&pPhyPool->freeListHead, NODE_OF_LIST(pPhyBufferContext));
			ATOMIC_INC(&pPhyPool->freeBufferCount);
		}
#endif
	}
	else
	{
		err = -BUF_ERR_UNMALLOC_MEMORY;
	}
	return err;
}

void* __BUF_Malloc(BufManHandle_t handle, u32 size, const char* szFunc, u32 paramAndLine, u32 tagOwner)
{
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, handle);
	int err = 0;
	u8 poolIndex;
	void* ret = NULL;
#if AUTO_MALLOC_DIRECT_BUFFER == 0
	if (IsDirectBufferWanted(size))
	{
		BUF_ASSERT_DBG(DIRECT_BUFFER_WANTED_SIZE(size) != 0);
		BUF_ASSERT_DBG(DIRECT_BUFFER_WANTED_SIZE(size) <= (1 << pMemoryContext->directPool[DIRECT_BUFFER_ID(size)].perBufSizeOrder));

		if (DIRECT_BUFFER_WANTED_SIZE(size) == 0
			|| (DIRECT_BUFFER_WANTED_SIZE(size)>(1 << pMemoryContext->directPool[DIRECT_BUFFER_ID(size)].perBufSizeOrder)))
		{
			err = -BUF_ERR_SIZE_OUT_RANGE;
		}
		else
			ret = DirectBufferMalloc(&pMemoryContext->directPool[DIRECT_BUFFER_ID(size)], DIRECT_BUFFER_WANTED_SIZE(size), szFunc, paramAndLine, tagOwner);
	}
	else
	{
		BUF_ASSERT_DBG(size != 0);
		BUF_ASSERT_DBG(size <= pMemoryContext->maxBufferSize);

		if (size == 0 || size> pMemoryContext->maxBufferSize)
			err = -BUF_ERR_SIZE_OUT_RANGE;
		else
		{
			poolIndex = pMemoryContext->sizeToLogPoolIndex[(size + (1 << MEM_APP_MALLOC_GRANULARITY_ORDER) - 1) >> MEM_APP_MALLOC_GRANULARITY_ORDER];
			ret = CascadeBufferMalloc(&pMemoryContext->cascadeLogPool[poolIndex], size, szFunc, paramAndLine, tagOwner);
		}
	}
#else  
	if (size == 0 || size> pMemoryContext->maxBufferSize)
		err = -BUF_ERR_SIZE_OUT_RANGE;
	else
	{
		poolIndex = pMemoryContext->sizeToLogPoolIndex[(size + (1 << MEM_APP_MALLOC_GRANULARITY_ORDER) - 1) >> MEM_APP_MALLOC_GRANULARITY_ORDER];
		if (poolIndex&DIRECT_BUF_TAG)//direct buffer
		{
#if TRY_BEST_MALLOC > 0
			u8 id;
			for (id = poolIndex&~DIRECT_BUF_TAG; id < pMemoryContext->directPoolNum; id++)
			{
				if (pMemoryContext->directPool[id].freeBufCount)
				{
					ret = DirectBufferMalloc(&pMemoryContext->directPool[id], size, szFunc, paramAndLine, tagOwner);
					break;
				}
			}
#else
			ret = DirectBufferMalloc(&pMemoryContext->directPool[poolIndex&~DIRECT_BUF_TAG], size, szFunc, paramAndLine, tagOwner);
#endif
		}
		else
			ret = CascadeBufferMalloc(&pMemoryContext->cascadeLogPool[poolIndex], size, szFunc, paramAndLine, tagOwner);
	}
#endif
	if (err < 0)
		BUG_REPORT(pMemoryContext, szFunc, paramAndLine & 0x0000FFFF, err, size);
	else if (ret == NULL)
		BUG_REPORT(pMemoryContext, szFunc, paramAndLine & 0x0000FFFF, -BUF_WARN_MEMORY_SHORTAGE, size);
	return ret;
}

int __BUF_Free(BufManHandle_t handle, u8* ptr, const char* szFunc, u32 line)
{
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, handle);
	int err = 0;
	u8 phyPoolIndex;

	BUF_ASSERT_DBG(ptr != NULL);
	if (ptr == NULL)
	{
		err = -BUF_ERR_NULL_PTR;
	}
	else
	{
		BUF_ASSERT_DBG(ptr >= pMemoryContext->pPhyBufBaseAddr && ptr < pMemoryContext->pPhyBufLimitAddr);
		if (ptr >= pMemoryContext->pPhyBufBaseAddr && ptr < pMemoryContext->pPhyBufLimitAddr)
		{
			phyPoolIndex = pMemoryContext->offsetToPhyPoolIndex[((u8*)ptr - pMemoryContext->pPhyBufBaseAddr) >> MEM_RESERVED_GRANULARITY_ORDER];
			if (phyPoolIndex&DIRECT_BUF_TAG)
			{
				err = DirectBufferFree(&pMemoryContext->directPool[phyPoolIndex&(~DIRECT_BUF_TAG)], ptr);
			}
			else
			{
				CascadePhyBufPool_t* pPhyPool = &pMemoryContext->cascadePhyPool[phyPoolIndex];
				u32 offset = ptr - pPhyPool->bufBaseAddr;
				err = CascadeBufferFree(pPhyPool->pPhyBufMeta[offset >> pPhyPool->perBufSizeOrder].pLogBufPool, offset);
			}
		}
		else
		{
			err = -BUF_ERR_INVALID_PTR;
		}
	}
	if (err<0)
	{
		BUG_REPORT(pMemoryContext, szFunc, line, err, ADDR_2_U32(ptr));
	}
	return err;
}

u32   __BUF_GetFreeBufferNum(BufManHandle_t handle, u32 size)
{
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, handle);
	u8 poolIndex;
#if AUTO_MALLOC_DIRECT_BUFFER == 0
	if (IsDirectBufferWanted(size))
	{
		BUF_ASSERT_DBG(DIRECT_BUFFER_ID(size)<pMemoryContext->directPoolNum);
		BUF_ASSERT_DBG(DIRECT_BUFFER_WANTED_SIZE(size) <= (1 << pMemoryContext->directPool[DIRECT_BUFFER_ID(size)].perBufSizeOrder));
		if (DIRECT_BUFFER_ID(size) >= pMemoryContext->directPoolNum || DIRECT_BUFFER_WANTED_SIZE(size)>(1 << pMemoryContext->directPool[DIRECT_BUFFER_ID(size)].perBufSizeOrder))
			return 0;
		else
			return pMemoryContext->directPool[DIRECT_BUFFER_ID(size)].freeBufCount;
	}
	else
	{
		BUF_ASSERT_DBG(size <= pMemoryContext->maxBufferSize);
		if (size> pMemoryContext->maxBufferSize)
		{
			return 0;
		}
		poolIndex = pMemoryContext->sizeToLogPoolIndex[(size + (1 << MEM_APP_MALLOC_GRANULARITY_ORDER) - 1) >> MEM_APP_MALLOC_GRANULARITY_ORDER];
		return pMemoryContext->cascadeLogPool[poolIndex].nbLogBufPerPhyBuf*pMemoryContext->cascadeLogPool[poolIndex].pPhyBufPool->freeBufferCount;
	}
#else  
	if (size> pMemoryContext->maxBufferSize)return 0;
	poolIndex = pMemoryContext->sizeToLogPoolIndex[(size + (1 << MEM_APP_MALLOC_GRANULARITY_ORDER) - 1) >> MEM_APP_MALLOC_GRANULARITY_ORDER];
	if (poolIndex&DIRECT_BUF_TAG)//direct buffer
	{
#if TRY_BEST_MALLOC > 0  
		// test test test
		u8 id;
		u32 sum = 0;
		for (id = poolIndex&~DIRECT_BUF_TAG; id < pMemoryContext->directPoolNum; id++)
		{
			sum += pMemoryContext->directPool[id].freeBufCount;
		}
		return sum;
#else
		BufferCache_t* pCache = CUR_THREAD_CACHE_OF_CASCADE_POOL(&pMemoryContext->directPool[poolIndex&~DIRECT_BUF_TAG]);
		return pMemoryContext->directPool[poolIndex&~DIRECT_BUF_TAG].freeBufCount + pCache->top;
#endif
	}
	else
	{
		BufferCache_t* pCache = CUR_THREAD_CACHE_OF_CASCADE_POOL(&pMemoryContext->cascadeLogPool[poolIndex]);
		return pMemoryContext->cascadeLogPool[poolIndex].nbLogBufPerPhyBuf*pMemoryContext->cascadeLogPool[poolIndex].pPhyBufPool->freeBufferCount
			+ pMemoryContext->cascadeLogPool[poolIndex].freeBufferCount + pCache->top;
	}
#endif
}


void __BUF_PrintStatistic(char* str, BufManHandle_t in_handle)
{
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, in_handle);
	u32 i;
	BUF_ASSERT(str != NULL);

	str += sprintf(str, "%8s Buffer Manager Statics\n", pMemoryContext->szName);
	str += sprintf(str, "    POOL     SIZE    TOTAL   USED    MAX_USED\n");
	for (i = 0; i<pMemoryContext->directPoolNum; i++)
	{
		str += sprintf(str, "DirectPool%d  % 5d  % 7d  % 7d % 7d\n", i,
			1 << pMemoryContext->directPool[i].perBufSizeOrder,
			pMemoryContext->directPool[i].bufTotalCount,
			pMemoryContext->directPool[i].bufTotalCount - pMemoryContext->directPool[i].freeBufCount,
#if DETECT_MAX_MEMORY_COST  > 0
			pMemoryContext->directPool[i].bufTotalCount - pMemoryContext->directPool[i].minFreeBufferCount
#else
			- 1 //not detected
#endif
			);
	}

	for (i = 0; i<pMemoryContext->cascadePhyPoolNum; i++)
	{
		str += sprintf(str, "cascadePhyPool%d  % 5d  % 7d  % 7d % 7d\n", i,
			1 << pMemoryContext->cascadePhyPool[i].perBufSizeOrder,
			pMemoryContext->cascadePhyPool[i].totalBufferCount,
			pMemoryContext->cascadePhyPool[i].totalBufferCount - pMemoryContext->cascadePhyPool[i].freeBufferCount,
#if DETECT_MAX_MEMORY_COST  > 0
			pMemoryContext->cascadePhyPool[i].totalBufferCount - pMemoryContext->cascadePhyPool[i].minFreeBufferCount
#else
			- 1 //not detected
#endif
			);
	}
}


void __BUF_FlushCache(BufManHandle_t in_handle)
{
#if SUPPORT_PER_THREAD_CACHE > 0
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, in_handle);
	BufferCache_t* pCache = NULL;
	//  MemoryAllocInfor_t* pBufferContext=NULL;
	u32 i;

	for (i = 0; i<pMemoryContext->directPoolNum; i++)
	{
		pCache = CUR_THREAD_CACHE_OF_DIRECT_POOL(&pMemoryContext->directPool[i]);
		if (pCache != NULL)
		{
			if (pCache->top > 0)
			{
				DirectBufferReleaseCache(&pMemoryContext->directPool[i], pCache, pCache->top);
			}
		}
	}

	for (i = 0; i<pMemoryContext->cascadeLogPoolNum; i++)
	{
		pCache = CUR_THREAD_CACHE_OF_CASCADE_POOL(&pMemoryContext->cascadeLogPool[i]);
		if (pCache->top > 0)
			CascadeBufferReleaseCache(&pMemoryContext->cascadeLogPool[i], pCache, pCache->top);
	}
#else
	in_handle = in_handle;
#endif
}


void __BUF_PrintOneBufferAllocInfor(char* out_str, BufManHandle_t in_handle, u8* in_buffer)
{
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, in_handle);
	MemoryAllocInfor_t* pAllocInfor = NULL;
	u32 offset;
	u8 phyPoolIndex;
	BUF_ASSERT(out_str != NULL);
	BUF_ASSERT_DBG(in_buffer != NULL && (in_buffer >= pMemoryContext->pPhyBufBaseAddr && in_buffer < pMemoryContext->pPhyBufLimitAddr));
	if (in_buffer != NULL && (in_buffer >= pMemoryContext->pPhyBufBaseAddr && in_buffer < pMemoryContext->pPhyBufLimitAddr))
	{
		phyPoolIndex = pMemoryContext->offsetToPhyPoolIndex[((u8*)in_buffer - pMemoryContext->pPhyBufBaseAddr) >> MEM_RESERVED_GRANULARITY_ORDER];
		if (phyPoolIndex&DIRECT_BUF_TAG)
		{
			DirectBufPool_t* pDirectPool = &pMemoryContext->directPool[phyPoolIndex&(~DIRECT_BUF_TAG)];
			offset = in_buffer - pDirectPool->bufBaseAddr;
			pAllocInfor = &pDirectPool->metaArray[offset >> pDirectPool->perBufSizeOrder];
		}
		else
		{
			CascadePhyBufPool_t* pPhyPool;
			pPhyPool = &pMemoryContext->cascadePhyPool[phyPoolIndex];
			offset = in_buffer - pPhyPool->bufBaseAddr;
			pAllocInfor = &pPhyPool->pLogBufMeta[offset >> pPhyPool->minCascadeBufSizeOrder];
		}
		if (pAllocInfor != NULL)
		{
			sprintf(out_str, "Buffer Addr=%08X refer=%d,last allocated %d bytes by %s-%d at time %d with tag32=%d(0x%08X) param16=%d(0x%04d)\n",
				ADDR_2_U32(pAllocInfor->buffer),
				pAllocInfor->referCount,
				pAllocInfor->size,
				pAllocInfor->szFuncName,
				pAllocInfor->paramAndLine & 0x0000FFFF,
				pAllocInfor->time,
				pAllocInfor->tagOwner,
				pAllocInfor->tagOwner,
				pAllocInfor->paramAndLine >> 16,
				pAllocInfor->paramAndLine >> 16);
		}
	}
	else
	{
		sprintf(out_str, "Invalid Address=%08X\n", ADDR_2_U32(in_buffer));
	}
}

// ====================== URGLY FUNCTIONS ========================================

u8* __BUF_GetAllocatedBufferBaseAddr(BufManHandle_t handle, u8* ptr, const char* szFunc, u32 line)
{
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, handle);
	int err = 0;
	u8 phyPoolIndex;

	BUF_ASSERT_DBG(ptr != NULL);
	if (ptr != NULL)//more likely
	{
		BUF_ASSERT_DBG(ptr >= pMemoryContext->pPhyBufBaseAddr && ptr < pMemoryContext->pPhyBufLimitAddr);
		if (ptr >= pMemoryContext->pPhyBufBaseAddr && ptr < pMemoryContext->pPhyBufLimitAddr)
		{
			phyPoolIndex = pMemoryContext->offsetToPhyPoolIndex[((u8*)ptr - pMemoryContext->pPhyBufBaseAddr) >> MEM_RESERVED_GRANULARITY_ORDER];
			if (phyPoolIndex&DIRECT_BUF_TAG)
			{
				DirectBufPool_t* pDirectPool = &pMemoryContext->directPool[phyPoolIndex&(~DIRECT_BUF_TAG)];
				return pDirectPool->bufBaseAddr + (((ptr - pDirectPool->bufBaseAddr) >> pDirectPool->perBufSizeOrder) << pDirectPool->perBufSizeOrder);
			}
			else
			{
				CascadePhyBufPool_t* pPhyPool;
				CascadeLogBufPool_t* pLogPool;
				u32 offset;
				u32 phyIndex, logIndex;
				pPhyPool = &pMemoryContext->cascadePhyPool[phyPoolIndex];
				offset = ptr - pPhyPool->bufBaseAddr;
				phyIndex = (offset >> pPhyPool->perBufSizeOrder);
				pLogPool = pPhyPool->pPhyBufMeta[phyIndex].pLogBufPool;
				logIndex = ((offset&pPhyPool->perBufAddrMask) >> pLogPool->perBufSizeOrder);
				return pPhyPool->pPhyBufMeta[phyIndex].pCascadeBuffer[logIndex*pLogPool->metaStep].buffer;
			}
		}
		else
		{
			err = -BUF_ERR_INVALID_PTR;
		}
	}
	else
	{

		err = -BUF_ERR_NULL_PTR;
	}
	// error if reach here
	BUG_REPORT(pMemoryContext, szFunc, line, err, ADDR_2_U32(ptr));
	return NULL;
}

u32 __BUF_GetAllocatedBufferSize(BufManHandle_t handle, u8* ptr, const char* szFunc, u32 line)
{
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, handle);
	int err = 0;
	u8 phyPoolIndex;

	BUF_ASSERT_DBG(ptr != NULL);
	if (ptr != NULL)//more likely
	{
		BUF_ASSERT_DBG(ptr >= pMemoryContext->pPhyBufBaseAddr && ptr < pMemoryContext->pPhyBufLimitAddr);
		if (ptr >= pMemoryContext->pPhyBufBaseAddr && ptr < pMemoryContext->pPhyBufLimitAddr)
		{
			phyPoolIndex = pMemoryContext->offsetToPhyPoolIndex[((u8*)ptr - pMemoryContext->pPhyBufBaseAddr) >> MEM_RESERVED_GRANULARITY_ORDER];
			if (phyPoolIndex&DIRECT_BUF_TAG)
			{
#if TRY_BEST_MALLOC > 0
				u8 id = phyPoolIndex&(~DIRECT_BUF_TAG);
				DirectBufPool_t* pDirectPool = &pMemoryContext->directPool[id];
				u32 size = pDirectPool->metaArray[((ptr - pDirectPool->bufBaseAddr) >> pDirectPool->perBufSizeOrder)].size;
				id = pMemoryContext->sizeToLogPoolIndex[(size + (1 << MEM_APP_MALLOC_GRANULARITY_ORDER) - 1) >> MEM_APP_MALLOC_GRANULARITY_ORDER];
				BUF_ASSERT(id&DIRECT_BUF_TAG);

				return 1 << pMemoryContext->directPool[id&(~DIRECT_BUF_TAG)].perBufSizeOrder;
#else
				return 1 << pMemoryContext->directPool[phyPoolIndex&(~DIRECT_BUF_TAG)].perBufSizeOrder;
#endif
			}
			else
			{
				CascadePhyBufPool_t* pPhyPool;
				CascadeLogBufPool_t* pLogPool;
				u32 offset;
				u32 phyIndex;
				pPhyPool = &pMemoryContext->cascadePhyPool[phyPoolIndex];
				offset = ptr - pPhyPool->bufBaseAddr;
				phyIndex = (offset >> pPhyPool->perBufSizeOrder);
				pLogPool = pPhyPool->pPhyBufMeta[phyIndex].pLogBufPool;
				return pLogPool->perBufferSize;
			}
		}
		else
		{
			err = -BUF_ERR_INVALID_PTR;
		}
	}
	else
		err = -BUF_ERR_NULL_PTR;
	// error if reach here
	BUG_REPORT(pMemoryContext, szFunc, line, err, ADDR_2_U32(ptr));
	return 0;
}

inline int DirectBufferIncreaseRefer(DirectBufPool_t* pContext, u8* ptr)
{
	u32 index;
	u32 snapshot;
	index = ((ptr - pContext->bufBaseAddr) >> pContext->perBufSizeOrder);
	BUF_ASSERT(index<pContext->bufTotalCount);

	do
	{
		snapshot = pContext->metaArray[index].referCount;
		if (snapshot == 0)break;
	} while (!ATOMIC_COMPARE_AND_SET(&pContext->metaArray[index].referCount, snapshot, snapshot + 1));
	return snapshot>0 ? 0 : -BUF_ERR_UNMALLOC_MEMORY;
}

inline int DirectBufferDecreaseRefer(DirectBufPool_t* pContext, u8* ptr)
{
	u32 index;
	u32 snapshot;
	index = ((ptr - pContext->bufBaseAddr) >> pContext->perBufSizeOrder);
	BUF_ASSERT(index<pContext->bufTotalCount);

	do
	{
		snapshot = pContext->metaArray[index].referCount;
		if (snapshot == 0)break;
	} while (!ATOMIC_COMPARE_AND_SET(&pContext->metaArray[index].referCount, snapshot, snapshot - 1));
	if (snapshot == 1)
	{
#if SUPPORT_PER_THREAD_CACHE > 0
		BufferCache_t* pCache = CUR_THREAD_CACHE_OF_DIRECT_POOL(pContext);
		cache_stack_push(pCache, &pContext->metaArray[index]);
		if (pCache->top >= pCache->maxWaterLevel)
			DirectBufferReleaseCache(pContext, pCache, pCache->maxWaterLevel - pCache->releaseWaterLevel);
#else
		atomic_list_add_head(&pContext->freeListHead, NODE_OF_LIST(&pContext->metaArray[index]));
		ATOMIC_INC(&pContext->freeBufCount);
#endif
	}
	return snapshot>0 ? 0 : -BUF_ERR_UNMALLOC_MEMORY;
}

inline int CascadeBufferIncreaseRefer(CascadeLogBufPool_t* pLogPool, u32 offset)
{
	u32 snapshot;
	u8 logBufferIndex;

	CascadePhyBufPool_t* pPhyPool = pLogPool->pPhyBufPool;
	CascadePhyBufContext_t* pPhyBufferContext = NULL;
	MemoryAllocInfor_t* pAllocMeta;
	pPhyBufferContext = &pPhyPool->pPhyBufMeta[offset >> pPhyPool->perBufSizeOrder];
	logBufferIndex = ((offset&pPhyPool->perBufAddrMask) >> pLogPool->perBufSizeOrder);
	pAllocMeta = pPhyBufferContext->pCascadeBuffer + logBufferIndex*pLogPool->metaStep;

	do
	{
		snapshot = pAllocMeta->referCount;
		if (snapshot == 0)break;
	} while (!ATOMIC_COMPARE_AND_SET(&pAllocMeta->referCount, snapshot, snapshot + 1));
	return snapshot>0 ? 0 : -BUF_ERR_UNMALLOC_MEMORY;
}


inline int CascadeBufferDecreaseRefer(CascadeLogBufPool_t* pLogPool, u32 offset)
{
	u32 snapshot;
	u8 logBufferIndex;

	CascadePhyBufPool_t* pPhyPool = pLogPool->pPhyBufPool;
	CascadePhyBufContext_t* pPhyBufferContext = NULL;
	MemoryAllocInfor_t* pAllocMeta;
	pPhyBufferContext = &pPhyPool->pPhyBufMeta[offset >> pPhyPool->perBufSizeOrder];
	logBufferIndex = ((offset&pPhyPool->perBufAddrMask) >> pLogPool->perBufSizeOrder);
	pAllocMeta = pPhyBufferContext->pCascadeBuffer + logBufferIndex*pLogPool->metaStep;

	do
	{
		snapshot = pAllocMeta->referCount;
		if (snapshot == 0)break;
	} while (!ATOMIC_COMPARE_AND_SET(&pAllocMeta->referCount, snapshot, snapshot - 1));

	if (snapshot == 1)
	{
#if THREAD_LOCK_ENABLE > 0
		{
			BufferCache_t* pCache = CUR_THREAD_CACHE_OF_CASCADE_POOL(pLogPool);
			cache_stack_push(pCache, pAllocMeta);
			if (pCache->top == pCache->maxWaterLevel)
				CascadeBufferReleaseCache(pLogPool, pCache, pCache->maxWaterLevel - pCache->releaseWaterLevel);
		}
#else
		if (ATOMIC_DEC_AND_FETCH(&pPhyBufferContext->referCount) == 0)
		{
			atomic_list_add_head(&pPhyPool->freeListHead, NODE_OF_LIST(pPhyBufferContext));
			ATOMIC_INC(&pPhyPool->freeBufferCount);
		}
#endif
	}
	return snapshot>0 ? 0 : -BUF_ERR_UNMALLOC_MEMORY;
}


int __BUF_IncreaseRefer(BufManHandle_t handle, u8* ptr, const char* szFunc, u32 line)
{
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, handle);
	int err = 0;
	u8 phyPoolIndex;

	BUF_ASSERT_DBG(ptr != NULL);
	if (ptr == NULL)
	{
		err = -BUF_ERR_NULL_PTR;
	}
	else
	{
		BUF_ASSERT_DBG(ptr >= pMemoryContext->pPhyBufBaseAddr && ptr < pMemoryContext->pPhyBufLimitAddr);
		if (ptr >= pMemoryContext->pPhyBufBaseAddr && ptr < pMemoryContext->pPhyBufLimitAddr)
		{
			phyPoolIndex = pMemoryContext->offsetToPhyPoolIndex[((u8*)ptr - pMemoryContext->pPhyBufBaseAddr) >> MEM_RESERVED_GRANULARITY_ORDER];
			if (phyPoolIndex&DIRECT_BUF_TAG)
			{
				err = DirectBufferIncreaseRefer(&pMemoryContext->directPool[phyPoolIndex&(~DIRECT_BUF_TAG)], ptr);
			}
			else
			{
				CascadePhyBufPool_t* pPhyPool = &pMemoryContext->cascadePhyPool[phyPoolIndex];
				u32 offset = ptr - pPhyPool->bufBaseAddr;
				err = CascadeBufferIncreaseRefer(pPhyPool->pPhyBufMeta[offset >> pPhyPool->perBufSizeOrder].pLogBufPool, offset);
			}
		}
		else
		{
			err = -BUF_ERR_INVALID_PTR;
		}
	}
	if (err<0)
	{
		BUG_REPORT(pMemoryContext, szFunc, line, err, ADDR_2_U32(ptr));
	}
	return err;
}

int __BUF_DecreaseRefer(BufManHandle_t handle, u8* ptr, const char* szFunc, u32 line)
{
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, handle);
	int err = 0;
	u8 phyPoolIndex;

	BUF_ASSERT_DBG(ptr != NULL);
	if (ptr == NULL)
	{
		err = -BUF_ERR_NULL_PTR;
	}
	else
	{
		BUF_ASSERT_DBG(ptr >= pMemoryContext->pPhyBufBaseAddr && ptr < pMemoryContext->pPhyBufLimitAddr);
		if (ptr >= pMemoryContext->pPhyBufBaseAddr && ptr < pMemoryContext->pPhyBufLimitAddr)
		{
			phyPoolIndex = pMemoryContext->offsetToPhyPoolIndex[((u8*)ptr - pMemoryContext->pPhyBufBaseAddr) >> MEM_RESERVED_GRANULARITY_ORDER];
			if (phyPoolIndex&DIRECT_BUF_TAG)
			{
				err = DirectBufferDecreaseRefer(&pMemoryContext->directPool[phyPoolIndex&(~DIRECT_BUF_TAG)], ptr);
			}
			else
			{
				CascadePhyBufPool_t* pPhyPool = &pMemoryContext->cascadePhyPool[phyPoolIndex];
				u32 offset = ptr - pPhyPool->bufBaseAddr;
				err = CascadeBufferDecreaseRefer(pPhyPool->pPhyBufMeta[offset >> pPhyPool->perBufSizeOrder].pLogBufPool, offset);
			}
		}
		else
		{
			err = -BUF_ERR_INVALID_PTR;
		}
	}
	if (err<0)
	{
		BUG_REPORT(pMemoryContext, szFunc, line, err, ADDR_2_U32(ptr));
	}
	return err;
}

// Return:
//       < 0: error code
//       ==0: no error but not match, so not free
//       > 0: succeed to free
inline int DirectBufferFreeWithAttr(DirectBufPool_t* pContext, u8* ptr, const u32* attr, u32 nbAttr)
{
	u32 index;
	u32 prevCount;
	u32 i;
	int err = 0;

	index = ((ptr - pContext->bufBaseAddr) >> pContext->perBufSizeOrder);
	BUF_ASSERT_DBG(index<pContext->bufTotalCount);
	for (i = 0; i<nbAttr; i++)
	{
		if (pContext->metaArray[index].tagOwner == attr[i])
			break;
	}
	if (i<nbAttr)
	{
		err = 1;
		prevCount = ATOMIC_FETCH_AND_CLR(&pContext->metaArray[index].referCount);
		if (prevCount == 0)//is free or not allocated
		{
			BUF_ASSERT_DBG(0);
			err = -BUF_ERR_UNMALLOC_MEMORY;
		}
		else
		{
#if SUPPORT_PER_THREAD_CACHE > 0
			BufferCache_t* pCache = CUR_THREAD_CACHE_OF_DIRECT_POOL(pContext);
			cache_stack_push(pCache, &pContext->metaArray[index]);
			if (pCache->top == pCache->maxWaterLevel)
			{
				DirectBufferReleaseCache(pContext, pCache, pCache->maxWaterLevel - pCache->releaseWaterLevel);
			}
#else
			atomic_list_add_head(&pContext->freeListHead, NODE_OF_LIST(&pContext->metaArray[index]));
			ATOMIC_INC(&pContext->freeBufCount);
#endif
		}
	}
	return err;
}

// Return:
//       < 0: error code
//       ==0: no error but not match, so not free
//       > 0: succeed to free
inline int CascadeBufferFreeWithAttr(CascadeLogBufPool_t* pLogPool, u32 offset, const u32* attr, u32 nbAttr)
{
	u8 logBufferIndex;
	u32 prevCount;
	u32 i;
	int err = 0;
	CascadePhyBufPool_t* pPhyPool = pLogPool->pPhyBufPool;
	CascadePhyBufContext_t* pPhyBufferContext = NULL;
	MemoryAllocInfor_t* pAllocMeta;
	pPhyBufferContext = &pPhyPool->pPhyBufMeta[offset >> pPhyPool->perBufSizeOrder];
	logBufferIndex = ((offset&pPhyPool->perBufAddrMask) >> pLogPool->perBufSizeOrder);
	pAllocMeta = pPhyBufferContext->pCascadeBuffer + logBufferIndex*pLogPool->metaStep;

	for (i = 0; i<nbAttr; i++)
	{
		if (pAllocMeta->tagOwner == attr[i])
			break;
	}
	if (i<nbAttr)
	{
#if THREAD_LOCK_ENABLE > 0
		prevCount = 0;
		err = CascadeBufferFree(pLogPool, offset);
		if (err == 0)err = 1;
#else
		err = 1;
		prevCount = ATOMIC_FETCH_AND_CLR(&pAllocMeta->referCount);
		if (prevCount == 0)
		{
			BUF_ASSERT_DBG(0);
			err = -BUF_ERR_UNMALLOC_MEMORY;
		}
		else
		{
			ATOMIC_DEC(&pPhyBufferContext->referCount);
			if (pPhyBufferContext->referCount == 0)
			{
				atomic_list_add_head(&pPhyPool->freeListHead, NODE_OF_LIST(pPhyBufferContext));
				ATOMIC_INC(&pPhyPool->freeBufferCount);
			}
		}
#endif
	}
	return err;
}


inline int __BUF_FreeWithAttr(BufferManager_t* pMemoryContext, u8*ptr, const u32* attr, u32 nbAttr)
{
	int err = 0;
	u8 phyPoolIndex;
	if (ptr == NULL)
	{
		BUF_ASSERT_DBG(0);
		err = -BUF_ERR_NULL_PTR;
	}
	else
	{
		BUF_ASSERT_DBG(ptr >= pMemoryContext->pPhyBufBaseAddr && ptr < pMemoryContext->pPhyBufLimitAddr);
		if (ptr >= pMemoryContext->pPhyBufBaseAddr && ptr < pMemoryContext->pPhyBufLimitAddr)
		{
			phyPoolIndex = pMemoryContext->offsetToPhyPoolIndex[((u8*)ptr - pMemoryContext->pPhyBufBaseAddr) >> MEM_RESERVED_GRANULARITY_ORDER];
			if (phyPoolIndex&DIRECT_BUF_TAG)
			{
				err = DirectBufferFreeWithAttr(&pMemoryContext->directPool[phyPoolIndex&(~DIRECT_BUF_TAG)], ptr, attr, nbAttr);
			}
			else
			{
				CascadePhyBufPool_t* pPhyPool = &pMemoryContext->cascadePhyPool[phyPoolIndex];
				u32 offset = ptr - pPhyPool->bufBaseAddr;
				err = CascadeBufferFreeWithAttr(pPhyPool->pPhyBufMeta[offset >> pPhyPool->perBufSizeOrder].pLogBufPool, offset, attr, nbAttr);
			}
		}
		else
		{
			err = -BUF_ERR_INVALID_PTR;
		}
	}
	return err;
}


void  __BUF_BatchFreeWithAttr(BufManHandle_t in_handle, void** in_out_list, u32 in_num, const u32* in_attr, u32 in_nbAttr, const char* szFunc, u32 line)
{
	u32 i;
	int err = 0;
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, in_handle);
	for (i = 0; i<in_num; i++)
	{
		err = __BUF_FreeWithAttr(pMemoryContext, (u8*)in_out_list[i], in_attr, in_nbAttr);
		if (err<0)
			BUG_REPORT(pMemoryContext, szFunc, line, err, ADDR_2_U32(in_out_list[i]));
		//    else
		//      in_out_list[i] = NULL;
	}
}


