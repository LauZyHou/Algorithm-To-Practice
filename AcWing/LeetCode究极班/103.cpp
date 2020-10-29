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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;

        if (root) q.push(root);
        int cnt = 0;
        while (q.size()) {
            vector<int> level;
            int len = q.size();

            for (int i = 0; i < len; i ++) {
                auto t = q.front();
                q.pop();
                level.emplace_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }

            if (cnt++ & 1)
                reverse(level.begin(), level.end());
            res.emplace_back(level);
        }

        return res;
    }
};