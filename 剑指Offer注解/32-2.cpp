#include<bits/stdc++.h>
#include "..\Utilities\BinaryTree.h"
using namespace std;

//层序遍历分行打印二叉树
void Print(BinaryTreeNode* pRoot) {
	if(pRoot == nullptr)//非空校验
		return;

	queue<BinaryTreeNode*> nodes;//存二叉树结点地址的队列
	nodes.push(pRoot);//初始放入根节点
	int nextLevel = 0;//队列中,下一层结点的数目
	int toBePrinted = 1;//队列中,当前层还没被打印的节点数
	while(!nodes.empty()) {//只要队列非空
		//每次输出队头
		BinaryTreeNode* pNode = nodes.front();
		printf("%d ", pNode->m_nValue);
		//判空并压入左子结点
		if(pNode->m_pLeft != nullptr) {
			nodes.push(pNode->m_pLeft);
			++nextLevel;//压入同时将下层结点数+1
		}
		//判空并压入右子结点
		if(pNode->m_pRight != nullptr) {
			nodes.push(pNode->m_pRight);
			++nextLevel;//压入同时将下层结点数+1
		}
		//弹出刚刚输出过的队头,并将本层节点数-1
		nodes.pop();
		--toBePrinted;
		//[关键]两个变量相互维护
		//如果本层节点数减少到了0
		if(toBePrinted == 0) {
			printf("\n");//那么说明本层已经打印完了,要打印下一层了
			toBePrinted = nextLevel;//将下层结点数复制到本层
			//因为这一次循环一定是出队了"本层"的最后一个结点
			//同时将其携带的"下层"结点入队
			//而这几个结点入队以后"下层"结点就全部入完队了
			//并且没有"下下层"的结点
			nextLevel = 0;//所以此时将下层节点数设置为0
		}
	}
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

	Print(pNode8);

	DestroyTree(pNode8);

	return 0;
}

