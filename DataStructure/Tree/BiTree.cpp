// Created on iPad.
//二叉树

#include <iostream>
using namespace std;
typedef char ElemType;


typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree,*QueueElem;

/*
//链队列

    //定义链表节点
    typedef struct LinkNode{
        QueueElem data; //数据域
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
    bool QueueEmpty(LinkQueue Q){
        if(Q.front==Q.rear) return true;
        else return false;
    }

    //入队
    bool EnQueue(LinkQueue &Q,QueueElem X){
        LinkNode *s= (LinkNode *)malloc(sizeof(LinkNode));    //申请新节点的内存空间
        s->data=X;
        s->next=NULL;
        Q.rear->next=s; //接入链表，尾插法
        Q.rear=s;
        return true;
    }

    //出队
    bool DeQueue(LinkQueue &Q,QueueElem &X){
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
    bool GetHead(LinkQueue Q,QueueElem &X){
        if(QueueEmpty(Q))   return false;
        X=Q.front->next->data;
        return true;
    }
//链队列
*/


//二叉树节点


//初始化
void InitBiTree(BiTree &T){
    T=(BiTNode *)malloc(sizeof(BiTNode));
    T->lchild=T->rchild=NULL;
    T->data=0;
}

void Visit(BiTree T){
    printf("%c \n",T->data);
}


//建立树
void CreateBiTree(BiTree &T){
//输入需要将二叉树补成满二叉树  ABD##E##CH###  或者 AB##C##
	char c;
	cin >> c;
	if ('#' == c)             //当遇到#时，令树的根节点为NULL，从而结束该分支的递归
		T = NULL;
	else
	{
		T = new BiTNode;
		T->data = c;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}

}


/*
    //清空树
    void ClearbiTree(BiTree &T){

    }

    //销毁
    void DestroyBiTree(BiTree &T){

    }

    //二叉树判空

    bool BiTreeEmpty(BiTree T){

    }
*/

//先序遍历
void PreOrderTraverse(BiTree T){
    if(T != NULL){
        Visit(T);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//中序遍历
void InOrderTraverse(BiTree T){
    if(T!=NULL){
        InOrderTraverse(T->lchild);
        Visit(T);
        InOrderTraverse(T->rchild);
    
    }
}

//后序遍历
void PostOrderTravers(BiTree T){
    if(T!=NULL){
        PostOrderTravers(T->lchild);
        PostOrderTravers(T->rchild);
        Visit(T);
    }
}

/*
//层次遍历
void LevelOrderTraverse(BiTree T){
    if(T==NULL) return;
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!QueueEmpty(Q)){
        DeQueue(Q,p);
        Visit(p);
        if(p->lchild != NULL){
            EnQueue(Q,p->lchild);
        }
        if(p->rchild != NULL){
            EnQueue(Q,p->rchild );
        }
    }
}
*/


/*

    //返回根
    BiTNode* Root(BiTree T){

    }

    //返回值，返回节点值
    ElemType Value(BiTree T,BiTNode e){

    }

    //给节点赋值
    void Assign(BiTree T,BiTNode &e,ElemType v){

    }

    //返回双亲节点
    BiTNode * Parent(BiTree T,BiTNode e){

    } 

    //返回左孩子节点

    //返回右孩子节点

    //根据LR插入树

*/






int main() {
    BiTree T;               //声明一个指向二叉树根节点的指针               
	cout << "kaishila !!!" << endl;
    
    CreateBiTree(T);
	cout << "二叉树创建完成！" << endl;
	cout << "前序遍历：" << endl;
	PreOrderTraverse(T);
	cout << endl;
	cout << "中序遍历：" << endl;
	InOrderTraverse(T);
	cout << endl;
	cout << "后序遍历：" << endl;
	PostOrderTravers(T);
}