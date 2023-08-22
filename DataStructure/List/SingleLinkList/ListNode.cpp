// Created on iPad.
/////////////////////////
//带头单链表的创建以及基本操作
/////////////////////////
#include <iostream>
using namespace std;

//定义数据结构
typedef struct ElemType{
    int data;
}ElemType;


//定义链表节点
typedef struct LNode{
    int data; //数据域
    struct LNode *next;//指针域
}LNode, *LinkList; //别名

//单链表初始化
void InitList(LinkList &L){
    L =(LNode *)malloc(sizeof(LinkList));
    L->next = NULL;//申请内存空间后，将指针域置空
    printf("单链表初始化完成 \n");
}



//**********************单链表的创建
//头插法创建单链表
 LinkList List_HeadInsert(LinkList &L){ //逆向建立单链表
    InitList(L);//初始化表头
    LNode *s;//用于申请新节点的空间并插入单链表中
    int x;//用于存储获取键盘的输入值
    printf("请输入创建链表的新值，每输入一个新值后回车确认，如果不需要再插入新值，请出入9999结束创建\n");
    scanf("%d",&x); //输入节点的值
    while(x!=9999){
        s=(LNode *)malloc(sizeof(LNode));//为新节点申请内存，相当于创建新节点
        s->data=x;//将新值注入新节点
        s->next=L->next; //将表头的后继 复制给新节点
        L->next=s;  //表头的后继变为 新节点
        scanf("%d",&x);
    }
    printf("新链表使用头插法建立完成 \n");
    return L;
}

//尾插法创建单链表
LinkList List_TailInsert(LinkList &L){
    InitList(L);//初始化链表
    LNode *s,*r=L;// s 用于申请新节点空间,r 保存最后一个节点（即表尾指针） 
    int x;//插入的新值
    printf("请输入创建链表的新值，每输入一个新值后回车确认，如果不需要再插入新值，请出入9999结束创建\n");
    scanf("%d",&x);//从键盘中获取新值
    while(x!=9999){
        s=(LNode *)malloc(sizeof(LNode));//为新节点申请内存空间，即创建新节点
        //s->next=NULL;//小尾巴处理，因为你在尾巴，所以你的尾巴不能向着别人
        s->data=x;//存入新值
        r->next=s;//链表的后继指向新的节点 ，即r->next 代表 L->next
        r=s;//将r变为最新的尾节点、
        scanf("%d",&x);
    }
    r->next=NULL; //尾节点置空，防止尾指针为脏数据所指的地址
    printf("新链表使用尾插法建立完成 \n");
    return L;
}




//**********************单链表的查询
//按序号查找节点值,查找第i个节点，并返回该节点（的指针）
LNode * GetElem(LinkList L,int i){
    int j=1;                    //代表第一个节点
    LNode *p=L->next;           //将表头的后继给p，表示第1个节点的指针赋值给p
    if(i==0)
        return L;               //若i=0相当于返回表头
    if(i<1)
        return NULL;            //即然 i不为0，又小于1，则i的值不合法，返回 NULL表示i值不合法
    while(p != NULL && j<i){    //从第一个节点开始查找，查找到第i个节点，当j=i时，即查找到了第i个节点，通知不符合条件，跳出循环
        p=p->next;              //切换到下一个指针
        j++;                    //计数增加，代表指向下一个节点，当前节点为第j个节点
    }
    return p;                   //返回第i个节点的指针，若i大于表长，则返回NULL，因为当查询到最后一个节点是，尾节点的后继为NULL
}

//按值查找表节点 注意：返回的节点是查找到的第一个数据匹配的节点
LNode * LocateElem(LinkList L,int e){
    LNode *p=L->next;           //用于存储查询到的节点，当前指向表头指向的第1个节点
    while(p!=NULL && p->data != e){ //从第一个节点开始查询，当该节点不为空，同时该节点的的数据域不为查询值时继续循环，！
    p= p->next; // 切换到下一个节点
    }
    return p;                   //返回查找到的节点，若未找到，则返回 NULL
}

