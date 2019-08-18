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
        queue<TreeNode*> q;
		vector<vector<int>> ans;
		if(!root)
			return ans;
		q.push(root);
		while(q.empty()==false) {
			vector<int> lev;
			int levLen = q.size();
			for(int i=0;i<levLen;i++) {
				TreeNode* tp = q.front();
				q.pop();
				lev.push_back(tp->val);
				if(tp->left)
					q.push(tp->left);
				if(tp->right)
					q.push(tp->right);
			}
			ans.push_back(lev);
		}
		return ans;
    }
};