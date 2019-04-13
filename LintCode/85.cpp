/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode * insertNode(TreeNode * root, TreeNode * node) {
        if(!root)
			return node;
		TreeNode *r = root;
		TreeNode *t;
		bool lft;
		while(r){
			t = r;
			if(node->val>r->val){
				r = r->right;
				lft = false;
			}
			else {
				r = r->left;
				lft = true;
			}
		}
		if(lft)
			t->left = node;
		else
			t->right = node;
		return root;
    }
};