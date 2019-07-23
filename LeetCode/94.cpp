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
	vector<int> ans;
	
	void inOrder(TreeNode* t) {
		if(!t)
			return ;
		inOrder(t->left);
		ans.push_back(t->val);
		inOrder(t->right);
	}

    vector<int> inorderTraversal(TreeNode* root) {
        ans = vector<int>();
		inOrder(root);
		return ans;
    }
};