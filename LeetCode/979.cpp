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
	
	//返回过载量
	int dfs(TreeNode* t) {
		if(!t)
			return 0;
		int left = dfs(t->left);
		int right = dfs(t->right);
		ans += abs(left) + abs(right);
		return left + right + t->val - 1;
	}

    int distributeCoins(TreeNode* root) {
        //过载量,3的叶节点要移动出去2个,0的叶节点要移动出去-1个
		//一棵子树的过载量,就是这棵树要移动出去多少个
		//(就是总金币数-总节点数)
		//但不必直接这样计算,一棵子树的过载量可以由其左右子树过载量,及自己的金币数计算
		//因为自己金币数-自己节点数1,再加上左右子树过载量,也就是这棵子树过载量
		//要计算一共移动了多少次,也就是去计算根节点的所有子树过载量绝对值之和
		//对于这棵树本身,过载量一定是0
		ans = 0;
		dfs(root);
		return ans;
    }
};