//**********************单链表的插入
//对某节点后插入进行插入
//对第i个节点进行删除
bool List_Insert(LinkList &L,int i,int e){
    LNode *p = GetElem(L,i-1);        //找到第i个元素的前一个节点
    if(p==NULL) //判读是否查找到节点，若p为NULL，则表示i不合法 
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data=e;                          //将数据送入节点
    s->next=p->next;                    //将第i-1个节点的后继（即第i个节点的指针）复制给新节点
    p->next=s;                          //更改第i-1个节点的后继为新节点，即第i-1个节点后面接着新节点，新节点后面接着第i个节点
    return true;
}

//对某个值后面插入新元素
bool List_InsertLocate(LinkList &L,int f,int e){
    LNode *p= LocateElem(L,f);//查找f的所在位置，并返回该节点
    if(p==NULL)     //判断返回的节点是否为空，若为空 则该列表中没有元素 f
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data=e;                          //将数据送入节点
    s->next=p->next;                    //将含有f元素的前节点的后继 复制给新节点
    p->next=s;                          //更改含有f元素的前节点的后继为新节点，即含有f元素的前节点后面接着新节点，新节点后面接着含有f元素的节点
    return true;
}


//对某节点进行前插操作
bool List_InsertFront(LNode *p,int e){
    if (p==NULL)//判断给的节点是否为合法节点，空节点没有data，也没有后继，回导致后面操作出错
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data=p->data;          //保存原来节点的值
    s->next=p->next;            //保存原来节点的后继
    p->data=e;                  //将新元素放入旧节点
    p->next=s;                  //将旧节点的后继改成新节点，这样就完成了对该节点的前插操作（就是把原来的节点往后移动了
    return true;

}




//**********************单链表的删除
//删除第i个节点
int List_Del(LinkList &L,int i){
    LNode * p= GetElem(L,i-1); //获取被删节点的前一个节点
    if(p==NULL)//判断返回节点是否合法，若为空意味着i不合法
        return false;
    int e=p->data;          //保存删除节点的值，最后返回
    LNode *q=p->next;       //取出第i个节点（要删除的节点），为了拿到它的后继
    p->next=q->next;        //将第i-1个节点的后继改为i的后继（即第i+1个节点）
    free(q);                //释放第i个节点的空间
    return e;
    
}

//删除节点*p
int List_DelPoint(LNode *p){
    if(p==NULL)         //判断该节点是否合法
        return false;
    LNode *q = p->next; //保存被删除节点的后继
    int e=p->data;      //保存要被删除节点中数据
    p->data=q->data;    //将后继的数据放入旧节点
    p->next=q->next;    //将后继的后继放入旧节点
    free(q);            //释放被删除节点的后继，反正后继的数据都挪到了旧节点（被删除节点），哈哈哈😂
    return e;
}



//求表长g
int GetLength(LinkList L){
    LNode *p=L->next;
    int i=0;
    while(p!= NULL){
        p=p->next;
        i++;
    }
    return i;
}

//遍历表格
void List_Show(LinkList L){
    LNode *p= L->next;
    printf("接下来开始遍历单链表 \n");
    while(p!= NULL){
        printf("  %d",p->data);
        p=p->next;//切换到下一个节点
    }
    printf("\n ");
}



//////////////////////////
//顺顺利利，永远都不要出bug//
/////////////////////////

int main() {
    cout << "Hello World!";
    LinkList L;
    List_TailInsert(L);
    LNode *x = GetElem(L,3);//按照序号查找元素
    printf("查找到的元素为%d \n",x->data);
    LNode *t =LocateElem(L,5);//按照值来查找元素
    printf("使用按照值来查找的方式查找到的节点为%d \n",t->data);
    //在第i个元素后面插入新元素
    bool b = List_Insert(L,3,0);
    printf("是否成功%d \n",b);
    printf("按照内容插入新元素 %d \n",List_InsertLocate(L,6,100));
    printf("表长%d \n",GetLength(L));
    List_Show(L);//遍历整个单链表
    int e=List_Del(L,1);//删除第一个节点
    List_Show(L);
    e=List_DelPoint(t);//删除查找到的节点
    List_Show(L);
    return 0;
}