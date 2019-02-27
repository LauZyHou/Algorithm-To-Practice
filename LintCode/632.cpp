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
     * @param root: the root of tree
     * @return: the max node
     */
	TreeNode * max=nullptr;
    TreeNode * maxNode(TreeNode * root) {
        if(root==nullptr)
			return nullptr;
		if(max==nullptr || root->val>max->val)
			max = root;
		TreeNode *p;
		if(max==nullptr || (p=maxNode(root->left))!=nullptr && p->val>max->val)
			max = p;
		if(max==nullptr || (p=maxNode(root->right))!=nullptr && p->val>max->val)
			max = p;
		return max;
    }
};