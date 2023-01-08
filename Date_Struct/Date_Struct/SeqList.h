#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//#define N 100
//typedef int SLDataType;//�ض���SLDataType������
//
////��̬˳���
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;  //��ʾ�����д洢�˶�������
//}SL;
//
////����
////�ӿں���
//void SeqListInit(SL* ps);
////��̬�ص㣺������˾Ͳ��ò��� ȱ�㣺��֪��������
////N�������˷ѣ���С�˲�����
//void SeqListPushBuck(SL* ps);
//void SeqListPopBuck(SL* ps);
//void SeqListPushFront(SL* ps);
//void SeqListPopFront(SL* ps);

#define N 100
typedef int SLDataType;//�ض���SLDataType������

//��̬˳���
typedef struct SeqList
{
	SLDataType* a;//��̬����
	int size;  //��ʾ�����д洢�˶�������
	int capacity; //����ʵ���ܴ洢���ݵĿռ������Ƕ��
}SL;

//����
//�ӿں���
void SeqListPrintf(SL* ps);//��ӡ
void SeqListInit(SL* ps);//��ʼ��
void SeqListCheckCapacity(SL* ps);//��������Ƿ���
void SeqListPushBuck(SL* ps,SLDataType x);//β��һ������
void SeqListPopBuck(SL* ps); //βɾ
void SeqListPushFront(SL* ps, SLDataType x);//ͷ��
void SeqListPopFront(SL* ps);//ͷɾ
void SeqListDestory(SL* ps);//free��̬���ٿռ�

//�ҵ��˷���x���±꣬�Ҳ�������-1
int SeqListFind(SL* ps, SLDataType x);
//ָ��pos�±��������
void SeqListInsert(SL* ps, int pos,SLDataType x);
//ɾ��posλ�õ�����
int SeqListErase(SL* ps, int pos);