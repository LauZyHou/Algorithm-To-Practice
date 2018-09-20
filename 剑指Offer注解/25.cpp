#include<bits/stdc++.h>
#include "../Utilities/List.h"
using namespace std;

//给出两个子链表(的头结点),完成题目要求的合并,返回合并后的头结点
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
	//特别的递归出口,某一个链表为空时直接返回另一个链表(这里优先返回第二个)
	if(pHead1 == nullptr)
		return pHead2;
	else if(pHead2 == nullptr)
		return pHead1;
	//如果都不为空,需要做合并操作
	ListNode* pMergedHead = nullptr;//合并后的链表头结点
	//如果1的头比2的头小
	if(pHead1->m_nValue < pHead2->m_nValue) {
		pMergedHead = pHead1;//那么1的头要在前面
		//其next指向的是去掉头的1链和原来的2链合并后的链表
		pMergedHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
	} else {//如果2的头比1的头小,或者两个头一样大
		pMergedHead = pHead2;//那么2的头放在前面(一样大时放谁都ok)
		//其next指向的是去掉头的2链和原来的1链合并后的链表
		pMergedHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
	}
	//至此,这两个子链已经合并完成,再返回合并后的链表头
	return pMergedHead;
}

int main() {
	//创建链表1 
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(5);
	ConnectListNodes(pNode1, pNode3);
	ConnectListNodes(pNode3, pNode5);
	//创建链表2 
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode6 = CreateListNode(6);
	ConnectListNodes(pNode2, pNode4);
	ConnectListNodes(pNode4, pNode6);
	//调用本题的合并
	ListNode* pNewHead=Merge(pNode1,pNode2);
	//输出和销毁 
	PrintList(pNewHead);
	DestroyList(pNewHead);
	return 0; 
}
