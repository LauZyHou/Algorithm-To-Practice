#include<bits/stdc++.h>
#include "../Utilities/BinaryTree.h"
using namespace std;

//递归函数,输入一棵二叉(子)树的根节点,将其镜像化
void MirrorRecursively(BinaryTreeNode *pNode) {
	//子二叉树的非空校验,如果左右子树都为空则镜像和不镜像结果一样,直接返回
	if((pNode == nullptr) || (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr))
		return;
	//交换当前根的左右子树结点指向
	BinaryTreeNode *pTemp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTemp;
	//如果左子树存在
	if(pNode->m_pLeft)
		MirrorRecursively(pNode->m_pLeft);//左子树也需要镜像
	//如果右子树存在
	if(pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight);//右子树也需要镜像
}

//本题的非递归实现,输入一棵二叉树的根节点,将其镜像化
void MirrorIteratively(BinaryTreeNode* pRoot) {
	if(pRoot == nullptr)//输入非空校验
		return;
	//建立存结点(地址)的栈,将根节点打入
	stack<BinaryTreeNode*> stackTreeNode;
	stackTreeNode.push(pRoot);
	//只要栈中非空,镜像操作即没有结束
	while(stackTreeNode.size() > 0) {
		BinaryTreeNode *pNode = stackTreeNode.top();//取栈顶结点
		stackTreeNode.pop();//并将其弹出
		//将栈顶结点所挂的左右子树交换
		BinaryTreeNode *pTemp = pNode->m_pLeft;
		pNode->m_pLeft = pNode->m_pRight;
		pNode->m_pRight = pTemp;

		if(pNode->m_pLeft)//新左子树非空
			stackTreeNode.push(pNode->m_pLeft);//则其内部也需要做镜像,将其压入

		if(pNode->m_pRight)//新右子树非空
			stackTreeNode.push(pNode->m_pRight);//同样需要镜像,压入栈
	}
	//循环结束后,按层序遍历的顺序将所有结点的左右子树做了交换
}

//            8
//        6      10
//       5 7    9  11
int main() {
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	PrintTree(pNode8);

	printf("=====MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);

	DestroyTree(pNode8);
	return 0;
}

