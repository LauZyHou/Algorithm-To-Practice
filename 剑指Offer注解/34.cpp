#include<bits/stdc++.h>
#include "../Utilities/BinaryTree.h"
using namespace std;

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int& currentSum);

// 参数:
//        pRoot:         二叉树根
//        expectedSum:   想检查的路径和
// 输出:
//        找到的路径
void FindPath(BinaryTreeNode* pRoot, int expectedSum) {
	if(pRoot == nullptr)
		return;
	//用vector模拟栈,因为打印路径时需要得到路径上所有结点,stack不方便
	vector<int> path;
	int currentSum = 0;//当前路径上的加和
	FindPath(pRoot, expectedSum, path, currentSum);
}

//递归函数,在二叉子树上,根据当前已检查到的路径和继续检查,直到叶子
void FindPath
(
    BinaryTreeNode*   pRoot,		//二叉(子)树根
    int               expectedSum,	//想检查的路径和
    vector<int>&      path,			//记录当前路径上结点的栈
    int&              currentSum	//当前路径上的加和
) {
	currentSum += pRoot->m_nValue;	//当前路径和要加上这个子树的根值
	path.push_back(pRoot->m_nValue);//将其加入到栈中(尾入)

	//判断是否叶子:左右孩子都为空就是叶结点
	bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
	//如果路径上结点的和等于输入的值,并且是叶结点
	if(currentSum == expectedSum && isLeaf) {
		//这时就找到了这条路径
		printf("A path is found: ");
		//用迭代器从头到尾输出这条路径上的结点值
		vector<int>::iterator iter = path.begin();
		for(; iter != path.end(); ++ iter)
			printf("%d\t", *iter);
		printf("\n");
	}

	//如果不是叶结点,则遍历它的子结点
	if(pRoot->m_pLeft != nullptr)
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	if(pRoot->m_pRight != nullptr)
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

	//在返回到父结点之前,在路径上删除当前结点
	path.pop_back();//将其弹出(尾出)
	//并在当前路径和中减去这个结点的值
	currentSum -= pRoot->m_nValue;
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7  
int main() {
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode10, pNode5, pNode12);
	ConnectTreeNodes(pNode5, pNode4, pNode7);
	
	FindPath(pNode10,22);
	
	DestroyTree(pNode10);

	return 0;
}
