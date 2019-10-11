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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* nd = new TreeNode(val);
		if(!root || root->val<val) {
			nd->left = root;
			return nd;
		}
		TreeNode* p = root;
		while(p->right && p->right->val>val)
			p = p->right;
		nd->left = p->right;
		p->right = nd;
		return root;
    }
};