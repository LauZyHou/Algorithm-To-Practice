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
    void add(TreeNode* p) {
        if(p->left)
            ans += p->left->val;
        if(p->right)
            ans += p->right->val;
    }
    void dfs(TreeNode* t) {
        if(!(t->val&1)) {
            if(t->left) {
                add(t->left);
            }
            if(t->right) {
                add(t->right);
            }
        }
        if(t->left)
            dfs(t->left);
        if(t->right)
            dfs(t->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root);
        return ans;
    }
};