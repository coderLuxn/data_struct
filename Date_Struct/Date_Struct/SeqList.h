#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//#define N 100
//typedef int SLDataType;//重定义SLDataType的类型
//
////静态顺序表
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;  //表示数组中存储了多少数据
//}SL;
//
////声明
////接口函数
//void SeqListInit(SL* ps);
////静态特点：如果满了就不让插入 缺点：不知道给多少
////N给大了浪费，给小了不够用
//void SeqListPushBuck(SL* ps);
//void SeqListPopBuck(SL* ps);
//void SeqListPushFront(SL* ps);
//void SeqListPopFront(SL* ps);

#define N 100
typedef int SLDataType;//重定义SLDataType的类型

//动态顺序表
typedef struct SeqList
{
	SLDataType* a;//动态开辟
	int size;  //表示数组中存储了多少数据
	int capacity; //数组实际能存储数据的空间容量是多大
}SL;

//声明
//接口函数
void SeqListPrintf(SL* ps);//打印
void SeqListInit(SL* ps);//初始化
void SeqListCheckCapacity(SL* ps);//检测容量是否满
void SeqListPushBuck(SL* ps,SLDataType x);//尾插一个数据
void SeqListPopBuck(SL* ps); //尾删
void SeqListPushFront(SL* ps, SLDataType x);//头插
void SeqListPopFront(SL* ps);//头删
void SeqListDestory(SL* ps);//free动态开辟空间

//找到了返回x的下标，找不到返回-1
int SeqListFind(SL* ps, SLDataType x);
//指定pos下标插入数据
void SeqListInsert(SL* ps, int pos,SLDataType x);
//删除pos位置的数据
int SeqListErase(SL* ps, int pos);