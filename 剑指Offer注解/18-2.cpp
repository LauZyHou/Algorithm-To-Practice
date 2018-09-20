#include<bits/stdc++.h>
#include "../Utilities/List.h"
using namespace std;

//要删除的结点可能是头结点,所以要传入头结点地址的指针
//否则当删除头结点时,只改形参指针的地址值无法影响到调用者知道的头结点地址 
void DeleteDuplication(ListNode** pHead) {
	//输入非空校验 
	if(pHead == nullptr || *pHead == nullptr)
		return;
	//双指针初始化:第二个从头结点开始,第一个指向它前面的结点(一开始没有) 
	ListNode* pPreNode = nullptr;//前一结点 
	ListNode* pNode = *pHead;//[当下结点]
	//遍历整个链表 
	while(pNode != nullptr) {
		ListNode *pNext = pNode->m_pNext;//探测[当下结点]的下一结点 
		bool needDelete = false;//[当下结点]是否要被删除 
		//如果下一结点存在,且和[当下结点]值相同 
		if(pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
			needDelete = true;//那么[当下结点]是要删除的 
		//如果探测结果表明[当下结点]不需要删除
		if(!needDelete) {
			//那么双指针向后走一步 
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		} else {//如果探测结果表明[当下结点]需要被删除,这时要向后找到下一类结点 
			int value = pNode->m_nValue;//记录要删除的这一串结点的共同值 
			ListNode* pToBeDel = pNode;//要被删除的结点从[当下结点]开始
			//往后走,只要没到结尾,而且值和要删除的结点一致 
			while(pToBeDel != nullptr && pToBeDel->m_nValue == value) {
				pNext = pToBeDel->m_pNext;//先获取下一结点,防止后续链表丢失 
				delete pToBeDel;//删除当前要删除的结点 
				pToBeDel = nullptr;
				pToBeDel = pNext;//要删除的结点再指向原下一结点 
			}
			//至此,这一串结点已经删除结束 
			if(pPreNode == nullptr)//如果前一结点为空,即不存在前置结点 
				*pHead = pNext;//说明刚刚删了开头的一串,要把头结点指向新发现的这类结点的第一个 
			else//否则,删除的不是开头的一串 
				pPreNode->m_pNext = pNext;//把前置结点的next指向新发现的结点,维持链表完整 
			pNode = pNext;//将[当下结点]指向新发现的结点 
		}
	}
}
