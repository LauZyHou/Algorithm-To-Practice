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
    int k, ans;

    int kthSmallest(TreeNode* root, int _k) {
        k = _k;
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* t) {
        if (!t) return ;
        dfs(t -> left);
        if (-- k == 0) {
            ans = t -> val;
            return ;
        }
        dfs(t -> right);
    }
};