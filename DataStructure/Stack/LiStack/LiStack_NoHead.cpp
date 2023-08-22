// Created on iPad.
///////////////////
//链式存储栈-不带头节点的
//////////////////
#include <iostream>
using namespace std;

typedef int ElemType;

//链栈的数据结构
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LNode,*LiStack;

//链栈初始化
bool InitStack(LiStack &S){
    S=NULL;
    return true;
}

//链栈判空
bool StackEmpty (LiStack S){
    return S == NULL;
}

//链栈进栈
bool Push(LiStack &S,ElemType X){
    LNode *n =(LNode *)malloc(sizeof(LiStack));
    n->data=X;
    n->next=S;
    S=n;
    return true;
}

//出栈
bool Pop(LiStack &S,ElemType &X){
    if(StackEmpty(S)) return false;
    LNode *p=S;
    X=p->data;
    S=p->next;
    return true;
}

//读顶栈
bool GetTop(LiStack S,ElemType &X){
    if(StackEmpty(S)) return false;
    X=S->data;
    return true;
}

//销毁栈
bool DestroyStack(LiStack &S){
    LNode *p=S,*q;//暂存指针
    while(p!=NULL){
        q=p;
        p=p->next;
        free(q);
    }
    free(S);
    return true;
}
//快速建栈

bool CreateStack(LiStack &S){
    InitStack(S);
    ElemType x;//用于存储所需要入栈的元素
    printf("please enter your number for create a stack ,if you have key in number enough ,please key in 9999 to shut down this creativity.\n");
    scanf("%d",&x); //扫描键盘
    while(x!=9999){
        Push(S,x);
        scanf("%d",&x); //扫描键盘
    }
    return true;
}

//遍历表格
void ShowStack(LiStack L){
    LNode *p= L;
    printf("接下来开始遍历单链表 \n");
    while(p!= NULL){
        printf("  %d",p->data);
        p=p->next;//切换到下一个节点
    }
    printf("\n ");
}

int main() {
    cout << "Hello World!";
    LiStack S;
    InitStack(S);
    printf("初始化完成\n");
    CreateStack(S);
    printf("创建完成\n");
    ShowStack(S);
    return 0;
}