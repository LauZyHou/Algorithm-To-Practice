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
    bool recur(TreeNode* a, TreeNode* b) {
        if(!a && !b)
            return true;
        if(!a || !b || a->val!=b->val)
            return false;
        return recur(a->left, b->right) && recur(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return recur(root->left, root->right);     
    }
};