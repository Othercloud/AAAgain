#include<bits/stdc++.h>
using namespace std;

typedef struct DNode 
{
    int data;
    struct DNode* prior, * next;
}DNode, * DLinkList;

//初始化
void InitList(DLinkList& L) 
{
    L = (DNode*)malloc(sizeof(DLinkList));
    L->prior = NULL;
    L->next = NULL;
}

//遍历操作
void PrintList(DLinkList L) 
{
    DNode* p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//求双链表的长度
int Length(DLinkList L) 
{
    DNode* p = L->next;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

//头插法建立双链表
DLinkList HeadInsert(DLinkList& L) 
{
    InitList(L); //初始化
    int x;
    cin >> x;
    while (x != 9999) {
        DNode* s = (DNode*)malloc(sizeof(DNode));
        s->data = x;
        if (L->next == NULL) {
            s->next = NULL;
            s->prior = L;
            L->next = s;
        }
        else {
            s->next = L->next;
            L->next->prior = s;
            s->prior = L;
            L->next = s;
        }
        cin >> x;
    }
    return L;
}

//尾插法建立双链表
DLinkList TailInsert(DLinkList& L) 
{
    InitList(L);
    DNode* s, * r = L;
    int x;
    cin >> x;
    while (x != 9999) {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;
        s->next = NULL;
        s->prior = r;
        r->next = s;
        r = s;
        cin >> x;
    }
    return L;
}

//按值查找：查找x在L中的位置
DNode* LocateElem(DLinkList L, int x) 
{
    DNode* p = L->next;
    while (p && p->data != x) {
        p = p->next;
    }
    return p;
}

//按位查找：查找在双链表L中第i个位置的结点
DNode* GetElem(DLinkList L, int i) 
{
    int j = 1;
    DNode* p = L->next;
    if (i == 0)return L;
    if (i < 1)return NULL;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p; //如果i大于表长，p=NULL,直接返回p即可
}

//将x插入到双链表L中*p结点的下一个结点
void Insert(DLinkList& L, DNode* p, int x) 
{
    DNode* s = (DNode*)malloc(sizeof(DNode));
    s->data = x;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

//删除操作:将双链表中的第i个结点删除
void Delete(DLinkList& L, int i) 
{
    if (i<1 || i>Length(L)) {
        cout << "delete failed: index is wrong." << endl;
        return;
    }
    DNode* p = GetElem(L, i - 1);
    DNode* q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
}

//判空操作
bool Empty(DLinkList L) 
{
    if (L->next == NULL) {
        cout << "L is null" << endl;
        return true;
    }
    else {
        cout << "L is not null" << endl;
        return false;
    }
}


int main() 
{
    //尾插法建立双链表，并遍历单链表
    DLinkList L = TailInsert(L);
    cout << "L: ";
    PrintList(L);

    DNode* p;
    //按值查找
    p = LocateElem(L, 2);
    cout << "值为2的结点的下一个结点值是：" << p->next->data << endl;
    cout << "值为2的结点的上一个结点值是：" << p->prior->data << endl;
    //按位查找
    p = GetElem(L, 3);
    cout << "第三个结点值是：" << p->data << endl;

    //插入操作
    Insert(L, p, 7);
    cout << "在第三个结点后面插入值为7的结点后L： ";
    PrintList(L);

    //删除操作
    Delete(L, 5);
    cout << "删除第五个结点后L： ";
    PrintList(L);

    //求表长
    cout << "表长为：" << Length(L) << endl;;

    //判空
    Empty(L);
    return 0;
}