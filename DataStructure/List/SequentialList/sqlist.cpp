// Created on iPad.

#include <iostream>
#include <algorithm>
using namespace std;
//静态分配空间大小
#define MaxSize 50 
//动态初始化空间大小
#define InitSize 10

//静态分配空间数据结构
typedef struct{
   int data[MaxSize];
   int length;
}SqList;

//动态分配数据空间结构
typedef struct{
   int *data;
   int Maxsize,length;
}SeqList;

//初始化表,静态空间顺序表
void InitList(SqList &L){
   for(int i=0;i<=MaxSize-1;i++)
   	L.data[i]=0;
   L.length=0;
   
}

//初始化表，动态空间:
void IniteList(SeqList &L){
   L.data=(int *)malloc(sizeof(int)*InitSize);
   L.Maxsize= InitSize;
   for (int i=0;i<=L.Maxsize;i++)
   	L.data[i]=0;
   L.length=0;
   
}

//插入元素


bool ListInsert(SqList &L,int i,int e){
	if(i<1|| i>L.length+1)
		return false;
   if(L.length >=MaxSize)
		return false;
   
   for(int j=L.length;j>=i;i++)
   	L.data[j]=L.data[j-1];
   L.data[i-1]=e;
   L.length++;
   return true;
}

bool ListDel(SqList &L,int i,int &e){
   if(L.length == 0)
      return false;
   e=L.data[i-1];
   for(;i<=L.length;i++){
      L.data[i-1]=L.data[i];
   }
   L.length=L.length-1;
   return true;
}

int main() {
   SqList L;
   InitList(L);
   bool hi= ListInsert(L,1,123);
   printf("%d,%d \n",hi,L.data[0]);
   return 0;
}
