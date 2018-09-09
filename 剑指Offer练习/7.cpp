#include "../Utilities/BinaryTree.h"
#include<bits/stdc++.h>
#include<exception>
using namespace std;

// 参数:
//        startPreorder:     当前前序遍历数组开头地址
//        endPreorder:       当前前序遍历数组结尾地址
//        startInorder:      当前中序遍历数组开头地址
//        endInorder:        当前中序遍历数组结尾地址
// 返回值:
//        以输入的前序和中序遍历序列所构造的二叉(子)树的根节点地址
BinaryTreeNode* ConstructCore
(
    int* startPreorder, int* endPreorder,
    int* startInorder, int* endInorder
) {
	//根据前序遍历序列的第一个数字创建根结点
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;//左右子树初始化为空

	//[递归出口]如果前序遍历序列开头和结尾地址一样,即只有这一个值
	if(startPreorder == endPreorder) {
		//这时去看中序遍历序列,也必须是开头和结尾地址一样,即只有一个值
		//且这个值和前序遍历序列的值相等,都是根节点的值
		if(startInorder == endInorder && *startPreorder == *startInorder)
			return root;//这时构建的二叉树就只有这一个根节点,返回
		else//否则,说明这两个序列是不对应的,无法正常构造二叉树
			throw exception();
	}

	//要寻找中序遍历序列中根结点的指针位置,从中序遍历序列开头处开始
	int* rootInorder = startInorder;
	//当没有超过中序遍历序列末尾结点,且不等于前序遍历序列第一个数字时
	while(rootInorder <= endInorder && *rootInorder != rootValue)
		++ rootInorder;//一直往下走

	//走完以后,判断一下,如果当前走到了末尾,并且还是没有这个数字
	if(rootInorder == endInorder && *rootInorder != rootValue)
		throw exception();//说明这两个序列是不匹配的,出错

	//至此,已经找到了中序遍历序列中根结点的指针位置

	//这时左子树的长度就看中序遍历序列根节点左边有几个数(左子树结点数)
	int leftLength = rootInorder - startInorder;
	//用这个左子树结点数,在前序遍历序列找到左子树序列的末尾点
	int* leftPreorderEnd = startPreorder + leftLength;
	//那么它的下一个点也就是右子树序列的起始点!

	//如果左子树结点不为0,即存在左子树
	if(leftLength > 0) {
		//递归调用这个函数来构建左子树
		//前序子序列:起始点只要去掉根结点,终止点刚刚计算出来的
		//中序子序列:起始点还是大中序序列的起始点,终止点要从根结点往前一步
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
		                              startInorder, rootInorder - 1);
		//构造之后挂成本结点左子树
	}
	//如果左子树结点数没有占完除了开头根节点后剩下的所有结点,即存在右子树
	if(leftLength < endPreorder - startPreorder) {
		//递归调用这个函数来构建右子树
		//前序子序列:起始点刚刚计算出来的左子树结束点+1,终止点使用大的终止点
		//中序子序列:起始点要从根结点往后一步,终止点使用大的终止点
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
		                               rootInorder + 1, endInorder);
		//构造之后挂成本结点右子树
	}

	return root;//返回构造好的结点给上层调用者
}


// 参数:
//        preorder:     前序遍历序列数组
//        inorder:      中序遍历序列数组
//        length:       数组的长度,两个序列一样
// 返回值:
//        以输入的前序和中序遍历序列所构造的二叉树的根节点地址
BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
	//输入合法性校验
	if(preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;

	//调用递归的构造结点的函数,传入最大的序列前后值,构造成整棵二叉树
	return ConstructCore(preorder, preorder + length - 1,
	                     inorder, inorder + length - 1);
}

//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
int main() {
	const int length = 8;//序列长度 
	int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};//前序 
	int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};//中序
	 
	try {
		//使用前序和中序构造整棵二叉树,获得根节点 
		BinaryTreeNode* root = Construct(preorder, inorder, length); 
		PrintTree(root);//输出 
		DestroyTree(root);//销毁 
	} catch(exception& exception) {
		printf("Invalid Input.\n");
	}
}

