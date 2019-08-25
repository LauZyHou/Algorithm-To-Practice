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
	TreeNode* traceback(TreeNode* t,int& h) {
		if(!t) {
			h = 0;
			return nullptr;
		}
		int lh,rh;//左右子树的高度
		TreeNode* lRoot = traceback(t->left,lh);
		TreeNode* rRoot = traceback(t->right,rh);
		if(lh==rh) {
			h = lh+1;
			return t;
		} else if(lh>rh) {
			h = lh+1;
			return lRoot;
		}
		//else
		h = rh+1;
		return rRoot;
	}

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
		int _a;
		return traceback(root,_a);
    }
};