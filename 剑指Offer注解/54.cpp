#include<bits/stdc++.h>
#include "../Utilities/BinaryTree.h"
using namespace std;


//递归函数:输入二叉(子)树根,输入k,在其上找中序遍历(剩下的)第k个结点
//k用引用传递,其改变可以影响到上面的递归层,k在调用中每找到一个就减小1
const BinaryTreeNode* KthNodeCore(const BinaryTreeNode* pRoot, unsigned int& k) {
	const BinaryTreeNode* target = nullptr;//存要找的目标结点

	if(pRoot->m_pLeft != nullptr)//左子树存在
		//递归第向左子树调用,一直到没有左子树的结点才是第一个结点
		//所以递归调用中的k没有发生改变
		target = KthNodeCore(pRoot->m_pLeft, k);

	if(target == nullptr) {//如果没有左子树了,或者左子树上找不到第k结点(左子树结点不够)
		if(k == 1)//如果是找第1个结点(这种时候只能是没有左子树了)
			target = pRoot;//这个"中"就是第1个结点
		k--;//把这个结点减去
		//如果没有满足上面的if,就是仅仅把这个结点减去
		//这时没有更新target,即在这一层上还没有找到第k个结点
	}

	//接下来要在这个结点的右子树上找剩下的k=k-1个结点了(k值已经用k--更新)

	//第一个条件:这一层的左子树和根结点都找完了结点还是不够
	//第二个条件:右子树存在,这时才能向右子树找
	if(target == nullptr && pRoot->m_pRight != nullptr)
		//向右子树找,递归调用(右子树的每个结点也要按这个左中右顺序)
		target = KthNodeCore(pRoot->m_pRight, k);

	//返回上一层
	return target;//如果等于nullptr表示要找的结点不在这层(个子树)上
}

//找给定二叉树中序遍历的第k个结点
const BinaryTreeNode* KthNode(const BinaryTreeNode* pRoot, unsigned int k) {
	if(pRoot == nullptr || k == 0)//仅仅多了一个输入合法性检查
		return nullptr;

	return KthNodeCore(pRoot, k);
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
	
	cout<<KthNode(pNode8,5)->m_nValue<<endl;

	DestroyTree(pNode8);//9
	
	return 0;
}
