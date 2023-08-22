// Created on iPad.
//////////////////
//顺序栈-类型一，栈顶指针指向已存数据
//////////////////

#include <iostream>
using namespace std;
#define MaxSize 10

typedef int ElemType;

//顺序栈的数据结构
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

//顺序站的初始化

void InitStack(SqStack &S){
    S.top=-1;
}

//判空
bool StackEmpty(SqStack S){
    return S.top == -1;
}

//入栈
bool Push(SqStack &S,ElemType x){
    //判断是否满栈
    if(S.top == MaxSize-1){
        return false;
    }
    //进栈
    S.data[++S.top]=x;
    return true;
}

//出栈
bool Pop(SqStack &S,ElemType &e){
    //判空
    if(StackEmpty(S))  return false;
    e=S.data[S.top--];
    return true;
}


//读栈
bool GetTop(SqStack S,ElemType &e){
    if(StackEmpty(S)) return false;
    e=S.data[S.top];
    return true;
}

//销毁栈
bool DestroyStack(SqStack &S){
    S.top=-1;
    return true;
}


//快速建栈

bool CreateStack(SqStack &S){
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

//遍历一个栈（偷偷的，这个算法不符合栈的定义的）
void ShowStack(SqStack S){
    if(StackEmpty(S)) return ;
    int i=S.top;
    while(i !=-1){
        printf("%d  ",S.data[i--]);
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