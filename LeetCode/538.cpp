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
private:
	int now;
public:
	void revOrderIn(TreeNode* p){
		if(!p)
			return ;
		revOrderIn(p->right);
		p->val += now;
		now = p->val;
		revOrderIn(p->left);
	}

    TreeNode* convertBST(TreeNode* root) {
        now = 0;
		revOrderIn(root);
		return root;
    }
};