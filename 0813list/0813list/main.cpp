#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<stack>

void PrintListReversingly_Iteratively(ListNode* pHead)
{
	std::stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while(pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while(!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
}

void PrintListReversingly_Recursively(ListNode* pHead)
{
	if(pHead != NULL)
	{
		if(pHead->m_pNext != NULL)
		{
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		printf("%d\t", pHead->m_nValue);
	}
}

void Test(ListNode* pHead)
{
	PrintList(pHead);
	PrintListReversingly_Iteratively(pHead);
	printf("\n");
	PrintListReversingly_Recursively(pHead);
}

void Test1()
{
	printf("\nTest1 begins.\n");

	ListNode* pNode1 = CreatListNode(1);
	ListNode* pNode2 = CreatListNode(2);
	ListNode* pNode3 = CreatListNode(3);
	ListNode* pNode4 = CreatListNode(4);
	ListNode* pNode5 = CreatListNode(5);

	ConnectListNodes(pNode1,pNode2);
	ConnectListNodes(pNode2,pNode3);
	ConnectListNodes(pNode3,pNode4);
	ConnectListNodes(pNode4,pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}

void Test2()
{
	printf("\nTest2 begins.\n");

	ListNode* pNode1 = CreatListNode(1);

	Test(pNode1);

	DestroyList(pNode1);
}

void Test3()
{
	printf("\nTest3 begins.\n");

	Test(NULL);
}

int main()
{
	Test1();
	Test2();
	Test3();

	system("pause");

	return 0;
}