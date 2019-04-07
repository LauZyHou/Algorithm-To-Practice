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
    bool isSymmetric(TreeNode* root) {
		if(!root)
			return true;
		return isMirror(root->left,root->right);
    }

	bool isMirror(TreeNode* a,TreeNode* b){
		if(!a && !b)
			return true;
		if(a && b && a->val==b->val){
			return isMirror(a->left,b->right) && isMirror(a->right,b->left);
		}
		return false;
	}
};