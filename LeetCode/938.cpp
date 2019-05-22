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
	int ans;
	int l,r;
	bool begin,end;

	void inOrder(TreeNode* t) {
		if(!t)
			return ;
		inOrder(t->left);
		if(end==true)
			return ;
		if(t->val==l)
			begin = true;
		if(t->val>r) {
			end = true;
			return ;
		}
		if(begin==true)
			ans += t->val;
		inOrder(t->right);
	}

    int rangeSumBST(TreeNode* root, int L, int R) {
		ans = 0;
		l = L;
		r = R;
		begin = false;
		end = false;
		inOrder(root);
		return ans;
	}
};