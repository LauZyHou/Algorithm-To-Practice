#include<bits/stdc++.h>
#include "..\Utilities\BinaryTree.h"
using namespace std;

//输入二叉树根结点,输出从这里开始的其层序遍历结果
void PrintFromTopToBottom(BinaryTreeNode* pRoot) {
	if(pRoot == nullptr)//输入非空校验
		return;

	//使用STL的deque(双端队列),其实只要是普通的队列就够了
	deque<BinaryTreeNode *> dequeTreeNode;

	dequeTreeNode.push_back(pRoot);//根节点从后入队

	//只要队列非空,就一直做
	while(dequeTreeNode.size()) {
		//取队头
		BinaryTreeNode *pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		//将其输出
		printf("%d ", pNode->m_nValue);
		//非空左孩子从后入队
		if(pNode->m_pLeft)
			dequeTreeNode.push_back(pNode->m_pLeft);
		//非空右孩子从后入队
		if(pNode->m_pRight)
			dequeTreeNode.push_back(pNode->m_pRight);
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
	
	PrintFromTopToBottom(pNode10);
	
	DestroyTree(pNode10);

	return 0;
}
