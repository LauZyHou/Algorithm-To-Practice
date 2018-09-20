#include<bits/stdc++.h>
using namespace std;

// 参数:
//        sequence:       后续遍历序列 
//        length:         序列的长度 
// 返回值:
//        这个后序遍历序列能否属于某BST(二叉搜索树) 
bool VerifySquenceOfBST(int sequence[], int length) {
	if(sequence == nullptr || length <= 0)//输入合法性校验 
		return false;

	int root = sequence[length - 1];//根节点是最后一个结点 

	//在二叉搜索树中左子树的结点小于根结点 
	int i = 0;
	for(; i < length - 1; ++ i) {//左右中,所以从左向右扫描
		if(sequence[i] > root)//发现第一个大于根节点的值 
			break;//这时就退出,i点左侧的全部值属于左子树 
	}

	//在二叉搜索树中右子树的结点大于根结点
	int j = i;//从刚刚找到的分界位置 
	for(; j < length - 1; ++ j) {//继续向后检查应当是右子树的部分 
		if(sequence[j] < root)//如果发现比根结点小的值 
			return false;//说明该序列不满足要求,绝不是BST的后续遍历序列 
	}

	//判断左子树是不是二叉搜索树
	bool left = true;
	if(i > 0)//分界点i>0左子树才是真实存在的,即至少有个sequence[0]结点\
		//分界点i正好表示其左侧的结点数,即左子树结点数 
		left = VerifySquenceOfBST(sequence, i);

	//判断右子树是不是二叉搜索树
	bool right = true;
	if(i < length - 1)//分界点i不到达根结点位置,右子树才是真实存在的
		//序列起始点要跳过i个左子树结点,序列长度要减掉1个根节点和i个左子树结点 
		right = VerifySquenceOfBST(sequence + i, length - i - 1); 
	
	//左右子树都为BST时,在该子树上才能认为是BST 
	return (left && right);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
int main() {
	int data[] = {4, 8, 6, 12, 16, 14, 10};
	cout<<boolalpha<<VerifySquenceOfBST(data,sizeof(data)/sizeof(int));
	return 0;
}

