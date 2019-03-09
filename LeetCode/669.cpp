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
	TreeNode* minOrder(TreeNode* rt,int L,int R){
		if(rt==nullptr)
			return rt;
		if(rt->val > R)
			return minOrder(rt->left,L,R);
		if(rt->val < L)
			return minOrder(rt->right,L,R);
		rt->left = minOrder(rt->left,L,R);
		rt->right = minOrder(rt->right,L,R);
		return rt;
	}

    TreeNode* trimBST(TreeNode* root, int L, int R) {
        return this->minOrder(root,L,R);
    }
};