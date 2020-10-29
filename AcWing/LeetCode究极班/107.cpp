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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if (root) q.push(root);
        while (q.size()) {
            int len = q.size();
            vector<int> level;

            while (len --) {
                auto t = q.front();
                q.pop();
                level.emplace_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }

            ans.emplace_back(level);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};