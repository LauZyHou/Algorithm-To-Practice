#include<bits/stdc++.h>
#include"../Utilities/List.h"
using namespace std;

//遍历获得链表长度
unsigned int GetListLength(ListNode* pHead) {
	unsigned int nLength = 0;
	ListNode* pNode = pHead;
	while(pNode != nullptr) {
		++nLength;
		pNode = pNode->m_pNext;
	}
	return nLength;
}

//寻找两个链表的第一个公共结点
ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
	//得到两个链表的长度
	unsigned int nLength1 = GetListLength(pHead1);
	unsigned int nLength2 = GetListLength(pHead2);
	int nLengthDif = nLength1 - nLength2;//长度差,即先行步数

	//默认链1长,链2短
	ListNode* pListHeadLong = pHead1;
	ListNode* pListHeadShort = pHead2;
	//如果链2长
	if(nLength2 > nLength1) {
		//反过来
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
		nLengthDif = nLength2 - nLength1;
	}

	//先在长链表上走nLengthDif步
	for(int i = 0; i < nLengthDif; ++i)
		pListHeadLong = pListHeadLong->m_pNext;

	//然后同时在两个链表上遍历:只要长短链都没遍历完,且还没找到公共结点
	while((pListHeadLong != nullptr) &&
	        (pListHeadShort != nullptr) &&
	        (pListHeadLong != pListHeadShort)) {
		//同步指针向下走
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadShort = pListHeadShort->m_pNext;
	}

	//返回得到的第一个公共结点,如果没有自然返回nullptr也没问题
	ListNode* pFisrtCommonNode = pListHeadLong;
	return pFisrtCommonNode;
}

// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
int main() {
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode6);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	cout<<FindFirstCommonNode(pNode1,pNode4)->m_nValue<<endl;//6

	DestroyList(pNode1);
	DestroyList(pNode4);

	return 0;
}
