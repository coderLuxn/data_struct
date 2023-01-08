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
	//���ж������Ƿ��� 
	//1.����˳���û�пռ�
	//2.�ռ䲻�� ����
	//3.�ռ��㹻 ֱ�Ӳ������ݼ���
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

void SeqListPushBuck(SL* ps, SLDataType x)//β��
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

void SeqListPopBuck(SL* ps) //βɾ
{
	//if (ps->size > 0)
	//{
	//	//ps->a[ps->size] = 0;
	//	ps->size--;//������ж�size�ͻ�Ϊ����
	//}
	assert(ps->size > 0);//Ϊ�����ִ�У�Ϊ����ֹ
	ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	//�ж�����
	SeqListCheckCapacity(ps);
	//Ų����
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
	//��һ��
	//int pos = 0;
	//while (x != ps->a[pos] && pos<ps->size)
	//{
	//		pos++;
	//}
	//if (pos < ps->size)
	//	return pos;
	//else
	//	return -1;
	//�ڶ���
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
	//����ķ����ж�pos��λ��������ȷ
	//if (pos<0 || pos>ps->size)
	//{
	//	printf("pos invalid\n");
	//	return;
	//}
	
	//ֱ�ӵķ���
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