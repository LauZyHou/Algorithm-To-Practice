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
    TreeNode* pre;
    TreeNode *a1, *a2, *b1, *b2; // 最多两个逆序对，至少一个逆序对
    
    void recoverTree(TreeNode* root) {
        pre = a1 = a2 = b1 = b2 = nullptr;
        dfs(root);
        if (b1)
            swap(a1->val, b2->val);
        else
            swap(a1->val, a2->val);
    }

    void dfs(TreeNode* root) {  
        if (!root) return ;
        dfs(root->left);
        if (pre && root->val < pre->val) {
            if (!a1)
                a1 = pre, a2 = root;
            else
                b1 = pre, b2 = root;
        }
        pre = root;
        dfs(root->right);
    }
};