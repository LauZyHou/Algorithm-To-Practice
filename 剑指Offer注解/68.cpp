#include<bits/stdc++.h>
#include"../Utilities/Tree.h"
using namespace std;

//递归函数
//获得pRoot到pNode的路径,将这个路径保存在path中,返回是否能到达
bool GetNodePath(const TreeNode* pRoot, const TreeNode* pNode, list<const TreeNode*>& path) {
	if(pRoot == pNode)//递归出口:同一结点
		return true;

	path.push_back(pRoot);//根结点是路径的第一个结点

	bool found = false;//先设定成不可达

	//前序遍历DFS,这层遍历所有子结点
	//更正:后面是用cbegin()而不是begin()
	vector<TreeNode*>::const_iterator i = pRoot->m_vChildren.cbegin();
	while(!found && i < pRoot->m_vChildren.end()) {//找到了,或者子结点全遍历完了就退出
		found = GetNodePath(*i, pNode, path);//递归地去看从子结点能否到那个路径
		++i;
	}

	if(!found)//没找到
		path.pop_back();//把这个结点弹出再回到上一层

	return found;//回到上一层
}

//得到两条路径path1和path2的最后一个公共结点
const TreeNode* GetLastCommonNode
(
    const list<const TreeNode*>& path1,
    const list<const TreeNode*>& path2
) {
	//两条路径的开始之处,更正:这里应用cbegin()而不是begin()
	list<const TreeNode*>::const_iterator iterator1 = path1.cbegin();
	list<const TreeNode*>::const_iterator iterator2 = path2.cbegin();

	const TreeNode* pLast = nullptr;//记录最后一个公共结点

	//两个迭代器都没走到底,更正:这里应用cend()而不是end()
	while(iterator1 != path1.cend() && iterator2 != path2.cend()) {
		if(*iterator1 == *iterator2)//存的内容是地址,地址一样就是同一个结点
			pLast = *iterator1;//这个结点成为目前找到的最后的公共结点

		//两个迭代器同步往下走
		iterator1++;
		iterator2++;
	}

	return pLast;//最后得到的就是最低(最后一个)公共结点
}

//在pRoot为根的树中找pNode1和pNode2的最低公共祖先并返回
const TreeNode* GetLastCommonParent(const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2) {
	//输入合法性检查
	if(pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
		return nullptr;

	//到pNode1的路径链表
	list<const TreeNode*> path1;
	GetNodePath(pRoot, pNode1, path1);

	//到pNode2的路径链表
	list<const TreeNode*> path2;
	GetNodePath(pRoot, pNode2, path2);

	//两个链表的最后一个公共结点即是所求
	return GetLastCommonNode(path1, path2);
}

// 形状普通的树
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
int main() {
	TreeNode* pNode1 = CreateTreeNode(1);
	TreeNode* pNode2 = CreateTreeNode(2);
	TreeNode* pNode3 = CreateTreeNode(3);
	TreeNode* pNode4 = CreateTreeNode(4);
	TreeNode* pNode5 = CreateTreeNode(5);
	TreeNode* pNode6 = CreateTreeNode(6);
	TreeNode* pNode7 = CreateTreeNode(7);
	TreeNode* pNode8 = CreateTreeNode(8);
	TreeNode* pNode9 = CreateTreeNode(9);
	TreeNode* pNode10 = CreateTreeNode(10);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode1, pNode3);

	ConnectTreeNodes(pNode2, pNode4);
	ConnectTreeNodes(pNode2, pNode5);

	ConnectTreeNodes(pNode4, pNode6);
	ConnectTreeNodes(pNode4, pNode7);

	ConnectTreeNodes(pNode5, pNode8);
	ConnectTreeNodes(pNode5, pNode9);
	ConnectTreeNodes(pNode5, pNode10);
	
	cout<<GetLastCommonParent(pNode1,pNode6,pNode8)->m_nValue<<endl;//2
	return 0;
}
