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
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root || !root->left && !root->right)
            return root;
        TreeNode* t = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(t);
        return root;
    }
};