#include<bits/stdc++.h>
using namespace std;
//带父节点指针的二叉树
struct BinaryTreeNode {
	int                    m_nValue;//结点值
	BinaryTreeNode*        m_pLeft;//左子树
	BinaryTreeNode*        m_pRight;//右子树
	BinaryTreeNode*        m_pParent;//父结点
};

//传入结点的值,创建一个二叉树结点
BinaryTreeNode* CreateBinaryTreeNode(int value) {
	//创建二叉树结点
	BinaryTreeNode* pNode = new BinaryTreeNode();
	//设置值,左右子树,父结点皆默认为空
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	pNode->m_pParent = nullptr;
	return pNode;
}

//连接结点,给出父节点和左右子树结点
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
	if(pParent != nullptr) {//校验父节点必须存在
		//使父节点指向左右子树
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;

		//如果左右子树结点非空,那么它们也要指向父结点
		if(pLeft != nullptr)
			pLeft->m_pParent = pParent;
		if(pRight != nullptr)
			pRight->m_pParent = pParent;
	}
}

//输出指定的二叉树结点,这部分和前面的BinaryTree一样,没区别
void PrintTreeNode(BinaryTreeNode* pNode) {
	if(pNode != nullptr) {//校验该结点非空
		printf("value of this node is: %d\n", pNode->m_nValue);

		if(pNode->m_pLeft != nullptr)//左子结点
			printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
		else
			printf("left child is null.\n");

		if(pNode->m_pRight != nullptr)//右子结点
			printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
		else
			printf("right child is null.\n");
	} else {
		printf("this node is null.\n");
	}
	printf("\n");
}

//给出根节点,输出整棵二叉树
void PrintTree(BinaryTreeNode* pRoot) {
	PrintTreeNode(pRoot);//输出根结点信息

	if(pRoot != nullptr) {//校验这个结点非空
		//递归地调用其自身,输出左右子树的信息
		if(pRoot->m_pLeft != nullptr)
			PrintTree(pRoot->m_pLeft);

		if(pRoot->m_pRight != nullptr)
			PrintTree(pRoot->m_pRight);
	}
}

//给出根节点,删除整棵二叉树
void DestroyTree(BinaryTreeNode* pRoot) {
	if(pRoot != nullptr) {
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

//输入二叉树上的一个结点,返回其中序遍历的下一结点
BinaryTreeNode* GetNext(BinaryTreeNode* pNode) {
	if(pNode == nullptr)//非空校验
		return nullptr;

	BinaryTreeNode* pNext = nullptr;//要返回的下一结点
	//[1]如果存在右子树
	if(pNode->m_pRight != nullptr) {
		BinaryTreeNode* pRight = pNode->m_pRight;//从右子树根开始
		//不停向左子树走,直到走到叶子
		while(pRight->m_pLeft != nullptr)
			pRight = pRight->m_pLeft;
		pNext = pRight;//这个右子树的最左椰子就是所求
	}
	//[2]如果不存在右子树,但当前结点不是根节点
	else if(pNode->m_pParent != nullptr) {
		//设置两个移动指针
		BinaryTreeNode* pCurrent = pNode;//一个从当前结点开始
		BinaryTreeNode* pParent = pNode->m_pParent;//一个从其父结点开始
		//上面的结点没超出总根,且下面的结点始终是上面结点的右子树时
		while(pParent != nullptr && pCurrent == pParent->m_pRight) {
			//两个结点需要一直向上走
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}
		//至此,上面的结点超出总根(表示已经没有中序遍历的下一结点了)
		//或者是下面的结点成为了上面结点的左子树
		pNext = pParent;//不论哪种情形,都是上面的结点为中序遍历的下一结点(或空)
	}

	return pNext;
}

//            8
//        6      10
//       5 7    9  11
int main() {
	//建立结点 
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	//连接成树 
	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);
	
	//中序遍历中7的后面应是8 
	cout<<GetNext(pNode7)->m_nValue<<endl;
	
	//销毁二叉树 
	DestroyTree(pNode8);
	return 0;
}
