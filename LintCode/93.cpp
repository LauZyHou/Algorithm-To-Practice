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
private:
	bool balance;
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
	int height(TreeNode* r){
		if(!r || !balance)
			return 0;
		int lft = height(r->left);
		int rgt = height(r->right);
		if(abs(lft-rgt)>1)
			balance = false;
		return max(lft,rgt)+1;
	}

    bool isBalanced(TreeNode * root) {
        balance = true;
		height(root);
		return balance;
    }
};