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
	int now;
	bool found;
	int ask;

	void traceback(TreeNode* t) {
		if(!t || found)
			return ;
		traceback(t->left);
		now--;
		if(now==0) {
			found = true;
			ask = t->val;
			return ;
		}
		traceback(t->right);
	} 

    int kthSmallest(TreeNode* root, int k) {
        now = k;
		found = false;
		traceback(root);
		return ask;
    }
};