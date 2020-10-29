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
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return {};
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int l, int r) {
        if (l > r) return {nullptr};
        vector<TreeNode*> res;

        // 枚举根节点位置
        for (int i = l; i <= r; i ++) {
            auto left = dfs(l, i - 1), right = dfs(i + 1, r);
            // 左边选一个右边选一个
            for (auto lt : left)
                for (auto rt : right) {
                    auto root = new TreeNode(i);
                    root->left = lt, root->right = rt;
                    res.emplace_back(root);
                }
        }

        return res;
    }
};