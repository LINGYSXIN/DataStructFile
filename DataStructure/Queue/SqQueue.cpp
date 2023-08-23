// Created on iPad.
//使用顺序存储实现的队列

#include <iostream>
using namespace std;
#define MaxSize 50
typedef int ElemType;

//顺序存储的队列
typedef struct{
    ElemType data[MaxSize];        //存放队列，元素
    int front,rear;                 //队头和队尾
}SqQueue;

//初始化队列
void InitQueue(SqQueue &Q){
    Q.front=Q.rear=0;               //将头尾指针指向0，完成初始化。
}

//队列判空
bool   QueueEmpty(SqQueue Q){
    if(Q.rear==Q.front) return true; //队列为空
    else return false;
}

    //判断队列是否为满与插入的操作息息相关，当rear指向数据的后一位时，那么(Q.rear+1)%MaxSize == Q.front相同时就为空，
    //如果rear指向的数据，那么就要增加标志来判断是否为队满；可以增加size变量说明队满，也可以增加tag来说明最近的操作是出队还是入队

//入队
bool EnQueue(SqQueue &Q,ElemType X){
    if((Q.rear+1)%MaxSize == Q.front) return false; //队满报错
    Q.data[Q.rear]=X;
    Q.rear=(Q.rear+1)%MaxSize;  //为指针加一
    return true;
}

//出队
bool DeQueue(SqQueue &Q,ElemType &X){
    if(QueueEmpty(Q)) return false;     //队列为空
    X=Q.data[Q.front];
    Q.front=(Q.front +1)%MaxSize;       //头指针加1
    return true;
}
//读队头
bool GetHead(SqQueue Q,ElemType &X){
    if(QueueEmpty(Q)) return false;     //空队列
    X=Q.data[Q.front];
    return true;
}


int main() {
    cout << "Hello World!\n";
    int X;
    int i=0,a[10]={5,4,3,2,1,6,7,8,9};
    SqQueue Q;
    InitQueue(Q);
    for(;i<=9;i++){
        printf("%d ",EnQueue(Q,a[i]));
    }
    printf("\n");
    GetHead(Q,X);
    printf("读头元素 %d \n",X);
    while(QueueEmpty(Q)==false){
        DeQueue(Q,X);
        printf("%d  ",X);
    }
    printf("\n");
    printf("完成测试\n");
    
    return 0;
}