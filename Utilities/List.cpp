#include "list.h"
#include <stdio.h>
#include <stdlib.h>

//给定结点值,创建结点并返回新结点地址
ListNode* CreateListNode(int value) {
	ListNode* pNode = new ListNode();//创建结点
	pNode->m_nValue = value;//设置值
	pNode->m_pNext = nullptr;//设置next为空
	return pNode;//返回该结点的地址
}

//连接两个结点,使后一个结点成为前一个结点的next结点
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext) {
	//前一个结点不允许为空,如果为空没办法指向后面的结点
	if(pCurrent == nullptr) {
		printf("Error to connect two nodes.\n");
		exit(1);
	}

	//使其指向后面的结点(可能为空)
	pCurrent->m_pNext = pNext;
}

//输出结点
void PrintListNode(ListNode* pNode) {
	if(pNode == nullptr)//判空
		printf("The node is nullptr\n");
	else//非空时输出结点值
		printf("The key in node is %d.\n", pNode->m_nValue);
}

//给定头结点,输出整个链表 
void PrintList(ListNode* pHead) {
	printf("PrintList starts.\n");

	//不应直接操作头结点,设置一个指针指向头结点 
	ListNode* pNode = pHead;
	//当非空,则未遍历完毕 
	while(pNode != nullptr) {
		printf("%d\t", pNode->m_nValue);//输出结点的值 
		pNode = pNode->m_pNext;//指针向后移动 
	}

	printf("\nPrintList ends.\n");
}

//销毁整个链表 
void DestroyList(ListNode* pHead) {
	//从从头结点开始删除 
	ListNode* pNode = pHead;
	//当不为空时,遍历删除没结束 
	while(pNode != nullptr) {
		//让头结点指向下一结点 
		pHead = pHead->m_pNext;
		//而刚刚的头结点被临时指针记录,将其删除 
		delete pNode;
		//临时指针再指向现在这个头结点 
		pNode = pHead;
	}
	//如此往复,结束时已经删除了所有结点 
}

//给定一个值,添加新结点到链表尾部 
//pHead是指向头结点指针的指针 
void AddToTail(ListNode** pHead, int value) {
	//先创建新结点,给其设置值 
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	//如果头结点指针为空,说明没有头结点 
	if(*pHead == nullptr) {
		*pHead = pNew;//这时这个结点就成为头结点 
	} else {
		//否则要将这个结点添加到当前头结点所在链表的尾部 
		ListNode* pNode = *pHead;//取出头结点地址 
		//向后走,直到next为空,当前在链表最后一个结点 
		while(pNode->m_pNext != nullptr)
			pNode = pNode->m_pNext;
		//将最后一个结点的next指向这个新创建的结点 
		pNode->m_pNext = pNew;
	}
}

//给定一个值,删除该值对应的链表结点
//pHead是指向头结点指针的指针
void RemoveNode(ListNode** pHead, int value) {
	//非空校验 
	if(pHead == nullptr || *pHead == nullptr)
		return;
	
	//将指向要被删除的结点的指针 
	ListNode* pToBeDeleted = nullptr;
	//如果要被删除的结点是头结点 
	if((*pHead)->m_nValue == value) {
		pToBeDeleted = *pHead;//记录要删除的结点 
		*pHead = (*pHead)->m_pNext;//将头结点指针打向其下一结点 
	} else {
		//从头结点开始 
		ListNode* pNode = *pHead;
		//向后走,只要下一结点非空,且下一结点不是要删除的结点 
		while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;//把这些结点跳过 
		
		//当下一结点就是要删除的结点时,说明找到了要删除的结点 
		if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value) {
			pToBeDeleted = pNode->m_pNext;//记录要删除的结点
			//将当前结点的下一结点指向要删除结点的下一结点,维护链表完整
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	//如果记录的结点存在,即存在需要删除的结点 
	if(pToBeDeleted != nullptr) {
		delete pToBeDeleted;//将其删除即可 
		pToBeDeleted = nullptr;
	}
}
