/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        // 叶结点
        if (!root->left && !root->right)
            return 1;
        // 左空右不空
        if (!root->left)
            return minDepth(root->right) + 1;
        // 右不空左空
        if (!root->right)
            return minDepth(root->left) + 1;
        // 左右都不空
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};