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

	void postOrder(TreeNode* t) {
		if(!t)
			return ;
		postOrder(t->left);
		postOrder(t->right);
		ans.push_back(t->val);
	}

    vector<int> postorderTraversal(TreeNode* root) {
        ans = vector<int>();
		postOrder(root);
		return ans;
    }
};