#include"Link.h"
SListNode* BuySListNode(SLTDateType x)						//�������ݱ���
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//����һ���ڵ�
	if (newnode == NULL)									//����Ƿ񿪱ٳɹ�
	{
		perror("SLTBynode error");
		return NULL;
	}
	newnode->data = x;										//�����ݱ�������data
	newnode->next = NULL;									//ָ�������ʼ��Ϊ��ָ��
	return newnode;											//���ؿ��ٵĽڵ��ַ
}
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;									//����һ����ʱָ����б�������ò�Ҫ��ͷ���
	while (cur)												//ָ����б�����ֱ��ָ��ָ��ռ���������
	{
		printf("%d->", cur->data);							//��ӡ�������ݱ���
		cur = cur->next;									//ָ��ָ����һ���ڵ�
	}
	printf("NULL\n");
}
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);					//����һ���½ڵ�
	if (*pplist == NULL)
	{
		*pplist = newnode;									//��������ǿ���ֱ�ӽ�ͷ���ָ���½ڵ�
	}
	else
	{
		SListNode* cur = *pplist;							//����һ����ʱָ�룬�����ҵ�β�ڵ�
		while (cur->next)									//ֱ�����һ���ڵ����
		{
			cur = cur->next;								//ָ��������һ���ڵ�
		}
		cur->next = newnode;								//��β�ڵ��ָ����ָ���½ڵ�
	}
}
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);					//�����½ڵ�
	if (*pplist == NULL)
	{
		*pplist = newnode;									//������Ϊ�ձ���ֱ�ӽ�ͷָ��ָ���½ڵ�
	}
	else
	{
		newnode->next = *pplist;							//�½ڵ��ָ����ָ������
		*pplist = newnode;									//ͷָ��ָ�������½ڵ�
	}
}
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);										//�ж������Ƿ�Ϊ��
	SListNode* cur = *pplist;								//������ʱָ��,�����ҵ����һ���ڵ��ǰһ���ڵ�
	if ((*pplist)->next == NULL)							//�ж��Ƿ�ֻ��һ���ڵ�
	{
		free(*pplist);										//ɾ������ڵ�
		*pplist = NULL;										//ͷָ���ÿ�
	}
	else
	{
		while (cur->next->next)								//���������һ���ڵ��ǰһ���ڵ�
		{
			cur = cur->next;
		}
		free(cur->next);									//ɾ�����һ��Ԫ��
		cur->next = NULL;									//ǰһ���ڵ��ѳ��µ����һ��Ԫ�أ�ָ�����ÿ�
	}
}
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);										//�ж������Ƿ�Ϊ��
	SListNode* cur = *pplist;								//������ʱָ��ָ��ڶ����ڵ�
	if ((*pplist)->next == NULL)							//�ж��Ƿ�ֻ��һ���ڵ�
	{
		free(*pplist);										//ɾ���ýڵ�
		*pplist = NULL;										//ͷָ���ÿ�
	}
	else
	{
		cur = cur->next;									//��ʱָ��ָ��ڶ����ڵ�
		free(*pplist);										//ɾ����һ���ڵ�
		*pplist = cur;										//ͷָ��ָ��ڶ����ڵ�

	}
}
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* cur = plist;									//������ʱָ���������
	while (cur)												//��ʱָ��Ϊ�����������
	{
		if (cur->data == x)									//�ڵ�����ݺͲ��ҵ����ݱȽ�
			return cur;										//���ظýڵ�ĵ�ַ
		cur = cur->next;									//��ʱָ��������һ���ڵ�
	}
	return NULL;											//û���ҵ��򷵻ؿ�
}
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);											//�ж�λ���Ƿ�Ϸ�
	SListNode* newnode = BuySListNode(x);					//�����½ڵ�
	newnode->next = pos->next;								//�½ڵ�ָ����ָ��ָ��λ�ú�һ���ڵ�
	pos->next = newnode;									//ָ��λ��ָ����ָ���½ڵ�
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos && pos->next);								//�ж�λ���Ƿ�Ϸ�
	SListNode* cur = pos->next;								//������ʱָ��ָ��ָ��λ�õĺ�һ���ڵ�
	pos->next = pos->next->next;							//��ָ��λ��ָ����ָ��Ҫɾ���ڵ�ĺ�һ���ӵ���
	free(cur);												//ɾ��ָ��λ�ú�һ���ڵ�
}
void SListDestroy(SListNode* plist)
{
	SListNode* cur = plist;									//�����һ����ʱָ�룬ָ�����ǰһ���ڵ�
	SListNode* next = plist;								//����ڶ�����ʱָ�룬ָ�����ǰһ���ڵ�
	while (next)											//������ֱ���ڶ����ڵ�ָ���
	{
		cur = next;
		next = next->next;
		free(cur);
	}
}