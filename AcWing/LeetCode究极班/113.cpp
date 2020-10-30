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
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root) dfs(root, sum);
        return ans;
    }

    void dfs(TreeNode* root, int sum) {
        sum -= root->val;
        path.emplace_back(root->val);
        if (!root->left && !root->right) {
            if (sum == 0)
                ans.emplace_back(path);
        }
        else {
            if (root->left)
                dfs(root->left, sum);
            if (root->right)
                dfs(root->right, sum);
        }
        path.pop_back();
    }
};