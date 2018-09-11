#pragma once

//复杂链表的结点
struct ComplexListNode {
	//普通链表就有的值和next域 
	int                 m_nValue;
	ComplexListNode*    m_pNext;
	//复杂链表还多一个指向任意结点的域 
	ComplexListNode*    m_pSibling;
};

//建立指定Value的新结点 
ComplexListNode* CreateNode(int nValue); 
//建立结点关系 
void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling);
//输出复杂链表 
void PrintList(ComplexListNode* pHead);
