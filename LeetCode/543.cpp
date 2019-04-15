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
	int ans = 0;
public:
	int height(TreeNode* t){
		if(!t)
			return 0;
		int lft = height(t->left);
		int rgt = height(t->right);
		if(lft+rgt>ans)
			ans = lft + rgt;
		return max(lft,rgt)+1;
	}

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
		//只要计算每个节点的两个子树的高度,然后取高度和最大的
		height(root);
		return ans;
	}
};