#include<bits/stdc++.h>
#include "../Utilities/ComplexList.h"
using namespace std;

void CloneNodes(ComplexListNode* pHead);
void ConnectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);

//[总的函数]复制一个复杂链表,传入原型链表头,返回复制后链表的头
ComplexListNode* Clone(ComplexListNode* pHead) {
	CloneNodes(pHead);//第一遍O(n)扫描,做克隆合并
	ConnectSiblingNodes(pHead);//第二版O(n)扫描,给出Sibling域
	//为什么不能一遍扫描?因为第一遍扫的时候后面的结点还没克隆创好
	//如果Sibling域指向后面的结点,那没法给出Sibling域

	return ReconnectNodes(pHead);//第三遍O(n)扫描,拆开搞成2个链表
}

//[克隆合并]对复杂链表的每个结点克隆,将其夹在原结点之next、原next之前
void CloneNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;//从头结点开始
	//沿着next走
	while(pNode != nullptr) {
		//复制当前结点
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;//注意其next也指向当前的next
		pCloned->m_pSibling = nullptr;//唯有这个特殊指针暂时置空
		//将原结点的next指向新克隆的结点,所以克隆的结点在next链上是被夹杂其中
		pNode->m_pNext = pCloned;
		//沿着next走
		pNode = pCloned->m_pNext;
	}
}

//连接Sibling域,传入[克隆合并]后的链表(next链已经变成两倍长了)
void ConnectSiblingNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;//从头结点开始
	//一直沿着next链走
	while(pNode != nullptr) {
		//克隆的结点总是在原结点的后面一个
		ComplexListNode* pCloned = pNode->m_pNext;
		//现在要克隆其Sibling域,只要原结点的Sibling域非空
		if(pNode->m_pSibling != nullptr) {
			//那么Sibling域所指的那个结点的后一个结点也就是其克隆结点
			//所以本结点的克隆结点的Sibling域将指向原结点的Sibling域的next
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		//一直沿着next链走
		pNode = pCloned->m_pNext;
	}
}

//将这个大链表拆开,把之前的原链表建回来
//并把新的克隆的链表也维护好,然后返回之
ComplexListNode* ReconnectNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;//原链表上的游标指针,从[合并链表]头开始
	ComplexListNode* pClonedHead = nullptr;//克隆链表的头
	ComplexListNode* pClonedNode = nullptr;//克隆链表上的游标指针

	if(pNode != nullptr) {//这里是防止空指针异常
		//克隆链表头和其上的游标都初始化为[合并链表]的第二个结点
		pClonedHead = pClonedNode = pNode->m_pNext;
		//原链表的next,是[合并链表]上其克隆结点的next
		pNode->m_pNext = pClonedNode->m_pNext;
		//原链表指针向后走
		pNode = pNode->m_pNext;
	}

	//至此,[原链表指针]比[克隆链表指针]领先一个身位
	//即这个[原链表指针]其实是对应当前[克隆链表指针]所指元素的下一个元素
	//并且[原链表指针]和后面一个身位的[克隆链表指针]都挂在[合并链表上]

	//只要[原链表指针]没到空,也即没有遍历完
	while(pNode != nullptr) {
		//[克隆链表指针]的next也就是它前面的[原链表指针]的next
		pClonedNode->m_pNext = pNode->m_pNext;
		//[克隆链表指针]向后走
		pClonedNode = pClonedNode->m_pNext;

		//现在,[克隆链表指针]又和[原链表指针]指向的元素相对应了
		//并且[克隆链表指针]还挂在[合并链表上]
		//[原链表指针]要维护next域(并向下走),要依赖这个[克隆链表指针]

		//[原链表指针]的next域就是[克隆链表指针]的下一个
		pNode->m_pNext = pClonedNode->m_pNext;
		//[原链表指针]向下走
		pNode = pNode->m_pNext;
	}

	return pClonedHead;//最终返回[克隆链表头]
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
int main() {
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, pNode3);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, nullptr);
	BuildNodes(pNode4, pNode5, pNode2);
	
	ComplexListNode* newNode=Clone(pNode1);
	
	PrintList(newNode);

	return 0;
}
