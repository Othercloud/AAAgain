#include"Link.h"
void TestSList()
{
	SListNode* node = NULL;
	SListPushBack(&node, 1);
	SListPushBack(&node, 2);
	SListPushBack(&node, 3);
	SListPushBack(&node, 4);
	SListPushBack(&node, 5);
	SListPushFront(&node, 0);
	SListPopBack(&node);
	SListPopFront(&node);
	SListNode* pos = SListFind(node, 3);

	SListPrint(node);
	//SListInsertAfter(pos,100);
	//SListPrint(node);
	SListEraseAfter(pos);
	SListPrint(node);
	SListDestroy(node);
}
int main()
{
	TestSList();
	return 0;
}