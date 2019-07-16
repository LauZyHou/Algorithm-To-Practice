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
	vector<int> a;

	TreeNode* go(int begin,int end) {
		if(begin>end)
			return nullptr;
		TreeNode* ret = new TreeNode(a[begin]);
		int i = begin+1;
		for(;a[i]<a[begin];i++)
			;
		ret->left = go(begin+1,i-1);
		ret->right = go(i,end);
		return ret;
	}

    TreeNode* bstFromPreorder(vector<int>& v) {
        a = v;
		int len = a.size();
		return go(0,len-1);
    }
};