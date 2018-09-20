#include<bits/stdc++.h>
#include "../Utilities/List.h"
using namespace std;

//输入链表头指针,k值,返回倒数第k个结点的地址
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	//输入非空校验
	if(pListHead == nullptr || k == 0)//"倒数第0个"这种说辞也是错误的
		return nullptr;

	ListNode *pAhead = pListHead;//先行指针
	ListNode *pBehind = nullptr;//后行指针

	//先行指针要先走k-1步,所以循环k-1次
	for(unsigned int i = 0; i < k - 1; ++ i) {
		if(pAhead->m_pNext != nullptr)//要判断下一步不是空
			pAhead = pAhead->m_pNext;//才能向下走
		else//如果下一步将踩空
			return nullptr;//那么说明链表太短了,没有"倒数第k个"
	}

	pBehind = pListHead;//至此,先行指针已经"先行"完了,后行指针要踩上第一个结点
	while(pAhead->m_pNext != nullptr) {//直到先行指针走到最后一个元素上为止
		//两指针联动,每次同时向后走一步
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	//最终,后行指针所指即为所求
	return pBehind;
}

int main() {
	//创建链表结点 
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
	//查询倒数第2个结点并输出 
	ListNode* pNode = FindKthToTail(pNode1, 2);
	PrintListNode(pNode);
	//销毁链表 
	DestroyList(pNode1);
	return 0;
}
