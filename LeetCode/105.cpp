/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	unordered_map<int,int> mp;
	int idx = 0;//在中序序列中按先序顺序走的编号,可以指示当前是先序中的哪个元素

	TreeNode* traceback(vector<int>& pre, vector<int>& in,int lft,int rgt) {//中序中的左开始位置和右侧结束位置+1
		if(lft==rgt)
			return nullptr;
		int val = pre[idx++];//有元素,idx就+1
		int in_idx = mp[val];
		TreeNode* t = new TreeNode(val);//中
		t->left = traceback(pre,in,lft,in_idx);//左
		t->right = traceback(pre,in,in_idx+1,rgt);//右
		//这里是在中序遍历序列里找,但是找的顺序却是先序
		return t;
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
		//因为要在先序里找到元素后,到中序里去找元素位置
		//记录中序中每个元素的下标
		mp = unordered_map<int,int>();
		for(int i=0;i<len;i++) {
			mp[inorder[i]] = i;
		}
		return traceback(preorder,inorder,0,len);
    }
};