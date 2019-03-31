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
	//用[左][右]的遍历,[中]永远不是要找的节点
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
			return 0;
		//只要判断一个结点是叶子,而且父亲的左孩子是这个节点,这个就是要找的节点
		//因为没有指向父节点的指针,所以这里直接判断当前节点的左孩子是不是满足要求
		if(root->left && !root->left->left && !root->left->right)
			return root->left->val + sumOfLeftLeaves(root->right);
		return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};