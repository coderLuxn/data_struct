#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	//先判断容器是否满 
	//1.整个顺序表没有空间
	//2.空间不够 扩容
	//3.空间足够 直接插入数据即可
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("%s ", strerror(errno));
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListPushBuck(SL* ps, SLDataType x)//尾插
{
	
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPrintf(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
}

void SeqListPopBuck(SL* ps) //尾删
{
	//if (ps->size > 0)
	//{
	//	//ps->a[ps->size] = 0;
	//	ps->size--;//如果不判断size就会为负数
	//}
	assert(ps->size > 0);//为真继续执行，为假中止
	ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	//判断容量
	SeqListCheckCapacity(ps);
	//挪数据
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end+1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin- 1] = ps->a[begin];
		begin++;
	}
}

int SeqListFind(SL* ps, SLDataType x)
{
	//第一种
	//int pos = 0;
	//while (x != ps->a[pos] && pos<ps->size)
	//{
	//		pos++;
	//}
	//if (pos < ps->size)
	//	return pos;
	//else
	//	return -1;
	//第二种
	for (int i = 0; i < ps->size; i++)
	{
		if (x == ps->a[i])
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//温柔的方法判断pos的位置正不正确
	//if (pos<0 || pos>ps->size)
	//{
	//	printf("pos invalid\n");
	//	return;
	//}
	
	//直接的方法
	assert(pos >= 0 && pos <= ps->size);
	SeqListCheckCapacity(ps);
	int end = ps->size-1;
	while (end >= pos )
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

int SeqListErase(SL* ps, int pos)
{
	assert(pos >= 0 && pos < ps -> size);
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}