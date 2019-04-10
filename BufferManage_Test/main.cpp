#include <QtCore/QCoreApplication>

#include "ee_buffer_manage.h"
#include "buffer_manage_internal.h"

typedef struct
{
	u8* pBuffer;
	u32 size;
	u32 time;
	u8 bAlloc;
	u32 filler;
}ALLOC_INFOR;

void test_direct_buffer(BufManHandle_t handle, u32 size, u8 region, u32 totalBlockNum)
{
	int i;
	int j;

	void** arPtr = (void**)malloc(sizeof(void*)*totalBlockNum);

	BUF_ASSERT(__BUF_GetFreeBufferNum(handle, DIRECT_MALLOC_REGION(size, region)) == totalBlockNum);
	for (i = 0; i<totalBlockNum; i++)
	{
		arPtr[i] = __BUF_Alloc(handle, DIRECT_MALLOC_REGION(size, region), 0, 0);
		BUF_ASSERT(__BUF_GetFreeBufferNum(handle, DIRECT_MALLOC_REGION(size, region)) == totalBlockNum - i - 1);
		BUF_ASSERT(arPtr[i]);
		for (j = 0; j<i; j++)
		{
			BUF_ASSERT(arPtr[i] != arPtr[j]);
		}
	}
	BUF_ASSERT(__BUF_GetFreeBufferNum(handle, DIRECT_MALLOC_REGION(size, region)) == 0);
	for (i = 0; i<totalBlockNum; i++)
	{
		__BUF_Dealloc(handle, arPtr[i]);
	}
	free(arPtr);
	__BUF_FlushCache(handle);
	BUF_ASSERT(__BUF_GetFreeBufferNum(handle, DIRECT_MALLOC_REGION(size, region)) == totalBlockNum);
}

void test_cascade_buffer(BufManHandle_t handle, u32 size, u32 totalBlockNum)
{
	int i;
	int j;

	void** arPtr = (void**)malloc(sizeof(void*)*totalBlockNum);

	BUF_ASSERT(__BUF_GetFreeBufferNum(handle, size) == totalBlockNum);


	for (i = 0; i<totalBlockNum; i++)
	{
		arPtr[i] = __BUF_Alloc(handle, size, 0, 0);
		BUF_ASSERT(__BUF_GetFreeBufferNum(handle, size) == totalBlockNum - i - 1);
		BUF_ASSERT(arPtr[i]);
		for (j = 0; j<i; j++)
		{
			BUF_ASSERT(arPtr[i] != arPtr[j]);
		}
	}
	BUF_ASSERT(__BUF_GetFreeBufferNum(handle, size) == 0);
	for (i = 0; i<totalBlockNum; i++)
	{
		__BUF_Dealloc(handle, arPtr[i]);
	}
	free(arPtr);
	__BUF_FlushCache(handle);
	BUF_ASSERT(__BUF_GetFreeBufferNum(handle, size) == totalBlockNum);
}

