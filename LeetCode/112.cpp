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
private:
	int s;
public:
    bool hasPathSum(TreeNode* root, int sum) {
        s = sum;
		if(!root)
			return false;
		return dfs(root,0);
    }

	bool dfs(TreeNode* t,int n){
		if(!t)
			return false;
		n += t->val;
		if(!t->left && !t->right)
			return n==s;
		return dfs(t->left,n) || dfs(t->right,n);
	}
};