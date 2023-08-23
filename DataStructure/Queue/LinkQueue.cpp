// Created on iPad.
//使用链式存储实现的队列

#include <iostream>
using namespace std;
typedef int ElemType;

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
    Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));    //建立头节点
    Q.front->next=NULL;             //初始化为空
}

//队列判空
bool   QueueEmpty(LinkQueue Q){
    if(Q.front==Q.rear) return true;
    else return false;
}

//入队
bool EnQueue(LinkQueue &Q,ElemType X){
    LinkNode *s= (LinkNode *)malloc(sizeof(LinkNode));    //申请新节点的内存空间
    s->data=X;
    s->next=NULL;
    Q.rear->next=s; //接入链表，尾插法
    Q.rear=s;
    return true;
}

//出队
bool DeQueue(LinkQueue &Q,ElemType &X){
    if(QueueEmpty(Q))   return  false;  //空队列
    LinkNode *p= Q.front->next;
    X=p->data;
    Q.front->next=p->next;
    if(Q.rear==p){
        Q.rear=Q.front;
    }
    free(p);
    return true;

}
//读队头
bool GetHead(LinkQueue Q,ElemType &X){
    if(QueueEmpty(Q))   return false;
    X=Q.front->next->data;
    return true;
}



int main() {
    cout << "Hello World!\n";
    int X;
    int i=0,a[10]={5,4,3,2,1,6,7,8,9};
    LinkQueue Q;
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