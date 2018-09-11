#include <cstdio>
#include "ComplexList.h"

//建立指定Value的结点:创建结点,设定值,返回 
ComplexListNode* CreateNode(int nValue) {
	ComplexListNode* pNode = new ComplexListNode();

	pNode->m_nValue = nValue;
	pNode->m_pNext = nullptr;
	pNode->m_pSibling = nullptr;

	return pNode;
}

//建立结点关系 
void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling) {
	if(pNode != nullptr) {//检查要设置关系的结点非空 
		pNode->m_pNext = pNext;
		pNode->m_pSibling = pSibling;
	}
}

//输出复杂链表 
void PrintList(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	while(pNode != nullptr) {
		printf("The value of this node is: %d.\n", pNode->m_nValue);
		//在输出时把它独有的域也输出,next域不用输出 
		if(pNode->m_pSibling != nullptr) 
			printf("The value of its sibling is: %d.\n", pNode->m_pSibling->m_nValue);
		else
			printf("This node does not have a sibling.\n");
		printf("\n");
		//因为输出链表时候还是从前向后按next这条路走 
		pNode = pNode->m_pNext;
	}
}
