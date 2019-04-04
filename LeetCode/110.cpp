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
	int height(TreeNode* t){
		if(!t)
			return 0;
		return 1+max(height(t->left),height(t->right));
	}

    bool isBalanced(TreeNode* root) {
		if(!root)
			return true;
		if(abs(height(root->left)-height(root->right))<2)
			return isBalanced(root->left) && isBalanced(root->right);
		return false;
    }
};