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
	int ans = INT_MAX;
	int now = 0;
	bool go = false;
public:
	void orderIn(TreeNode* p){
		if(p==nullptr)
			return ;
		orderIn(p->left);
		
		if(go && p->val-now<ans)
			ans = p->val - now;
		now = p->val;
		go = true;
		
		orderIn(p->right);
	}

    int minDiffInBST(TreeNode* root) {
        ans = INT_MAX;
		orderIn(root);
		return ans;
    }
};