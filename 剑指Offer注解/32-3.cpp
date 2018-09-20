#include<bits/stdc++.h>
#include "../Utilities/BinaryTree.h"
using namespace std;


//输入树根,层序之字形打印二叉树
void Print(BinaryTreeNode* pRoot) {
	if(pRoot == nullptr)//非空校验
		return;
	//创建两个栈,分别用来保存之字型的两个顺序
	//在之前写层序遍历中,一个队列里也最多只能出现相邻两层的结点
	//所以两个栈足够用,分别各自交替存放一层的结点(入栈顺序相反),再各自pop至空
	stack<BinaryTreeNode*> levels[2];
	//结合上一道题:按行层序打印二叉树,需要使用两个变量维护
	int current = 0;//当前所在栈号,0栈放偶数层
	int next = 1;//下一层应放在栈号,1栈放奇数层

	levels[current].push(pRoot);//树根压入0号(偶数层)栈
	//只要两个栈都不是空,则逻辑队列非空
	while(!levels[0].empty() || !levels[1].empty()) {
		//取当前层栈顶元素
		BinaryTreeNode* pNode = levels[current].top();
		levels[current].pop();

		printf("%d ", pNode->m_nValue);//层内输出

		//如果当前在0号栈(偶数层栈)
		if(current == 0) {
			//孩子以先左再右的顺序入1号栈(奇数层栈)
			if(pNode->m_pLeft != nullptr)
				levels[next].push(pNode->m_pLeft);
			if(pNode->m_pRight != nullptr)
				levels[next].push(pNode->m_pRight);
		}
		//如果当前在1号栈(奇数层栈)
		else {
			//孩子以先右再左的顺序入0号栈(偶数层栈)
			if(pNode->m_pRight != nullptr)
				levels[next].push(pNode->m_pRight);
			if(pNode->m_pLeft != nullptr)
				levels[next].push(pNode->m_pLeft);
		}
		//如果发现当前栈为空,说明这一层打印完了
		if(levels[current].empty()) {
			printf("\n");//换行
			//换栈,下次循环要打印的是另一个栈了
			//下面的操作就是0变1,1变0
			current = 1 - current;
			next = 1 - next;
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
