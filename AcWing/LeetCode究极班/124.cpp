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
    int ans;

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }

    // 求从u往下走的最大和
    int dfs(TreeNode* u) {
        if (!u) return 0;
        int l = max(0, dfs(u->left)), r = max(0, dfs(u->right));
        ans = max(ans, l + r + u->val);
        return u->val + max(l, r);
    }
};