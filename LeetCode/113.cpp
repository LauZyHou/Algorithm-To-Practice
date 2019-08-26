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
	vector<vector<int>> ans;
	int s;

	void traceback(TreeNode* t,int n,vector<int>& v) {
		v.push_back(t->val);
		if(!t->left && !t->right) {
			if(n+t->val==s)
				ans.push_back(vector<int>(v));
		}
		if(t->left){
			traceback(t->left,n+t->val,v);
		}
		if(t->right) {
			traceback(t->right,n+t->val,v);
		}
		v.pop_back();
	}

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		ans = vector<vector<int>>();
		if(!root)
			return ans;
		s = sum;
		vector<int> v;
		traceback(root,0,v);
		return ans;
    }
};