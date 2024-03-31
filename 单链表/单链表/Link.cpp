#include"Link.h"
SListNode* BuySListNode(SLTDateType x)						//传入数据变量
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//开辟一个节点
	if (newnode == NULL)									//检查是否开辟成功
	{
		perror("SLTBynode error");
		return NULL;
	}
	newnode->data = x;										//将数据变量赋给data
	newnode->next = NULL;									//指针变量初始化为空指针
	return newnode;											//返回开辟的节点地址
}
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;									//定义一个临时指针进行遍历，最好不要动头结点
	while (cur)												//指针进行遍历，直到指针指向空即遍历结束
	{
		printf("%d->", cur->data);							//打印链表数据变量
		cur = cur->next;									//指针指向下一个节点
	}
	printf("NULL\n");
}
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);					//创建一个新节点
	if (*pplist == NULL)
	{
		*pplist = newnode;									//如果链表是空则直接将头结点指向新节点
	}
	else
	{
		SListNode* cur = *pplist;							//定义一个临时指针，遍历找到尾节点
		while (cur->next)									//直到最后一个节点结束
		{
			cur = cur->next;								//指针往后走一个节点
		}
		cur->next = newnode;								//将尾节点的指针域指向新节点
	}
}
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);					//开辟新节点
	if (*pplist == NULL)
	{
		*pplist = newnode;									//若链表为空表，则直接将头指针指向新节点
	}
	else
	{
		newnode->next = *pplist;							//新节点的指针域指向链表
		*pplist = newnode;									//头指针指向新向新节点
	}
}
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);										//判断链表是否为空
	SListNode* cur = *pplist;								//定义临时指针,用来找到最后一个节点的前一个节点
	if ((*pplist)->next == NULL)							//判断是否只有一个节点
	{
		free(*pplist);										//删除这个节点
		*pplist = NULL;										//头指针置空
	}
	else
	{
		while (cur->next->next)								//遍历到最后一个节点的前一个节点
		{
			cur = cur->next;
		}
		free(cur->next);									//删除最后一个元素
		cur->next = NULL;									//前一个节点已成新的最后一个元素，指针域置空
	}
}
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);										//判断链表是否为空
	SListNode* cur = *pplist;								//定义临时指针指向第二个节点
	if ((*pplist)->next == NULL)							//判断是否只有一个节点
	{
		free(*pplist);										//删除该节点
		*pplist = NULL;										//头指针置空
	}
	else
	{
		cur = cur->next;									//临时指针指向第二个节点
		free(*pplist);										//删除第一个节点
		*pplist = cur;										//头指针指向第二个节点

	}
}
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* cur = plist;									//定义临时指针遍历链表
	while (cur)												//临时指针为空则遍历结束
	{
		if (cur->data == x)									//节点的数据和查找的数据比较
			return cur;										//返回该节点的地址
		cur = cur->next;									//临时指针往后走一个节点
	}
	return NULL;											//没有找到则返回空
}
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);											//判断位置是否合法
	SListNode* newnode = BuySListNode(x);					//创建新节点
	newnode->next = pos->next;								//新节点指针域指向指定位置后一个节点
	pos->next = newnode;									//指定位置指针域指向新节点
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos && pos->next);								//判断位置是否合法
	SListNode* cur = pos->next;								//定义临时指针指向指定位置的后一个节点
	pos->next = pos->next->next;							//让指定位置指针域指向要删除节点的后一个接地那
	free(cur);												//删除指定位置后一个节点
}
void SListDestroy(SListNode* plist)
{
	SListNode* cur = plist;									//定义第一个临时指针，指向相对前一个节点
	SListNode* next = plist;								//定义第二个临时指针，指向相对前一个节点
	while (next)											//遍历，直到第二个节点指向空
	{
		cur = next;
		next = next->next;
		free(cur);
	}
}