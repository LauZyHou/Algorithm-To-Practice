#include <cstdio>
#include "BinaryTree.h"

//传入结点的值,创建一个二叉树结点
BinaryTreeNode* CreateBinaryTreeNode(int value) {
	//创建二叉树结点
	BinaryTreeNode* pNode = new BinaryTreeNode();
	//设置值,左右子树默认为空
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	return pNode;
}

//连接结点,给出父节点和左右子树结点
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
	if(pParent != nullptr) { //校验父节点必须存在
		//使父节点指向左右子树即可
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

//输出指定的二叉树结点
void PrintTreeNode(const BinaryTreeNode* pNode) {
	if(pNode != nullptr) { //校验该结点非空
		printf("value of this node is: %d\n", pNode->m_nValue);

		if(pNode->m_pLeft != nullptr)//左子结点
			printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
		else
			printf("left child is nullptr.\n");

		if(pNode->m_pRight != nullptr)//右子结点
			printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
		else
			printf("right child is nullptr.\n");
	} else {
		printf("this node is nullptr.\n");
	}
	printf("\n");
}

//给出根节点,输出整棵二叉树
void PrintTree(const BinaryTreeNode* pRoot) {
	PrintTreeNode(pRoot);//输出根结点信息

	if(pRoot != nullptr) {//校验这个结点非空
		//递归地调用其自身,输出左右子树的信息
		if(pRoot->m_pLeft != nullptr)
			PrintTree(pRoot->m_pLeft);

		if(pRoot->m_pRight != nullptr)
			PrintTree(pRoot->m_pRight);
	}
	//这种输出方式不好,以后有空再找更人性化的控制台输出方式吧
}

//给出根节点,删除整棵二叉树
void DestroyTree(BinaryTreeNode* pRoot) {
	if(pRoot != nullptr) {//校验这个结点非空
		//将其左右子树的地址先分别记录下来 
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;
		//然后删除这个根节点 
		delete pRoot;
		pRoot = nullptr;
		//然后调用这个函数本身,递归地删除左右子树 
		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}
