#include<bits/stdc++.h>
using namespace std;

typedef struct DNode 
{
    int data;
    struct DNode* prior, * next;
}DNode, * DLinkList;

//��ʼ��
void InitList(DLinkList& L) 
{
    L = (DNode*)malloc(sizeof(DLinkList));
    L->prior = NULL;
    L->next = NULL;
}

//��������
void PrintList(DLinkList L) 
{
    DNode* p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//��˫����ĳ���
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

//ͷ�巨����˫����
DLinkList HeadInsert(DLinkList& L) 
{
    InitList(L); //��ʼ��
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

//β�巨����˫����
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

//��ֵ���ң�����x��L�е�λ��
DNode* LocateElem(DLinkList L, int x) 
{
    DNode* p = L->next;
    while (p && p->data != x) {
        p = p->next;
    }
    return p;
}

//��λ���ң�������˫����L�е�i��λ�õĽ��
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
    return p; //���i���ڱ���p=NULL,ֱ�ӷ���p����
}

//��x���뵽˫����L��*p������һ�����
void Insert(DLinkList& L, DNode* p, int x) 
{
    DNode* s = (DNode*)malloc(sizeof(DNode));
    s->data = x;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

//ɾ������:��˫�����еĵ�i�����ɾ��
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

//�пղ���
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
    //β�巨����˫����������������
    DLinkList L = TailInsert(L);
    cout << "L: ";
    PrintList(L);

    DNode* p;
    //��ֵ����
    p = LocateElem(L, 2);
    cout << "ֵΪ2�Ľ�����һ�����ֵ�ǣ�" << p->next->data << endl;
    cout << "ֵΪ2�Ľ�����һ�����ֵ�ǣ�" << p->prior->data << endl;
    //��λ����
    p = GetElem(L, 3);
    cout << "���������ֵ�ǣ�" << p->data << endl;

    //�������
    Insert(L, p, 7);
    cout << "�ڵ��������������ֵΪ7�Ľ���L�� ";
    PrintList(L);

    //ɾ������
    Delete(L, 5);
    cout << "ɾ�����������L�� ";
    PrintList(L);

    //���
    cout << "��Ϊ��" << Length(L) << endl;;

    //�п�
    Empty(L);
    return 0;
}