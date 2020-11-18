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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            for (int i = 0; i < len; i ++ ) {
                auto t = q.front();
                q.pop();
                if (t -> left)
                    q.push(t->left);
                if (t -> right)
                    q.push(t->right);
                if (i == len - 1)
                    res.emplace_back(t->val);
            }
        }
        return res;
    }
};
