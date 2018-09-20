#include<bits/stdc++.h>
#include "../Utilities/List.h"
using namespace std;

//输入链表的头结点,用快慢指针找到环内的一个结点,如果不存在环返回nullptr 
ListNode* MeetingNode(ListNode* pHead) {
	//输入非空校验 
	if(pHead == nullptr)
		return nullptr;
	//慢指针:初始在头结点后1个指针 
	ListNode* pSlow = pHead->m_pNext;
	if(pSlow == nullptr)//每次都要判断非空,确保有环 
		return nullptr;
	//快指针:初始在头结点后2个指针 
	ListNode* pFast = pSlow->m_pNext;
	//每次判断当下非空,再往下走
	//实际上根本没必要再去检查慢指针了,这里还是保留作者的写法 
	//[注意]有环的链表往后走绝不会走到空 
	while(pFast != nullptr && pSlow != nullptr) {
		if(pFast == pSlow)//如果两指针相遇 
			return pFast;//那么该处一定是环内一结点,将其返回 
		//慢指针每次走一步 
		pSlow = pSlow->m_pNext;
		//快指针每次走两步 
		pFast = pFast->m_pNext;//第一步可以直接走,因为while循环里判断过了 
		if(pFast != nullptr)//第二步就需要再判断一次再走了 
			pFast = pFast->m_pNext;
	}
	//如果while结束了还没返回,说明发现了空,链表没有环 
	return nullptr;
}

//输入链表头结点,找到链表中环的起始结点 
ListNode* EntryNodeOfLoop(ListNode* pHead) {
	//找到环内的某个结点 
	ListNode* meetingNode = MeetingNode(pHead); 
	if(meetingNode == nullptr)//如果返回了nullptr 
		return nullptr;//说明不存在环,这个函数也返回nullptr 

	//得到环中结点的数目
	int nodesInLoop = 1;//从1(刚刚找到的这个结点)开始计数 
	ListNode* pNode1 = meetingNode;//找到的结点用于标记当下位置,另找一个跑动的指针 
	//只要接下来不是标记位置,就说明没遍历完这个环 
	while(pNode1->m_pNext != meetingNode) {
		pNode1 = pNode1->m_pNext;//跑动指针向下走 
		++nodesInLoop;//计数+1 
	}
	
	//至此,已经得到了环长(环中结点数),保存在nodesInLoop中 

	//双指针法,先移动pNode1为先行 
	pNode1 = pHead;//从头结点开始移动 
	for(int i = 0; i < nodesInLoop; ++i)//次数为环中结点的数目
		pNode1 = pNode1->m_pNext;

	ListNode* pNode2 = pHead;//pNode2踩上头结点
	//两个指针同时向后移动,直到相遇为止 
	while(pNode1 != pNode2) {
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}
	//双指针相遇的位置即为所求的环的起始结点 
	return pNode1;
}

int main() {
	//创建结点 
	ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
	//连成带环的链,即5绕回到3上 
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode3);
	//计算起始结点,并输出 
	PrintListNode(EntryNodeOfLoop(pNode1));
	//销毁链表 
    DestroyList(pNode1);
	return 0;
}
