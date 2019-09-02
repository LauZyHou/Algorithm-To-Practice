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
    vector<int> largestValues(TreeNode* root) {
		vector<int> ans;
		if(!root)
			return ans;
		queue<TreeNode*> q;
		q.push(root);
		while(q.empty()==false) {
			int len = q.size();
			TreeNode* t = q.front();
			int nowmax = t->val;
			if(t->left)
				q.push(t->left);
			if(t->right)
				q.push(t->right);
			q.pop();
			for(int i=1;i<len;i++) {
				t = q.front();
				q.pop();
				if(t->val>nowmax)
					nowmax = t->val;
				if(t->left)
					q.push(t->left);
				if(t->right)
					q.push(t->right);
			}
			ans.push_back(nowmax);
		}
		return ans;
    }
};