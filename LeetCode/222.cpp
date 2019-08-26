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
	int hei(TreeNode* t) {
		int ret = 0;
		while(t) {
			ret++;
			t = t->left;
		}
		return ret;
	}

    int countNodes(TreeNode* root) {
        if(!root)//递归出口:空数节点数0
			return 0;
		//判断左右子树高度
		int lftLen = hei(root->left);
		int rgtLen = hei(root->right);
		//左右子树高度相等,左子树一定是满lftLen高了
		if(lftLen==rgtLen) {
			//计算右子树节点数,左子树+root一共2^lftLen个节点
			return countNodes(root->right) + (1<<lftLen);
		}
		//高度不等,对于完全二叉树一定是左子树高,这时右子树一定是满rgtLen高了
		return countNodes(root->left) + (1<<rgtLen);
    }
};