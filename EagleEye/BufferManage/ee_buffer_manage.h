/***********************************************************************************/
/*!
* @file ee_buffer_manage.h
*
* @brief
*    App interfaces provided by middle level
*
* Description:
*    App interfaces provided by middle level
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

#ifndef __EE_BUFFER_MANAGE_INCLUDE__
#define __EE_BUFFER_MANAGE_INCLUDE__

#include "buffer_manage.h"

#ifdef __cplusplus
extern "C" {
#endif
	int EE_BufInitialize();
#ifdef __cplusplus
}
#endif

#define EEBUF_INIT() EE_BufInitialize()
#define EEBUF_SHOW() BUF_Info_Show()

#ifndef EXTERN
#define EXTERN extern
#endif

//Please define value accroding 'l2dl_buffer_config'
#define NODE_BUFFER_ID      0
#define CONTEXT_BUFFER_ID   1

#define PER_CONTEXT_BUFFER_SIZE_ORDER 5
#define PER_CONTEXT_BUFFER_SIZE (1<<PER_CONTEXT_BUFFER_SIZE_ORDER)

EXTERN BufManHandle_t ee_buf_handle;

#define EE_AllocBuffer(size, tag32, param16) __BUF_Alloc(ee_buf_handle, size,tag32, param16)
#define EE_DeallocBuffer(ptr) __BUF_Dealloc(ee_buf_handle,(u8*)(ptr))

#define EE_ALLOC(size) EE_AllocBuffer(size, 0, 0)
#define EE_FREE(ptr)   EE_DeallocBuffer(ptr)

#if AUTO_MALLOC_DIRECT_BUFFER > 0 //No C/N/D conception
#define EE_AllocNode(size,tag32,param16)      EE_AllocBuffer(size,tag32,param16)
#define EE_AllocContext(size,tag32,param16)   EE_AllocBuffer(size,tag32,param16)
#define EE_AllocData(size,tag32,param16)      EE_AllocBuffer(size,tag32,param16)
#else
#define EE_AllocNode(size,tag32,param16)      (NODE*)EE_AllocBuffer(DIRECT_MALLOC_REGION(size,NODE_BUFFER_ID),tag32,param16)
#define EE_AllocContext(size,tag32,param16)   EE_AllocBuffer(DIRECT_MALLOC_REGION(size,CONTEXT_BUFFER_ID),tag32,param16)
#define EE_AllocData(size,tag32,param16)      EE_AllocBuffer(size,tag32,param16)
#endif

// I don't think that the previous alloc/dealloc macros for node/Context are defined well.
// As for context, there are server types of context, so alloc macro should include 'size' param.
// As for node, it seems just defined for 'NODE' type, it will be better if add type check
// Prefer to define like this(compiler can detect error if misuse for other structer): 
//  #define L2DL_AllocNode(ptrSave) ptrSave =(NODE*)Alloc(sizeof(NODE))
//
#define EE_ObsoleteAllocData(trace,size) ((trace)!=NULL?EE_AllocData(size,trace[0],trace[2]):EE_AllocData(size,0,0))
#define EE_ObsoleteAllocContext(trace) ((trace)!=NULL?EE_AllocContext(PER_CONTEXT_BUFFER_SIZE,trace[0],trace[2]):EE_AllocContext(PER_CONTEXT_BUFFER_SIZE,0,0))
#define EE_ObsoleteAllocNode(trace) ((trace)!=NULL?EE_AllocNode(sizeof(NODE),trace[0],trace[2]):EE_AllocNode(sizeof(NODE),0,0))

//#define EE_NEW(type)  ( 1 ? ( ##type* ptr = static_cast<##type *>(EE_AllocBuffer((sizeof(##type) + sizeof(int)), 0, 0)), ptr->##type::##type(), 1) : 0)

//#define EE_DELETE(ptr, type) {ptr->~##type(); EE_DeallocBuffer(ptr);}

#define EE_DeallocNode EE_DeallocBuffer
#define EE_DeallocContext EE_DeallocBuffer
#define EE_DeallocData EE_DeallocBuffer

#define EE_BatchDeallocDataBuffer(in_list,in_nbElem)  __BUF_BatchFree(ee_buf_handle,(void**)in_list,in_nbElem)

#if AUTO_MALLOC_DIRECT_BUFFER > 0
#define EE_GetFreeNodeBufferNb() __BUF_GetFreeBufferNum(ee_buf_handle,sizeof(NODE))
#else
#define EE_GetFreeNodeBufferNb() __BUF_GetFreeBufferNum(ee_buf_handle,DIRECT_MALLOC_REGION(sizeof(NODE),NODE_BUFFER_ID))
#endif
#define EE_GetFreeDataBufferNum(size) __BUF_GetFreeBufferNum(ee_buf_handle,size)

void BUF_Info_Show();

// { Don't call these functions in new code. APPs should manage by themself.
#define EE_BatchDeallocDataBufferWithAttr(in_list,in_nbElem, in_arAttr, in_nbAttr) \
	__BUF_BatchFreeWithAttr(ee_buf_handle, (void**)(in_list), in_nbElem, in_arAttr, in_nbAttr, __func__, __LINE__)
#define EE_IncreaseDataBufferRefer(ptr) __BUF_IncreaseRefer(ee_buf_handle,ptr,__func__,__LINE__)
#define EE_DecreaseDataBufferRefer(ptr) __BUF_DecreaseRefer(ee_buf_handle,ptr,__func__,__LINE__)
#define EE_GetDataBufferBaseAddr(ptr) __BUF_GetAllocatedBufferBaseAddr(ee_buf_handle,ptr,__func__,__LINE__)
#define EE_GetAllocatedBufferSize(ptr) __BUF_GetAllocatedBufferSize(ee_buf_handle,ptr,__func__,__LINE__)
// }

#endif

