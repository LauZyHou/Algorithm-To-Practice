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
    bool ans;
    TreeNode* pre;

    void inorder(TreeNode* t) {
        if (t -> left)
            inorder(t -> left);
        if (!pre) {
            pre = t;
        }
        else if (t -> val <= pre -> val) {
            ans = false;
            return ;
        }
        pre = t;
        if (t -> right)
            inorder(t -> right);
    }
public:
    bool isValidBST(TreeNode* root) {
        ans = true;
        pre = nullptr;
        if (!root)
            return true;
        inorder(root);
        return ans;
    }
};