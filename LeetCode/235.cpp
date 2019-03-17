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
	TreeNode* ans = nullptr;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		this->ans = nullptr;
		if(p->val<=q->val)
			lca(root,p,q);
		else
			lca(root,q,p);
		return this->ans;
    }

	void lca(TreeNode *rt,TreeNode* a,TreeNode* b){
		if(rt==nullptr)
			return;
		//二叉搜索树的最低公共节点,左边的<=它,右边的>=它
		if(a->val<=rt->val && b->val>=rt->val)
			this->ans = rt;
		//都比它大往右子树搜索
		else if(a->val>rt->val && b->val>rt->val)
			lca(rt->right,a,b);
		else if(a->val<rt->val && b->val<rt->val)
			lca(rt->left,a,b);
	}
};