void random_test(BufManHandle_t handle)
{
#define TEST_LEN 50000
	BufferManager_t* pManager = TRANS(BufferManager_t, handle);
	ALLOC_INFOR *array = (ALLOC_INFOR *)malloc(sizeof(ALLOC_INFOR)*TEST_LEN);
	int index;
	int bMalloc;
	int bDirect;
	int size;
	u8 direct_rgn;
	u32 i, j;

	printf("Begin to random test\n");
	memset(array, 0, sizeof(ALLOC_INFOR)*TEST_LEN);

	for (j = 0; j<0x12345; j++)
	{
		index = rand() % (TEST_LEN);
		bMalloc = rand() & 0x03;
		switch (bMalloc)
		{
		case 0://malloc
			if (array[index].bAlloc == 0)
			{
				bDirect = 0;
#if AUTO_MALLOC_DIRECT_BUFFER == 0         
				bDirect = rand() & 0x01;
				if (bDirect)
				{
					direct_rgn = rand() % (pManager->directPoolNum);
					size = rand()&((1 << pManager->directPool[direct_rgn].perBufSizeOrder) - 1);
					size |= 0x04; //in case 0
					size &= ~0x03;
					array[index].pBuffer = (u8*)__BUF_Alloc(handle, DIRECT_MALLOC_REGION(size, direct_rgn), 0, 0);
					if (array[index].pBuffer)
					{
						array[index].bAlloc = 1;
						array[index].size = size;
					}
					else
						printf("WARNING: fail to direct malloc %d\n", size);
				}
				else
				{
#endif             
					size = rand()&(pManager->maxBufferSize - 1);
					size |= 0x04; //in case 0
					size &= ~0x03;
					array[index].pBuffer = (u8*)__BUF_Alloc(handle, size, 0, 0);
					if (array[index].pBuffer)
					{
						array[index].bAlloc = 1;
						array[index].size = size;
						//printf("MC:%08x % 6d\n",array[index].pBuffer,size);
					}
					else
						printf("WARNING: fail to cascade malloc %d\n", size);
#if AUTO_MALLOC_DIRECT_BUFFER == 0                
				}
#endif
				if (array[index].bAlloc)
				{
					int i;
					array[index].filler = rand();
					for (i = 0; i<(size >> 2); i++)
					{
						((u32*)array[index].pBuffer)[i] = array[index].filler;
					}
					BUF_ASSERT((u8*)__BUF_GetAllocatedBufferBaseAddr(handle, array[index].pBuffer + 3, __func__, __LINE__) == array[index].pBuffer
						|| (u8*)__BUF_GetAllocatedBufferBaseAddr(handle, array[index].pBuffer + 3, __func__, __LINE__) == array[index].pBuffer - 4);
					BUF_ASSERT((u8*)__BUF_GetAllocatedBufferBaseAddr(handle, array[index].pBuffer + (array[index].size - 1), __func__, __LINE__) == array[index].pBuffer
						|| (u8*)__BUF_GetAllocatedBufferBaseAddr(handle, array[index].pBuffer + (array[index].size - 1), __func__, __LINE__) == array[index].pBuffer - 4);
					if (bDirect)
					{
						BUF_ASSERT(__BUF_GetAllocatedBufferSize(handle, array[index].pBuffer, __func__, __LINE__) == (1 << pManager->directPool[direct_rgn].perBufSizeOrder));
					}
					else
					{
						int i;
#if AUTO_MALLOC_DIRECT_BUFFER > 0

						for (i = 0; i<pManager->directPoolNum; i++)
						{
							if (size <= (1 << pManager->directPool[i].perBufSizeOrder))break;
						}
						if (i<pManager->directPoolNum)
						{
							BUF_ASSERT(__BUF_GetAllocatedBufferSize(handle, array[index].pBuffer, __func__, __LINE__) == (1 << pManager->directPool[i].perBufSizeOrder));
						}
						else
						{
#endif
							for (i = 0; i<pManager->cascadeLogPoolNum; i++)
							{
								if (size <= pManager->cascadeLogPool[i].perBufferSize)break;
							}
							BUF_ASSERT(i<pManager->cascadeLogPoolNum);

							BUF_ASSERT(__BUF_GetAllocatedBufferSize(handle, array[index].pBuffer, __func__, __LINE__) == pManager->cascadeLogPool[i].perBufferSize);
#if AUTO_MALLOC_DIRECT_BUFFER > 0
						}
#endif
					}

					//To check alloc repeatly
					for (i = 0; i<TEST_LEN; i++)
					{
						if (i == index)continue;
						if (array[i].bAlloc)
						{
							BUF_ASSERT(array[i].pBuffer != array[index].pBuffer);
						}
					}
				}
			}
			break;
		case 1://free
			if (array[index].bAlloc > 0)
			{
				int i;
				//             printf("F :%08x % 6d\n",array[index].pBuffer,array[index].size);
				for (i = 0; i<(array[index].size >> 2); i++)
				{
					BUF_ASSERT(((u32*)array[index].pBuffer)[i] == array[index].filler);
				}
				__BUF_Dealloc(handle, array[index].pBuffer);

				array[index].bAlloc = 0;
				array[index].pBuffer = NULL;
			}
			break;
		case 2://increase
			if (array[index].bAlloc > 0)
			{
				__BUF_IncreaseRefer(handle, array[index].pBuffer, __func__, __LINE__);
				array[index].bAlloc++;
			}
			break;
		case 3://decrease
			if (array[index].bAlloc > 0)
			{
				int result = __BUF_DecreaseRefer(handle, array[index].pBuffer, __func__, __LINE__);
				BUF_ASSERT(result == BUF_ERR_NO_ERROR);
				array[index].bAlloc--;
				if (array[index].bAlloc == 0)
				{
					array[index].pBuffer = NULL;
				}
			}
			break;
		}
	}


	for (j = 0; j<TEST_LEN; j++)
	{
		if (array[j].bAlloc)
		{
			__BUF_Dealloc(handle, array[j].pBuffer);
		}
	}

	__BUF_FlushCache(handle);

	for (i = 0; i<pManager->directPoolNum; i++)
	{
		printf("direct pool size=%d total=% 8d free=% 8d\n", (1 << pManager->directPool[i].perBufSizeOrder), pManager->directPool[i].bufTotalCount, pManager->directPool[i].freeBufCount);
	}
	for (i = 0; i<pManager->cascadeLogPoolNum; i++)
	{
		printf("cascade pool % 8d: % 8d\n", pManager->cascadeLogPool[i].perBufferSize, pManager->cascadeLogPool[i].freeBufferCount);
	}
	for (i = 0; i<pManager->cascadePhyPoolNum; i++)
	{
		printf("physical pool size=%d total=% 8d free=% 8d\n", 1 << pManager->cascadePhyPool[i].perBufSizeOrder, pManager->cascadePhyPool[i].totalBufferCount, pManager->cascadePhyPool[i].freeBufferCount);
	}
	free(array);
}

