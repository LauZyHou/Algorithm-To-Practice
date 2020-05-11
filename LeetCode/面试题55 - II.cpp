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
    bool ans = true;
public:
    bool isBalanced(TreeNode* root) {
        h(root);
        return ans;
    }

    int h(TreeNode* t) {
        if(!t || !ans)
            return 0;
        int lh = h(t->left);
        int rh = h(t->right);
        if(abs(lh-rh)>1)
            ans = false;
        return max(lh,rh)+1;
    }
};