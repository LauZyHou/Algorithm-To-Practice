#include<bits/stdc++.h>
#include"../Utilities/BinaryTree.h"
using namespace std;

//递归函数:判断二叉树是不是平衡二叉树,并将高度保存在第二个参数指代的内存中
bool IsBalanced(const BinaryTreeNode* pRoot, int* pDepth) {
	//递归出口
	if(pRoot == nullptr) {//空结点
		*pDepth = 0;//空结点没有高度(高度是0)
		return true;//空结点没有左右子树,认为是平衡的
	}

	int left, right;//存左右子树的高度
	//递归调用判断左右子树平衡,计算保存左右子树的高度
	if(IsBalanced(pRoot->m_pLeft, &left)
	        && IsBalanced(pRoot->m_pRight, &right)) {//如果左右子树都是平衡的才继续判断
		int diff = left - right;//左右子树高度差
		if(diff <= 1 && diff >= -1) {//在[-1,1]内该子树就是平衡的
			*pDepth = 1 + (left > right ? left : right);//高度=max(左,右)+1
			return true;//平衡返回true
		}
	}
	//如果左右子树不都是平衡的,不必再继续判断了
	return false;
}

//判断一棵二叉树是不是平衡二叉树
bool IsBalanced_Solution(const BinaryTreeNode* pRoot) {
	int depth = 0;//用于保存二叉树的高度计算结果
	return IsBalanced(pRoot, &depth);//调用递归函数判断
}


// 不是完全二叉树，但是平衡二叉树
//             1
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

	cout<<boolalpha<<IsBalanced_Solution(pNode1)<<endl;//true 

	DestroyTree(pNode1);
	return 0;
}
