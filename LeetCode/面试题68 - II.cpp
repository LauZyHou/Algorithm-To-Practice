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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 递归出口，只要找到p或者q就返回
        if(!root || root==p || root==q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 左边找不到说明都在右边找到了
        if(!left)
            return right;
        // 右边找不到说明都在左边找到了
        if(!right)
            return left;
        // 左边右边都找到说明两边各有一个，当前就是根
        return root;
    }
};