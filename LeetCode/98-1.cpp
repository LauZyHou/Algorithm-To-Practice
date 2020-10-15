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
    TreeNode* pre;
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        if (!isValidBST(root -> left))
            return false;
        if (pre && root -> val <= pre -> val)
            return false;
        pre = root;
        return isValidBST(root -> right);
    }
};