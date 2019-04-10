/***********************************************************************************/
/*!
* @file ee_buffer_manage.c
*
* @brief
*    Implement for eagle eye buffer
*
* Description:
*    Implement for eagle eye buffer
*
* Content :
*
* @section history_sec History
* @code
|----------------|-----------------------------------------|-----------|----------|
|   Name         |         Description                     |   Date    | Version  |
|----------------|-----------------------------------------|-----------|----------|
| yuquanz        | Creation                                | JULY-1-14 | NO VER   |
* @endcode
*/

#define EXTERN 
#include "buffer_manage_internal.h"
#include "ee_buffer_manage.h"
#include "EeCommon.h"

#include <stdio.h>

static const PhyBufPoolConfig_t ee_buffer_config[] =
{
#if AUTO_MALLOC_DIRECT_BUFFER > 0
	{ DIRECT_BUF_POOL, 5, BYTE_TO_GRANULARITY(0x100000 * 15), 0x0020 },
	{ DIRECT_BUF_POOL, 6, BYTE_TO_GRANULARITY(0x100000 * 15), 0x0020 },
	{ DIRECT_BUF_POOL, 7, BYTE_TO_GRANULARITY(0x100000 * 15), 0x0020 },
	//{ DIRECT_BUF_POOL, 8, BYTE_TO_GRANULARITY(0x100000 * 15), 0x0020 },

#else
	{ DIRECT_BUF_POOL, 5, BYTE_TO_GRANULARITY(0x100000 * 2), 0x0020 },//NODE
	{ DIRECT_BUF_POOL, 5, BYTE_TO_GRANULARITY(0x100000 * 13), 0x0020 },//CONTEXT
#endif
	//  {CASECADE_BUF_POOL,   11,    BYTE_TO_GRANULARITY(0x100000*170), 0x0E00},// 2K, 512->2048
	//  {CASECADE_BUF_POOL,   14,    BYTE_TO_GRANULARITY(0x100000*48), 0x7000},//16K, 4K->16K
	{ CASECADE_BUF_POOL, 14, BYTE_TO_GRANULARITY(0x100000 * 208), 0x7E00 },//16K, 512->16K
	{ 0, 0, 0, 0 }
};

static const u8 offsetToPhyPoolIndex[] = {
	0x80, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
};
static const u8 sizeToLogPoolIndex[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
	0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
	0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
	0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05,
};


int EE_BufInitialize()
{
	ee_buf_handle = BUF_CreateManager("EagleEye", ee_buffer_config, offsetToPhyPoolIndex, sizeToLogPoolIndex);

	return 0;
}

void BUF_Info_Show()
{
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, ee_buf_handle);
	u32 i;
	u32 end;
	EELOG_INFO("New Buffer Management");

	for (i = 0; i<pMemoryContext->directPoolNum; i++)
	{
		EELOG_INFO(
			"direct poolId(" << 
			i << 
			") BaseAddr (" << 
			ADDR_2_U32(pMemoryContext->directPool[i].bufBaseAddr) << 
			") BufSizeOrder (" << 
			pMemoryContext->directPool[i].perBufSizeOrder << 
			") NbBuffer (" << 
			pMemoryContext->directPool[i].bufTotalCount << 
			") CurrentFree ("
			<< pMemoryContext->directPool[i].freeBufCount << 
			") MinFree (" << 
			pMemoryContext->directPool[i].minFreeBufferCount << 
			") AllocCount (" <<
			GET_MALLOC_COUNT(&pMemoryContext->directPool[i]) << 
			") CacheMiss (" << 
			GET_CACHE_MISS(&pMemoryContext->directPool[i]) << 
			")");
	}

	for (i = 0; i<pMemoryContext->cascadePhyPoolNum; i++)
	{
		EELOG_INFO(
			"physical poolId(" <<
			i <<
			") BaseAddr (" <<
			ADDR_2_U32(pMemoryContext->cascadePhyPool[i].bufBaseAddr) <<
			") BufSizeOrder (" <<
			pMemoryContext->cascadePhyPool[i].perBufSizeOrder <<
			") NbBuffer (" <<
			pMemoryContext->cascadePhyPool[i].totalBufferCount <<
			") CurrentFree (" << 
			pMemoryContext->cascadePhyPool[i].freeBufferCount <<
			") MinFree (" <<
			pMemoryContext->cascadePhyPool[i].minFreeBufferCount <<
			")");
	}

	EELOG_INFO("BUF_LOCAL_TIME (" << 
		BUF_LOCAL_TIME << 
		") BUF_nullPointerCounter (" << 
		pMemoryContext->nullPointerCounter << 
		") BUF_multipleEntryCounter ( 0 ) BUF_doubleDeallocationCounter (" << 
		pMemoryContext->unallocationCounter << 
		") BUF_magicNumberCheckFailCounter (" << 
		pMemoryContext->overSizeCounter << 
		") UL BUF leak detected (" << 
		pMemoryContext->invalidPointerCounter << 
		") workArounded in PDUArrayInit (" << 
		pMemoryContext->depleteCounter << 
		")");


	//printf(
	//	"FreeNodeBufferNb=%d, FreeCPoolBufferNb=%d, total_leak_bpdN_buf_released=%d, total_leak_bpdD_buf_released=%d\n",
	//	EE_GetFreeNodeBufferNb(), EE_GetFreeNodeBufferNb(), 0, 0
	//	);

	EELOG_INFO("BUF_LOCAL_TIME (" << 
		BUF_LOCAL_TIME <<
		") nullPtr (" << 
		pMemoryContext->nullPointerCounter << 
		") unalloc/re dealloc (" << 
		pMemoryContext->unallocationCounter << 
		") oversize (" << 
		pMemoryContext->overSizeCounter << 
		") overWrite (" << 
		pMemoryContext->overWriteCounter << 
		") invalidPtr (" << 
		pMemoryContext->invalidPointerCounter << 
		") deplete (" << 
		pMemoryContext->depleteCounter << 
		")");


	EELOG_INFO("BUF Error And Warning Logs");
	end = pMemoryContext->errorLogIndex;
	end &= LOG_DEPTH - 1;
	i = pMemoryContext->errorLogIndex + 1;
	i &= LOG_DEPTH - 1;
	while (i != end)
	{
		if (pMemoryContext->errorLog[i].szBufFunc != NULL)
		{
			EELOG_INFO("" << 
				pMemoryContext->errorLog[i].szBufFunc << 
				"-" << 
				pMemoryContext->errorLog[i].line << 
				":" << 
				pMemoryContext->errorLog[i].error << 
				" " << pMemoryContext->errorLog[i].param);
		}
		i++;
		i &= LOG_DEPTH - 1;
	}
}

void BUF_Info_Reset(void)
{
	BufferManager_t* pMemoryContext = TRANS(BufferManager_t, ee_buf_handle);
	ATOMIC_FETCH_AND_CLR(&pMemoryContext->unallocationCounter);
	ATOMIC_FETCH_AND_CLR(&pMemoryContext->overWriteCounter);
	ATOMIC_FETCH_AND_CLR(&pMemoryContext->overSizeCounter);
	ATOMIC_FETCH_AND_CLR(&pMemoryContext->nullPointerCounter);
	ATOMIC_FETCH_AND_CLR(&pMemoryContext->invalidPointerCounter);
	ATOMIC_FETCH_AND_CLR(&pMemoryContext->depleteCounter);
}
