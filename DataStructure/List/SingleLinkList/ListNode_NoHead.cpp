// Created on iPad.
/////////////////////////
//不不不不不不带头单链表的创建以及基本操作
/////////////////////////
/*
不带头节点的单链表总结：
    1.对于建立新表，在头插法中所改动较小，只需要把L->next 改成L，这是因为L指代的第一个头节点，L->next == L
    2.对于建立新表，在尾插法中，需要注意，处理第一个节点时，需要直接将第一个节点赋予给L，即（L=s），如果使用的是r=s，则是改变了r的指向，
这就是在尾插法中，有无头节点的重要区别，L 与 r 本质上一样，两者同为指针变量，因此，仅使用r=s；仅改变遍了r的指针指向，因为原来r=L 只是r指向L，
因此没有改变L的指针指向，而在带头节点的单链表中，r=L，插入第一个节点时，r->next=s; 相当于L->next=s;从内存上改变了L的指向。
    3.对于查找，在按序查找中，i的值主要有几个需要注意，i=0或i=1时返回的L，而在有表头的单链表中，i=0代表返回表头（即L），i=1时代表返回第一个数据节点（即L->next)
    4.对于插入，按序的尾插法需要对第一个节点进行特殊处理，（需要注意的时，此时，我们查询时i-1=0时返回的是L）在判定不为空后，将L的内容复制给新节点的后继（next）
最后将L指针的指向改为新节点。
    5.对于插入，按照内容插入的操作与有表头的链表相同，因为两者都是传递根据一个节点的地址来进行操作，因此这部分的代码两者相同
    6.对于删除，按照需要删除中，当删除的是第1个节点，因为L就是第一个节点，而L->next是第二个节点 ，因此需要对删除第一个节点进行特殊处理，
使用一个指针将L中内容保存下来，让后将L指向第一个节点的后继（即：L=L->next),然后释放第一个节点的内存（free(q);)
    7.最后，带头链表与不带头链表最大也是最根本的区别在于带头链表的第一个数据节点为 L->next 、而不带头节点的第一个数据节点为 L ，因此在带头节点的链表代码中，L->next 与不带头节点的链表代码中 L的意义相同
    而对于判断是否空表，则可以理解为是否有第一个节点，一个是L->next == NULL,另一个是L==NULL；在增删改中，在带头节点的链表中，改变表指向第一个数据节点的操作与改变其他节点的后继操作完全一致，因此可以共用一套代码
    （即 L->next 也可以通过 p=L ，p->next == L->next ）,在没有头节点的链表中，对L指向第一个节点的操作为L=s，而其他节点变更后继的操作时p->next =s ，因此没有办法共用一套代码，这也是导致要对第一个节点进行特殊处理的直接原因

*/

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
    L=NULL;                 //⚠️⚠️⚠️和带头节点单链表不同，不带头节点的单链表的初始化是直接置空，而不是申请一个一块空间给头节点
    printf("无表头单链表初始化完成 \n");
}

////////////////////////////////////////
//因为单链表中没有带有头节点，所以在进行查询头节点或者说查找节点的过程中需要对第一个节点进行特殊处理
///////////////////////////////////////

////
//
//思考：插入第一个节点或者在删除节点时
////在第一个节点前插入，将新节点的后继指向第一个节点，将L指向新节点，即：s->next=L;L=s;
////删除第一个节点时，将L指向该节点的后继，即s=L;L=L->next;free(s);
//当空表时又如何操作
////空表判断，L==NULL



//**********************单链表的创建
//头插法创建单链表
 LinkList List_HeadInsert(LinkList &L){ //逆向建立单链表
    InitList(L);//初始化无头单链表，没有脑袋，傻傻又可爱🐶🐶🐶
    LNode *s;//用于申请新节点的空间并插入单链表中
    int x;//用于存储获取键盘的输入值
    printf("请输入创建链表的新值，每输入一个新值后回车确认，如果不需要再插入新值，请出入9999结束创建\n");
    scanf("%d",&x); //输入节点的值
    while(x!=9999){
        s=(LNode *)malloc(sizeof(LNode));//为新节点申请内存，相当于创建新节点
        s->data=x;//将新值注入新节点
        s->next=L; // 新节点指向原第一个节点，没有表头时，L就是第一个节点，相当于L 就是L->next
        L=s;  //L指向新节点，因为没有头节点，同时L直接指向第一个数据节点，所以L=s；就是指向第一个新节点
        scanf("%d",&x);
    }
    printf("没有头节点的 无头新单链表使用头插法建立完成 \n");
    return L;
}

