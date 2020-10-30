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
    int ans = 0;

    int sumNumbers(TreeNode* root) {
        if (root) dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* root, int t) {
        t = t * 10 + root->val;
        if (!root->left && !root->right)
            ans += t;
        if (root->left)
            dfs(root->left, t);
        if (root->right)
            dfs(root->right, t);
    }
};