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
    int cnt = 0;
    int ans;
public:
    int kthLargest(TreeNode* root, int k) {
        cnt = 0;
        recursive(root, k);
        return ans;
    }

    void recursive(TreeNode* t, int p) {
        if(!t)
            return ;
        if(cnt==p) {
            return ;
        }
        recursive(t->right, p);
        cnt++;
        if(cnt==p)
            ans = t->val;
        recursive(t->left, p);
    }
    
};