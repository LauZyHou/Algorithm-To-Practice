#include<bits/stdc++.h>
#include"../Utilities/BinaryTree.h"
using namespace std;

//递归函数:给定二叉树求其树高
int TreeDepth(const BinaryTreeNode* pRoot) {
	if(pRoot == nullptr)//递归出口:空结点高度为0
		return 0;

	int nLeft = TreeDepth(pRoot->m_pLeft);//递归求左子树高 
	int nRight = TreeDepth(pRoot->m_pRight);//递归求右子树高 

	//返回max(左,右)+本子树的根节点高度1
	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

//            1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
int main() {
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, nullptr, pNode6);
	ConnectTreeNodes(pNode5, pNode7, nullptr);

	cout<<TreeDepth(pNode1)<<endl;//4

	DestroyTree(pNode1);
	return 0;
}
