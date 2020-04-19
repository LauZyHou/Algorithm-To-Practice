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
    unordered_map<TreeNode*,int> um;
public:
    int cal(TreeNode* t) {
        if(!t)
            return 0;
        if(um.count(t))
            return um[t];
        // 这个结点要
        int ans1 = t->val;
        if(t->left)
            ans1 += cal(t->left->left) + cal(t->left->right);
        if(t->right)
            ans1 += cal(t->right->left) + cal(t->right->right);
        // 这个结点不要
        int ans2 = cal(t->left) + cal(t->right);
        return um[t]=max(ans1, ans2);
    }

    int rob(TreeNode* root) {
        return cal(root);
    }
};