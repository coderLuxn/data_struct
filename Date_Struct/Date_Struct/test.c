#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

//初始化
void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1);//初始化

	SeqListPushBuck(&s1, 1);//尾插一个数据
	SeqListPushBuck(&s1, 2);
	SeqListPushBuck(&s1, 3);
	SeqListPushBuck(&s1, 4);
	SeqListPushBuck(&s1, 5);
	SeqListPrintf(&s1);

	SeqListPopBuck(&s1);//尾删
	SeqListPopBuck(&s1);
	SeqListPopBuck(&s1);
	SeqListPopBuck(&s1);
	SeqListPopBuck(&s1);
	SeqListPrintf(&s1);
	SeqListDestory(&s1);

	
}

void TestSeqList2()
{
	SL s2;
	SeqListInit(&s2);
	SeqListPushBuck(&s2, 1);//尾插一个数据
	SeqListPushBuck(&s2, 2);
	SeqListPushBuck(&s2, 3);
	SeqListPushBuck(&s2, 4);
	SeqListPushBuck(&s2, 5);
	SeqListPrintf(&s2);

	SeqListPushFront(&s2,10);//头插
	SeqListPushFront(&s2, 20);
	SeqListPushFront(&s2, 30);
	SeqListPrintf(&s2);

	SeqListPopFront(&s2);//头删
	SeqListPopFront(&s2);
	SeqListPrintf(&s2);

	SeqListDestory(&s2);//free动态开辟空间
}

int TestSeqList3()
{
	SL s2;
	SeqListInit(&s2);
	SeqListPushBuck(&s2, 1);//尾插一个数据
	SeqListPushBuck(&s2, 2);
	SeqListPushBuck(&s2, 3);
	SeqListPushBuck(&s2, 4);
	SeqListPushBuck(&s2, 5);
	SeqListPrintf(&s2);

	int  ret=SeqListFind(&s2,7);//查找
	return ret;
}

void TestSeqList4()
{
	SL s2;
	SeqListInit(&s2);
	SeqListPushBuck(&s2, 1);//尾插一个数据
	SeqListPushBuck(&s2, 2);
	SeqListPushBuck(&s2, 3);
	SeqListPushBuck(&s2, 4);
	SeqListPushBuck(&s2, 5);
	SeqListPrintf(&s2);

	SeqListInsert(&s2,  3, 100);
	SeqListPrintf(&s2);

	SeqListErase(&s2, 3);
	SeqListPrintf(&s2);
}

int main()
{
	//TestSeqList1();
	//TestSeqList2();
	//int ret=TestSeqList3();
	//printf("%d ", ret);
	TestSeqList4();
	return 0;
}