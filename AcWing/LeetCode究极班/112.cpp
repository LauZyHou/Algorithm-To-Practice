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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        sum -= root->val; // 反向减掉当前值
        if (!root->left && !root->right) // 到了叶子结点
            return sum == 0;
        return root->left && hasPathSum(root->left, sum) || root->right && hasPathSum(root->right, sum);
    }
};