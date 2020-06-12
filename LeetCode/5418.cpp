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
private:
    int a[10] = {0};
    int ans = 0;

    bool judge() {
        int cnt = 0;
        for(int i=0;i<10;i++) {
            if(a[i]&1)
                cnt++;
            if(cnt > 1)
                return false;
        }
        return true;
    }

    void dfs(TreeNode* t) {
        a[t->val]++;
        if(!t->left && !t->right) {
            if(judge())
                ans++;
            a[t->val]--;
            return;
        }
        if(t->left)
            dfs(t->left);
        if(t->right)
            dfs(t->right);
        a[t->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)
            return 0;
        dfs(root);
        return ans;
    }
};