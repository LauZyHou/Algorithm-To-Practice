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
private:
	vector<int> v;
public:
	void inOrder(TreeNode* r){
		if(!r)
			return ;
		inOrder(r->left);
		v.push_back(r->val);
		inOrder(r->right);
	}

    bool findTarget(TreeNode* root, int k) {
        vector<int>().swap(v);
		inOrder(root);
		int len = v.size();
		int i = 0;
		int j = len-1;
		while(i<j){
			int tmp = v[i]+v[j];
			if(tmp==k)
				return true;
			if(tmp>k)
				j--;
			else
				i++;
		}
		return false;
    }
};