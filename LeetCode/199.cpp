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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
		if(!root)
			return ans;
		queue<TreeNode*> q;
		q.push(root);
		while(q.empty()==false) {
			int lev = q.size();
			for(int i=0;i<lev;i++) {
				TreeNode* t = q.front();
				q.pop();
				if(t->left)
					q.push(t->left);
				if(t->right)
					q.push(t->right);
				if(i==lev-1)
					ans.push_back(t->val);
			}
		}
		return ans;
    }
};