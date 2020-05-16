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
    TreeNode* getTargetCopy(TreeNode* a, TreeNode* b, TreeNode* t) {
        if(a == nullptr)
            return nullptr;
        // 中
        if(a == t)
            return b;
        // 左
        TreeNode* l = getTargetCopy(a->left, b->left, t);
        if(l)
            return l;
        // 右
        TreeNode* r = getTargetCopy(a->right, b->right, t);
        if(r)
            return r;
        return nullptr;        
    }
};