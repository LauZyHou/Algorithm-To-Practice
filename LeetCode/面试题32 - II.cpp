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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        if(!root)
            return ans;
        que.push(root);
        while(!que.empty()) {
            int len = que.size();
            vector<int> lev(len);
            for(int i=0;i<len;i++) {
                TreeNode* t = que.front();
                lev[i] = t->val;
                que.pop();
                if(t->left)
                    que.push(t->left);
                if(t->right)
                    que.push(t->right);
            }
            ans.push_back(lev);
        }
        return ans;
    }
};