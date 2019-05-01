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
	int maxi;
	int nowval;
	TreeNode *pre;
	vector<int> ans;

	void inOrder(TreeNode* t){
		if(!t)
			return ;
		//lft
		inOrder(t->left);
		//mid
		if(!pre) {
			nowval = maxi = 1;
			ans.push_back(t->val);
		} else {
			if(pre->val==t->val)
				nowval++;
			else
				nowval = 1;

			if(nowval==maxi)
				ans.push_back(t->val);
			else if(nowval>maxi){
				ans.clear();
				ans.push_back(t->val);
				maxi = nowval;
			}
		}
		pre = t;
		inOrder(t->right);
	}

    vector<int> findMode(TreeNode* root) {
		ans.clear();
        maxi = nowval = 0;
		pre = nullptr;
		inOrder(root);
		return ans;
    }
};