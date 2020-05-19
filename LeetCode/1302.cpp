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
private:
    int ans = 0;
    int maxdep = 0;
    void dfs(TreeNode* t, int lev) {
        if(!t->left && !t->right) {
            if(lev == maxdep) {
                ans += t->val;
            }
            else if(lev > maxdep) {
                maxdep = lev;
                ans = t->val;
            }
        }
        if(t->left)
            dfs(t->left, lev+1);
        if(t->right)
            dfs(t->right, lev+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};