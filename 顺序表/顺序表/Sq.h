#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define InitSize 10

typedef struct//����˳���
{
	int length;//
	int Maxsize;
	int* data;
}SqList;

void InitList(SqList& L)//��ʼ��˳���
{
	L.data = (int*)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.Maxsize = InitSize;
}

void WriteList(SqList& L)//��Ԫ�ط���˳���
{
	printf("��������Ҫ������˳���ĳ��ȣ�");
	scanf("%d", &L.length);
	printf("������%d����Ҫ����˳������Ԫ�أ�", L.length);
	for (int i = 0; i < L.length; i++)
		scanf("%d", &L.data[i]);
}

void IncreaseSize(SqList& L)//����˳���ĳ���
{
	int len;
	int* p = L.data;
	printf("��������Ҫ���ӵ�˳���ĳ���:");
	scanf("%d", &len);
	L.data = (int*)malloc((L.Maxsize + len) * sizeof(int));
	for (int i = 0; i < L.length; i++)
		L.data[i] = p[i];
	L.Maxsize = L.Maxsize + len;
	free(p);
}

bool ListInsret(SqList& L)//����Ԫ��
{
	int i, e;
	printf("������Ҫ����˳����Ԫ�غ�Ԫ��λ�ã�");
	scanf("%d %d", &e, &i);
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length > L.Maxsize)
		return false;
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	printf("�����Ԫ����%d�������λ����%d\n", e, i);
	return true;
}

bool ListDelete(SqList& L)//ɾ������
{
	int i, e;
	printf("������Ҫɾ����Ԫ��λ�ã�");
	scanf("%d", &i);
	if (i<1 || i>L.length + 1)
		return false;
	if (!L.data)
		return false;
	e = L.data[i - 1];
	for (int j = i; j <= L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	printf("ɾ����Ԫ����%d�����Ԫ�ص�λ����%d\n", e, i);
	return true;
}

bool GetElem(SqList& L)//��λ����
{
	int i;
	printf("��Ҫ�ҵڼ���Ԫ�أ�");
	scanf("%d", &i);
	if (i<1 || i>L.length + 1)
	{
		printf("����ʧ��\n");
		return false;
	}
	printf("��%d��Ԫ����%d\n", i, L.data[i - 1]);
	return true;
}

void LocateElem(SqList& L)//��ֵ����
{
	int e;
	int k = 1;
	printf("������Ҫ���ҵ�Ԫ��ֵ��");
	scanf("%d", &e);
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
		{
			printf("�ҵ��ˣ��ǵ�%d��Ԫ��\n", i + 1);
			k = 0;
			break;
		}
	if (k)
		printf("�Ҳ���Ԫ��%d\n", e);
}

bool PrintList(SqList& L)//��ӡ˳���
{
	if (!L.data)
		return false;
	printf("˳������Ԫ���У�");
	for (int i = 0; i < L.length; i++)
		printf("%d ", L.data[i]);
	printf("\n");
	return true;
}

void DestroyList(SqList& L)//����˳���
{
	char a;
	getchar();
	printf("�Ƿ�����˳���(Y/N):");
	scanf("%c", &a);
	if (a == 'Y')
	{
		L.length = 0;
		L.Maxsize = 0;
		free(L.data);
		printf("˳���������\n");
	}
}

int Length(SqList& L)//���
{
	if (L.length == 0)
		return 0;
	return L.length;
}
