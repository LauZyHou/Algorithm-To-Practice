#include<bits/stdc++.h>
#include "../Utilities/List.h"
using namespace std;

//输入链表,输出反转后的链表(原链表尾结点将成为头结点)
ListNode* ReverseList(ListNode* pHead) {
	ListNode* pReversedHead = nullptr;//反转后的链表头结点
	ListNode* pNode = pHead;//[当前结点]从头结点开始
	ListNode* pPrev = nullptr;//[当前结点]的[前一结点]
	//只要没走出链表
	while(pNode != nullptr) {
		ListNode* pNext = pNode->m_pNext;//记录[下一结点],防止内存泄露

		if(pNext == nullptr)//如果已经没有下一结点的话
			pReversedHead = pNode;//[当前结点]就已经是最终反转后的链表头

		pNode->m_pNext = pPrev;//将[当前结点]的next指向前一结点,以做反转
		//[当前结点]和[前一结点]都要向后走
		pPrev = pNode;
		pNode = pNext;
	}
	return pReversedHead;
}

int main() {
	//创建结点 
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	//连接成链 
	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	//输出
	PrintList(pNode1);
	//反转 
	ListNode* pReversedHead=ReverseList(pNode1);
	//输出和销毁
	PrintList(pReversedHead);
	DestroyList(pReversedHead); 
	return 0;
}
