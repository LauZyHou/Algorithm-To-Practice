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
        check(root);
        return ans;
    }

    int check(TreeNode* t) {
        if(!t || !ans)
            return 0;
        int left = check(t->left);
        int right = check(t->right);
        if(abs(left-right)>1)
            ans = false;
        return max(left,right)+1;
    }
};