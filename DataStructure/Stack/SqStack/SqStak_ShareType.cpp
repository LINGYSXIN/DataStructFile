// Created on iPad.
//////////////////
//顺序栈-类型三，共享栈
//////////////////

#include <iostream>
using namespace std;
#define MaxSize 20

typedef int ElemType;

//顺序栈的数据结构
typedef struct{
    ElemType data[MaxSize];
    int top0;
    int top1;
}SqStack;

//顺序站的初始化

void InitStack(SqStack &S){
    S.top0=-1;
    S.top1=MaxSize;
}

//判空
bool StackEmpty(SqStack S){
    return S.top0 == -1 && S.top1==MaxSize;
}

//stack0
bool StackEmptyZero(SqStack S){
    return S.top0==-1 ;
}

//stack 1
bool StackEmptyOne(SqStack S){
    return S.top1==-1 ;
}


//判满
bool StackFull(SqStack S){
    return 1==(S.top1-S.top0);
}
//入栈
bool PushZero(SqStack &S,ElemType x){
    //判断是否满栈
    if(StackFull(S)){
        return false;
    }
    //进栈
    S.data[++S.top0]=x;
    return true;
}
bool PushOne(SqStack &S,ElemType x){
    //判断是否满栈
    if(StackFull(S)){
        return false;
    }
    //进栈
    S.data[--S.top1]=x;
    return true;
}
//出栈
bool PopZero(SqStack &S,ElemType &e){
    //判空
    if(StackEmptyZero(S))  return false;
    e=S.data[S.top0--];
    return true;
}
bool PopOne(SqStack &S,ElemType &e){
    //判空
    if(StackEmptyOne(S))  return false;
    e=S.data[S.top1++];
    return true;
}

//读栈
bool GetTopZero(SqStack S,ElemType &e){
    if(StackEmptyZero(S)) return false;
    e=S.data[S.top0];
    return true;
}
bool GetTopOne(SqStack S,ElemType &e){
    if(StackEmptyOne(S)) return false;
    e=S.data[S.top1];
    return true;
}
//销毁栈
bool DestroyStack(SqStack &S){
    S.top0=-1;
    S.top1=MaxSize;
    return true;
}


//快速建栈

bool CreateStack(SqStack &S){
    InitStack(S);
    int t=0;
    ElemType x;//用于存储所需要入栈的元素
    printf("如果你要插入到0号栈（默认），请输入99990，如果要切换到1号栈，请出入99991，输入9999结束创建.\n");
    scanf("%d",&x); //扫描键盘
    while(x!=9999 && !StackFull(S)){
        if(x==99990) {
            t=0;
            printf("切换到0号");
            scanf("%d",&x); //扫描键盘
            continue;}
        if(x==99991) {
            t=1;
            printf("切换到1号");
            scanf("%d",&x); //扫描键盘
            continue;}
        if(t==0)
        PushZero(S,x);
        else
        PushOne(S,x);
        scanf("%d",&x); //扫描键盘
    }
    return true;
}

//遍历一个栈（偷偷的，这个算法不符合栈的定义的）
void ShowStack(SqStack S){
    if(StackEmpty(S)) return ;
    int i=MaxSize;
    while(i !=0){
        printf("%d  ",S.data[--i]);
    }
    printf("\n");
}


int main() {
    cout << "Hello World!";
    SqStack S;
    InitStack(S);
    printf("初始化完成\n");
    CreateStack(S);
    printf("创建完成\n");
    ShowStack(S);
    return 0;
}