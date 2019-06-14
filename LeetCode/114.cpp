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
    void flatten(TreeNode* root) {
        if(root==nullptr)
			return ;
		//先操作左右子树,然后再连接起来(中,左子树,右子树)
		flatten(root->left);
		flatten(root->right);
		//记录一下右子树指针
		TreeNode* r = root->right;
		//原来左子树挂到右子树上
		root->right = root->left;
		//左子树清空
		root->left = nullptr;
		//原来右子树挂到最右边
		while(root->right) {
			root = root->right;
		}
		root->right = r;
    }
};