void test_batch(BufManHandle_t handle)
{
#define BATCH_LEN 500
	BufferManager_t* pManager = TRANS(BufferManager_t, handle);
	int bDirect;
	int size;
	u8 direct_rgn;
	u32 i, j;
	void* ptr_array[2][BATCH_LEN];
	u32 attr = 1;
	printf("Begin to batch test\n");

	for (i = 0; i<2; i++)
	{
		for (j = 0; j<BATCH_LEN; j++)
		{
			bDirect = rand() & 0x01;
			if (bDirect)
			{
				direct_rgn = rand() % (pManager->directPoolNum);
				size = rand()&((1 << pManager->directPool[direct_rgn].perBufSizeOrder) - 1);
				size |= 0x01; //in case 0

				ptr_array[i][j] = __BUF_Alloc(handle, DIRECT_MALLOC_REGION(size, direct_rgn), i, 0);
				if (ptr_array[i][j] == NULL)
					printf("WARNING: fail to direct malloc %d\n", size);
			}
			else
			{
				size = rand()&(pManager->maxBufferSize - 1);
				size |= 0x01;//in case 0
				ptr_array[i][j] = (u8*)__BUF_Alloc(handle, size, i, 0);
				if (ptr_array[i][j] == NULL)
					printf("WARNING: fail to cascade malloc %d\n", size);
			}
		}
	}
	__BUF_BatchFree(handle, ptr_array[0], BATCH_LEN);
	__BUF_BatchFreeWithAttr(handle, ptr_array[1], BATCH_LEN, &attr, 1, __func__, __LINE__);

	__BUF_FlushCache(handle);
	for (i = 0; i<pManager->cascadeLogPoolNum; i++)
	{
		printf("cascade pool % 8d: % 8d\n", pManager->cascadeLogPool[i].perBufferSize, pManager->cascadeLogPool[i].freeBufferCount);
	}
	for (i = 0; i<pManager->cascadePhyPoolNum; i++)
	{
		printf("physical pool % 8d: % 8d % 8d\n", 1 << pManager->cascadePhyPool[i].perBufSizeOrder, pManager->cascadePhyPool[i].freeBufferCount, pManager->cascadePhyPool[i].totalBufferCount);
	}
}

class TestB
{
public:
	TestB()
	{
		printf("TestB::TestB()\n");
	}

	~TestB()
	{
		printf("TestB::~TestB()\n");
	}
};

class TestA
{
public:
	TestA()
	{
		printf("TestA::TestA()\n");
	}

	~TestA()
	{
		printf("TestA::~TestA()\n");
	}
	
	void showMe() const
	{
		printf("var1 = %d, var2 = %d\n", var1, var2);
	}

	void* operator new(size_t size) throw (std::bad_alloc)
	{
		printf("TestA::operator new\n");
		void * bufPtr = EE_ALLOC(size);
		if (nullptr == bufPtr)
		{
			throw std::bad_alloc();
			return nullptr;
		}
		else
		{
			return bufPtr;
		}
	}

	void operator delete(void* bufPtr)
	{
		printf("TestA::operator delete\n");
		EE_FREE(bufPtr);
	}

public:
	int var1{ 6 };
	int var2{ 8 };
	TestB var3;
};

void EE_Test(BufManHandle_t handle)
{
	TestA* pTestA = new TestA;
	pTestA->showMe();
	delete pTestA;

	__BUF_FlushCache(handle);
}

void BUF_Test(BufManHandle_t handle)
{
	int i;
	BufferManager_t* pManager = TRANS(BufferManager_t, handle);
	printf("Begin to test\n");
	for (i = 9; i <= 14; i++)
	{
		printf("size=%d max=%d\n", 1 << i, __BUF_GetFreeBufferNum(handle, 1 << i));
	}

	for (i = 0; i<pManager->cascadeLogPoolNum; i++)
	{
		printf("Test cascade pool %d\n", i);
		test_cascade_buffer(handle, pManager->cascadeLogPool[i].perBufferSize, pManager->cascadeLogPool[i].pPhyBufPool->freeBufferCount*pManager->cascadeLogPool[i].nbLogBufPerPhyBuf);
	}

	for (i = 0; i<pManager->directPoolNum; i++)
	{
		printf("Test direct pool %d\n", i);
		test_direct_buffer(handle, 1 << pManager->directPool[i].perBufSizeOrder, i, pManager->directPool[i].bufTotalCount);
	}

	random_test(handle);
	test_batch(handle);
	for (i = 9; i <= 14; i++)
	{
		printf("siz=%d max=%d\n", 1 << i, __BUF_GetFreeBufferNum(handle, 1 << i));
	}
	__BUF_FlushCache(handle);
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	EE_BufInitialize();

	BUF_Info_Show();

	EE_Test(ee_buf_handle);

	BUF_Info_Show();

	//BUF_Test(ee_buf_handle);

	//return a.exec();
	system("pause");
	return 0;
}