//尾插法创建单链表
LinkList List_TailInsert(LinkList &L){
    InitList(L);//初始化没有脑袋瓜子的无头单链表 🧑‍🦲🧑‍🦲🧑‍🦲
    LNode *s,*r=L;// s 用于申请新节点空间,r 保存最后一个节点，r->next 为NULL 
    int x;//插入的新值
    printf("请输入创建链表的新值，每输入一个新值后回车确认，如果不需要再插入新值，请出入9999结束创建\n");
    scanf("%d",&x);//从键盘中获取新值
    //全都是没有头节点惹的祸，没有头节点，L就没有next，因为L就是NULL
    //真是要命
        s=(LNode *)malloc(sizeof(LNode));//为新节点申请内存空间，即创建新节点
        s->next=NULL;//小尾巴处理，因为你在尾巴，所以你的尾巴不能向着别人
        s->data=x;//存入新值
        L=s;
        r=s;        //这是第1⃣️个节点，L没有next，所以把第一个节点给L，相当于L就是第一个节点，从现在开始，L有next 了！！！！
    //完了，这下要再扫描一次了，不然👇这个循环要重复插入刚才的数据了
    printf("打印第一次创建节点r的值%d \n",r->data);
    scanf("%d",&x);//从键盘中获取新值
    //没办法👐，没有头节点就是这样子的啦，我又不是大神，只能用蛮力咯，多写点，多吐槽这个没有的无头单链表
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
//没有头节点，所以要第一个节点的地址就是L

LNode * GetElem(LinkList L,int i){
    //如果要第一个节点，只能给它返回L，因为咱们没有头节点，头节点直接指向第一个数据节点，咱们也没办法👋
    if(i==1 || i==0)
        return L;               //若i=1相当于要第一个节点的地址,如果它要的是第0个，返回原来的L，正好每次他都要判断一下空表
    int j=1;                    //代表第一个节点
    
    LNode *p=L;           //将表头的后继给p，表示第1个节点的指针赋值给p，所以从这开始，后面都是查第1个节点后的
    if(i<1 || i==0)       
    //不对喔，i=0就是要给第一个节点前面的地址（咱没有🈚️），可是它那个函数里i=1，如果它是插入，关我什么事👋，它自己不是有嘛，如果它要删除它也有，但是它需要单独判断一次，这个链表是不是空表，可是有必要调用这个GetElem嘛
        return NULL;            //即然 i为0或者小于1，则i的值不合法，返回 NULL表示i值不合法，因为咱们没有表头，同时有没有它喜欢的节点
    while(p != NULL && j<i){    //从第一个节点开始查找，查找到第i个节点，当j=i时，即查找到了第i个节点，通知不符合条件，跳出循环
        p=p->next;              //切换到下一个指针
        j++;                    //计数增加，代表指向下一个节点，当前节点为第j个节点
    }
    return p;                   //返回第i个节点的指针，若i大于表长，则返回NULL，因为当查询到最后一个节点是，尾节点的后继为NULL
}

//按值查找表节点 注意：返回的节点是查找到的第一个数据匹配的节点
LNode * LocateElem(LinkList L,int e){
    LNode *p=L;           //用于存储查询到的节点，同时当前指向第1个数据节点，L代表第一个数据节点
    while(p!=NULL && p->data != e){ //从第一个节点开始查询，当该节点不为空，同时该节点的的数据域不为查询值时继续循环，！
    p= p->next; // 切换到下一个节点
    }
    return p;                   //返回查找到的节点，若未找到，则返回 NULL
}

//**********************单链表的插入
//对第i个节点前插入进行插入，就是插入到第i-1个节点后，所以查的时候查的是i-1
//如果是对第一个节点呢？
//没有头节点，很难搞的喔
//插入第一节点前面，要先把新节点指向L，然后把L指向新节点，就是：s->next=L;L=s;简单吧
//所以要对第一个节点特殊处理，因为其他节点都是

bool List_Insert(LinkList &L,int i,int e){
    //这段操作插入第一节点前面的操作放在前面没事吧？😐，先跑起来吧
    //我想我知道了，如果这个链表为空或者i=1，GetElem可就返回 NULL了，咱们没有办法直接对空表进行操作呀！放这不行，绝对不行
    //改了GetElem了，i-1传过去，就算i-1=0，也是返回L，这样就不用担心，让下面来判断空表好了
    //感觉怪怪的，即然是没有表头为什么要查i-1这个节点呢？
    LNode *p = GetElem(L,i-1);        //找到第i个元素的前一个节点
    if(p==NULL) //判读是否查找到节点，若p为NULL，则表示i不合法 
        return false;
    //不是空🈳️🕳️表就好
    if(i==1){       //难搞哦，真来第一个节点前面插入啊！😧
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data=e;                          //将数据送入节点
    s->next=L;      //L就是第一个数据节点
    L=s;            //L指向新的第一个数据节点
    return true;    //溜了溜了，要在第一个节点前插入新节点的操作搞定
    }

    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data=e;                          //将数据送入节点
    s->next=p->next;                    //将第i-1个节点的后继（即第i个节点的指针）复制给新节点
    p->next=s;                          //更改第i-1个节点的后继为新节点，即第i-1个节点后面接着新节点，新节点后面接着第i个节点
    return true;
}

//对某个值后面插入新元素
bool List_InsertLocate(LinkList &L,int f,int e){
    //这个解决方案就非常6，很合适没有脑袋瓜子的无头节点单链表 ，😂😄😄😹，但是他是插在后面的捏
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
    if (p==NULL)//判断给的节点是否为合法节点，空节点没有data，也没有后继，会导致后面操作出错
        return false;
    
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data=p->data;          //保存原来节点的值
    s->next=p->next;            //保存原来节点的后继
    p->data=e;                  //将新元素放入旧节点
    p->next=s;                  //将旧节点的后继改成新节点，这样就完成了对该节点的前插操作（就是把原来的节点往后移动了
    return true;

}


//没事，这里我给他一个前插操作
bool List_InsertLocateFront(LinkList &L,int f,int e){
    LNode *p= LocateElem(L,f);//查找f的所在位置，并返回该节点
    return List_InsertFront(p,e);
    //主打的就是一个高效封装，简洁有力，看这个没有脑袋瓜子的无头单恋小老头能拿我怎么样✌️✌️✌️
}


//**********************单链表的删除
//思考：如果列表就剩一个数据节点，如果链表为空表
//如果就剩一个数据节点，查找i>1,返回的是NULL，如果i=1，查找（i-1=0）返回的L，我特地改的这样，这样查找完返回判断就知道是不是空链表了
//删除第i个节点
int List_Del(LinkList &L,int i){
    LNode * p= GetElem(L,i-1); //获取被删节点的前一个节点
    if(p==NULL)//判断返回节点是否合法，若为空意味着i不合法,也有可能意味着这个是空🈳️🈳️链表，特别是i=1时
        return false;
    int e=p->data;          //保存删除节点的值，最后返回，确实可以这样，即使是 i=1，返回的是L，L->data就是第一个节点的数据
    if(i==1){
        LNode *q=L;         //把第一个节点交给q，等会儿要释放
        L=q->next;          //把第一个节点的后继给L，
        free(q);            //释放这个节点
        return e;           //已经存好数据了，直接开溜🏃
    }
    //下面都是除了第一个节点外的节点
    LNode *q=p->next;       //取出第i个节点（要删除的节点），为了拿到它的后继
    p->next=q->next;        //将第i-1个节点的后继改为i的后继（即第i+1个节点）
    free(q);                //释放第i个节点的空间
    return e;
    
}

//删除节点*p
//采用的是和前插法的方式，所以没有改动，兼容无头苍蝇
int List_DelPoint(LNode *p){
    if(p==NULL)         //判断该节点是否合法，如果p是L，正好判断是不是空链表
        return false;
    //说明不是空节点
    LNode *q = p->next; //保存被删除节点的后继，不是空就是有后继了，就算L就剩一个数据节点了，这个数据节点的后继也是NULL
    int e=p->data;      //保存要被删除节点中数据
    //如果q是NULL呢？
    //那就没有把NULL中的数据和后继挪进去的必要了，毕竟NULL里没有这些东西
    //简单判断一下吧
    if(q==NULL){
        free(p);        //是不是应该先把p释放了再置空啊？
        p=NULL;         //直接将p置空，如果p是L，剩下最后一个数据节点，那么 L=p ，p->next =NULL 
        return e;
    }
    //说明还是有后继的
    p->data=q->data;    //将后继的数据放入旧节点
    p->next=q->next;    //将后继的后继放入旧节点
    free(q);            //释放被删除节点的后继，反正后继的数据都挪到了旧节点（被删除节点），哈哈哈😂
    return e;
}



//求表长g
int GetLength(LinkList L){
    int i=0;
    //if(L==NULL) //如果这个链表空了，就说明没有
    //    return i;
    //i++;//说明没空，至少有一个
    LNode *p=L;//直接改成这样不就得了，还写那么一大堆废话，书背
    while(p!= NULL){
        p=p->next;
        i++;
    }
    return i;
}

//遍历表格
void List_Show(LinkList L){
    LNode *p= L;//直接指向第一个数据节点，反正有头节点的时候，L->next也是指向第一个数据节点
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
    cout << "Hello World!\n";
    LinkList L;
    List_TailInsert(L);
    //看看建立的表
    if(L==NULL){
        printf("空表子！！！！！\n");
    }
    List_Show(L);
    //查找测试
    LNode *x = GetElem(L,1);//按照序号查找元素
    printf("查找到的元素为%d \n",x->data);
    LNode *t =LocateElem(L,1);//按照值来查找元素
    printf("使用按照值来查找的方式查找到的节点为%d \n",t->data);
    //插入测试
    //在第i个元素后面插入新元素
    bool b = List_Insert(L,1,0);
    printf("是否成功%d \n",b);
    List_Show(L);
    //按照内容插入
    printf("按照内容插入新元素 %d \n",List_InsertLocateFront(L,6,100));
    List_Show(L);
    //删除测试
    printf("表长%d \n",GetLength(L));
    List_Show(L);//遍历整个单链表
    int e=List_Del(L,1);//删除第一个节点
    List_Show(L);
    e=List_DelPoint(t);//删除查找到的节点
    List_Show(L);
    return 0;
}