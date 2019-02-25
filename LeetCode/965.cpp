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
    bool isUnivalTree(TreeNode* root) {
        if(root && !root->left && !root->right)
			return true;
		bool c1=true;
		if(root->left)
			c1 = root->left->val == root->val && isUnivalTree(root->left);
		bool c2=true;
		if(root->right)
			c2 = root->right->val == root->val && isUnivalTree(root->right);
		return c1&&c2;
    }
};