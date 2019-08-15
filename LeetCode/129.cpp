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
	int ans;

	void dfs(TreeNode* t,int n) {
		if(!t->left && !t->right) {
			ans += n*10+t->val;
			return ;
		}
		if(t->left)
			dfs(t->left,n*10+t->val);
		if(t->right)
			dfs(t->right,n*10+t->val);
	}

    int sumNumbers(TreeNode* root) {
		if(!root)
			return 0;
		ans = 0;
        dfs(root,0);
		return ans;
    }
};