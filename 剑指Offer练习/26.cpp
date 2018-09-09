#include<bits/stdc++.h>
#include "../Utilities/DblBinaryTree.h"
using namespace std;

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
bool Equal(double num1, double num2);

//递归函数,传入两个二叉树(树根),判断第二个是否是第一个的子结构
bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	bool result = false;

	//两棵树根都不为空时才做判断
	if(pRoot1 != nullptr && pRoot2 != nullptr) {
		if(Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))//如果树根相同
			result = DoesTree1HaveTree2(pRoot1, pRoot2);//从该位置开始判断是不是残疾子树
		if(!result)//如果上一步判断完仍然是false
			result = HasSubtree(pRoot1->m_pLeft, pRoot2);//从第1棵树的左子树上调用自身再判断
		if(!result)//如果上一步判断完仍然是false
			result = HasSubtree(pRoot1->m_pRight, pRoot2);//从第1棵树的右子树上调用自身再判断
	}

	return result;
}

//递归函数,传入两个二叉树(树根),判断第二个是否是第一个的残疾情况
//即第二个是否是第一个去掉一些非根结点,或者去掉全部结点(nullptr)的情况
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	if(pRoot2 == nullptr)//如果第二个为空
		return true;//相当于第一个去掉了所有结点

	if(pRoot1 == nullptr)//如果第二个不为空(执行至此),且第一个为空
		return false;//那么第一个怎么去掉都不对

	//至此,两棵树都不为空,要做递归判断

	if(!Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))//如果两棵树的根节点都不相等
		return false;//那么也是从第1棵树里怎么去掉都不对

	//递归地判断左右子树是否也分别是第1棵树的左右子树的残疾情况
	return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
	       DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

//判断两个浮点数相等
bool Equal(double num1, double num2) {
	//即判断它们之间的差值足够小
	if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

// 树中结点含有分叉,树B是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
bool test1() {
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

	return HasSubtree(pNodeA1,pNodeB1);
}

// 树中结点含有分叉,树B不是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
bool test2() {
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);
	
	return HasSubtree(pNodeA1,pNodeB1);
}

int main() {
	cout<<boolalpha<<test1()<<endl;
	cout<<boolalpha<<test2()<<endl;
	return 0;
}
