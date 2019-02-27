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
    TreeNode* searchBST(TreeNode* root, int val) {
		if(val==root->val)
			return root;
		if(val<root->val)
			if(root->left)
				return searchBST(root->left,val);
			else
				return nullptr;
		else
			if(root->right)
				return searchBST(root->right,val);
			else
				return nullptr;
	}
};