#include<bits/stdc++.h>
#include "..\Utilities\BinaryTree.h"
using namespace std;

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);

//输入BST的树根,返回转换后的双向链表的头结点
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree) {
	//pLastNodeInList用于记录转换后双向链表的尾结点
	BinaryTreeNode *pLastNodeInList = nullptr;
	//传入BST的树根,传入转换后双向链表的尾结点[指针的地址],从而改掉这个指针
	ConvertNode(pRootOfTree, &pLastNodeInList);

	//pHeadOfList用于记录转换后双向链表的头结点
	//现在要从尾结点位置向前寻找头结点
	BinaryTreeNode *pHeadOfList = pLastNodeInList;
	//只要结点非空,且其左侧结点(原BST的左子树结点)非空
	while(pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
		pHeadOfList = pHeadOfList->m_pLeft;//一直向左走
	//上面这个while循环可以优化:第一个条件只需要判断第一次即可
	//这里还是保留作者的写法
	return pHeadOfList;//最终返回转换后的双向链表的头结点
}

//这里是递归实现部分,单独拿出来形成一个函数
//传入BST的(子)树根,传入转换后双向链表的尾结点[指针的地址],从而改掉这个指针
void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList) {
	if(pNode == nullptr)//BST树非空校验
		return;

	BinaryTreeNode *pCurrent = pNode;//当前结点

	//中序遍历顺序:左-中-右

	/*左*/
	if (pCurrent->m_pLeft != nullptr)//左子树存在
		ConvertNode(pCurrent->m_pLeft, pLastNodeInList);//对左子树做转换

	/*中*/
	//至此,左子树已经转换完了,所以目前转换完的链表的最右结点指针*pLastNodeInList
	//应该指向左子树转换成的双向链表的最右结点
	//而这个结点正是左子树上的最大结点,也就是比当前结点小但数值最近的一个结点
	//----------------------------------------------
	//对右子树的最左叶子而言,左子树是不存在的,这时*pLastNodeInList是右子树的根的双亲
	//----------------------------------------------
	//所以这一步每次可以做两件事之一:
	//                   1.根节点-向左->左子树的最右叶子
	//                   2.右子树的最左叶子-向左->根节点
	//因此,当前结点的左指针应该指向这个结点
	pCurrent->m_pLeft = *pLastNodeInList;
	//如果*pLastNodeInList非空(这也说明左子树是实际存在的(至少有一个结点))
	if(*pLastNodeInList != nullptr)
		//这时要维护从它到当前结点的指针
		//同理,这一步也是每次可以做两件事之一:
		//               1.左子树的最右叶子-向右->根节点
		//               2.根节点-向右->右子树的最左叶子
		(*pLastNodeInList)->m_pRight = pCurrent;

	//此时,中间结点就已经维护到了左子树所转双向链表的最右侧
	*pLastNodeInList = pCurrent;//更新链表最右结点指针为当前结点

	/*右*/
	if (pCurrent->m_pRight != nullptr)//右子树存在
		ConvertNode(pCurrent->m_pRight, pLastNodeInList);//对右子树做转换
}

//提供双向链表的头结点,输出双向链表
void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList) {
	BinaryTreeNode* pNode = pHeadOfList;//游标指针从头结点开始
	//从左到右输出一遍
	printf("The nodes from left to right are:\n");
	while(pNode != nullptr) {
		printf("%d\t", pNode->m_nValue);
		if(pNode->m_pRight == nullptr)
			break;
		pNode = pNode->m_pRight;
	}
	//从右到左输出一遍
	printf("\nThe nodes from right to left are:\n");
	while(pNode != nullptr) {
		printf("%d\t", pNode->m_nValue);
		if(pNode->m_pLeft == nullptr)
			break;
		pNode = pNode->m_pLeft;
	}
	printf("\n");
}

//提供双向链表的头结点,销毁双向链表
void DestroyList(BinaryTreeNode* pHeadOfList) {
	BinaryTreeNode* pNode = pHeadOfList;//游标指针从头开始
	while(pNode != nullptr) {//只要没走完
		//记录右侧的结点
		BinaryTreeNode* pNext = pNode->m_pRight;
		//销毁当前的结点
		delete pNode;
		//右侧的结点作为新的当前结点,继续循环
		pNode = pNext;
	}
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
int main() {
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);

	BinaryTreeNode* pHeadOfList=Convert(pNode10);

	//输出双向链表
	PrintDoubleLinkedList(pHeadOfList);

	DestroyList(pHeadOfList);

	return 0;
}
