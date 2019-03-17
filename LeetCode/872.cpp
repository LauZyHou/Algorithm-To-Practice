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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        int a[100],alen=0;
		int b[100],blen=0;
		search(root1,a,&alen);
		search(root2,b,&blen);
		if(alen!=blen) return false;
		for(int i=0;i<alen;i++)
			if(a[i]!=b[i]) return false;
		return true;
    }

	//要查找的子树根,存储叶子序列的首地址,当前存储到的下标地址
	void search(TreeNode* rt,int* leaves,int* idx){
		if(rt==nullptr)
			return;
		//找到了叶子
		if(rt->left==nullptr && rt->right==nullptr){
			leaves[(*idx)++]=rt->val;
			return;
		}
		search(rt->left,leaves,idx);
		search(rt->right,leaves,idx);
	}
};