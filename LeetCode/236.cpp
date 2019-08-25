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
	TreeNode* ans;

	int traceback(TreeNode* root, TreeNode* p, TreeNode* q) {
		//中左右,这里面有两个找到目标节点了当前root就是所求了
		if(!root || ans)//ans!=nullptr说明已经找到了,不必再找了
			return 0;
		int lft = traceback(root->left,p,q);
		int rgt = traceback(root->right,p,q);
		int mid = 0;
		if(root->val==p->val || root->val==q->val)
			mid = 1;
		if(lft+mid+rgt>=2)
			ans = root;
		return lft+mid+rgt>=1 ? 1 : 0;
	}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		ans = nullptr;
        traceback(root,p,q);
		return ans;
    }
};