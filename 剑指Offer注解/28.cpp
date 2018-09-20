#include<bits/stdc++.h>
#include "../Utilities/BinaryTree.h"
using namespace std;

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

//传入一棵二叉树的根节点,判断二叉树是不是对称的
bool isSymmetrical(BinaryTreeNode* pRoot) {
	return isSymmetrical(pRoot, pRoot);
}

//传入[带nullptr的]二叉树[前序遍历]和同步的[对称前序遍历]序列中的两个结点
//判断继续向下遍历二叉树是否是对称的
bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	//两结点都为空肯定对称
	if(pRoot1 == nullptr && pRoot2 == nullptr)
		return true;
	//如果不都为空,而是某一个为空,那肯定不对称
	if(pRoot1 == nullptr || pRoot2 == nullptr)
		return false;
	//如果都不为空,但值不同,也不对称
	if(pRoot1->m_nValue != pRoot2->m_nValue)
		return false;
	//至此,再该结点上检查它是符合要求的
	//第一个参数结点是[前序遍历],[中左右]
	//第二个参数是[前序遍历的对称],[中右左]
	//现在[中]已经检查完了,这两种遍历要同步地继续向下检查
	return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight)
	       && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}


//            8
//        6      6
//       5 7    7 5
int main() {
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode8, pNode61, pNode62);
	ConnectTreeNodes(pNode61, pNode51, pNode71);
	ConnectTreeNodes(pNode62, pNode72, pNode52);
	
	cout<<boolalpha<<isSymmetrical(pNode8);
	
	DestroyTree(pNode8);
	return 0;
}
