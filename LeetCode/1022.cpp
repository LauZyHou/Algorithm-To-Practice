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
	const int mod = 1000000007;
	int sum = 0;

	//
	void dfs(TreeNode* t,int fval) {
		if(!t)
			return ;
		//计算到当前节点的值
		int now = fval<<1 | t->val;
		//判断是不是叶子结点
		if(t->left==nullptr && t->right==nullptr) {
			sum = (sum + now%mod)%mod;
			return ;
		}
		dfs(t->left, now);
		dfs(t->right, now);
	}

    int sumRootToLeaf(TreeNode* root) {
		sum = 0;
		//根节点没有父节点,所以这里用0(高位多个0不影响结果值)
		dfs(root,0);
		return sum;
    }
};