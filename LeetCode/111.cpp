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
	int ans = 0;
	int now = 0;

	void dfs(TreeNode* t) {
		//叶子
		if(!t->left && !t->right) {
			if(!ans || now<ans)
				ans = now;
			return ;
		}
		now+=1;
		if(t->left)
			dfs(t->left);
		if(t->right)
			dfs(t->right);
		now-=1;
	}

    int minDepth(TreeNode* root) {
		if(!root)
			return 0;
		now = ans = 0;
		dfs(root);
		return ans+1;
    }
};