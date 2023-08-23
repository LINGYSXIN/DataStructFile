// Created on iPad.
//使用链式存储实现的队列

#include <iostream>
using namespace std;
#define ElemType int

//链节点

//定义链表节点
typedef struct LinkNode{
    ElemType data; //数据域
    struct LinkNode *next;//指针域
}LinkNode; //别名

//顺序存储的队列
typedef struct{
    LinkNode *front,*rear;                 //队头和队尾
}LinkQueue;

//初始化队列
void InitQueue(LinkQueue &Q){

}

//队列判空
bool   QueueEmpty(LinkQueue Q){

}

//入队
void EnQueue(LinkQueue &Q,ElemType X){

}

//出队
void DeQueue(LinkQueue &Q,ElemType &X){

}
//读队头
void GetHead(LinkQueue,ElemType &X){
    
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