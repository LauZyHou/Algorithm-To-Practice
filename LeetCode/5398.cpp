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
    int ans = 0;
    stack<int> st; // 存路径上结点的最大值，随回溯同进同退
    void dfs(TreeNode* t) {
        if(st.empty() || st.top() <= t->val) {
            st.push(t->val);
            ans++;
        }
        else {
            st.push(st.top());
        }
        if(t->left)
            dfs(t->left);
        if(t->right)
            dfs(t->right);
        st.pop();
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root);
        return ans;
    }
};