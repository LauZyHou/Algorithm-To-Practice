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
	map<int,int> mp;

	int dfs(TreeNode* t) {
		int ret = t->val;
		if(t->left)
			ret += dfs(t->left);
		if(t->right)
			ret += dfs(t->right);
		if(mp.find(ret)==mp.end())
			mp[ret] = 1;
		else
			mp[ret] += 1;
		return ret;
	}

    vector<int> findFrequentTreeSum(TreeNode* root) {
        mp = map<int,int>();
		vector<int> ans;
		if(!root)
			;
		else {
			dfs(root);
			int maxNum = 0;
			for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
				if(it->second>maxNum)
					maxNum = it->second;
			}
			for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
				if(it->second == maxNum)
					ans.push_back(it->first);
			}
		}
		return ans;
    }
};