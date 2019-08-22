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
	
	//标准态DFS,有null的放左边,两个都是null时候随意
	//注意两个节点val一样时候这题这样做不了,还好题里有说了每个结点val唯一
	void dfs(TreeNode* t,vector<int>& v) {
		if(!t) {
			v.push_back(-1);
			return ;
		}
		v.push_back(t->val);
		int val1 = t->left ? t->left->val : -1;
		int val2 = t->right ? t->right->val : -1;
		if(val1<val2) {
			dfs(t->left,v);
			dfs(t->right,v);
		} else {
			dfs(t->right,v);
			dfs(t->left,v);
		}
	}

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
		vector<int> v2;
		dfs(root1,v1);
		dfs(root2,v2);
		int len = v1.size();
		int len2 = v2.size();
		if(len2!=len)
			return false;
		for(int i=0;i<len;i++)
			if(v1[i]!=v2[i])
				return false;
		return true;
    }
};