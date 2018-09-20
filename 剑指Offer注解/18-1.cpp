#include<bits/stdc++.h>
#include "../Utilities/List.h"
using namespace std;

// 参数:
//        pListHead:      指向头结点指针的指针 
//        pToBeDeleted:   指向要删除的结点的指针 
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
	if(!pListHead || !pToBeDeleted)//输入非空检验 
		return;

	//next非空,说明要删除的结点不是尾结点
	if(pToBeDeleted->m_pNext != nullptr) {
		ListNode* pNext = pToBeDeleted->m_pNext;//记录下一结点地址 
		pToBeDeleted->m_nValue = pNext->m_nValue;//将其值覆盖到当前结点 
		pToBeDeleted->m_pNext = pNext->m_pNext;//将当前结点的next指向原下一结点的next,绕过原下一结点 
		delete pNext;//删除刚刚抽出链表的原下一结点即可 
		pNext = nullptr;
	}
	//没满足上个if就说明是尾结点,如果同时还是头结点 
	else if(*pListHead == pToBeDeleted) {
		delete pToBeDeleted;//也就说明只有这一个结点,直接将它删除即可 
		pToBeDeleted = nullptr;
		*pListHead = nullptr;
	}
	//最后一种情况是,在链表中不止一个结点的情形下删除尾结点 
	else {
		ListNode* pNode = *pListHead;//从头结点开始
		//不断向下走,直到走到要删除的结点的前一个结点 
		while(pNode->m_pNext != pToBeDeleted) { 
			pNode = pNode->m_pNext;
		}
		//将该结点next指向空,成为尾结点 
		pNode->m_pNext = nullptr;
		delete pToBeDeleted;//然后删除这个尾结点 
		pToBeDeleted = nullptr;
	}
}
