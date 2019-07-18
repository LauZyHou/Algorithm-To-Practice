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
	bool dfs(TreeNode* t) {
		if(t->left!=nullptr)
			if(false==dfs(t->left))
				t->left=nullptr;
		if(t->right!=nullptr)
			if(false==dfs(t->right))
				t->right=nullptr;
		if(!t->left && !t->right && t->val==0)
			return false;
		return true;
	}

    TreeNode* pruneTree(TreeNode* root) {
		bool b=false;
        if(root!=nullptr)
			b = dfs(root);
		return b==false ? nullptr : root;
	}
};