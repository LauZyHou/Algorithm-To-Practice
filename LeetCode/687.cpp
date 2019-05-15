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
    int ans = 0;

	int longestUnivaluePath(TreeNode* root) {
        if(!root)
			return 0;
		//从根节点递归跑一遍,就把ans算好了
		maxLeftRightArrowLen(root);
		return ans;
    }

	//最左或者最右的等值路径的最大长度
	int maxLeftRightArrowLen(TreeNode* t) {
		if(!t)
			return 0;
		//获取左子/右子的最长路径
		int lft = maxLeftRightArrowLen(t->left);
		int rgt = maxLeftRightArrowLen(t->right);
		//记录当前往左往右的路径长度
		int nowlft = 0;
		int nowrgt = 0;
		//和当前节点比较一下一样不一样,一样的时候就要算上当前的节点
		if(t->left && t->val==t->left->val)
			nowlft = lft+1;
		if(t->right && t->val==t->right->val)
			nowrgt = rgt+1;
		//注意,因为计算的是路径长度,不是节点数这里不需要-1
		ans = max(ans,nowlft+nowrgt);
		//返回的是最大的到当前节点的路径长
		return max(nowlft,nowrgt);
	}
};