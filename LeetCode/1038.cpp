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
	int nowsum = 0;

	//反向中序:右中左遍历
	void yzz(TreeNode* t) {
		if(t==nullptr)
			return ;
		yzz(t->right);
		t->val += nowsum;
		nowsum = t->val;
		yzz(t->left);
	}

    TreeNode* bstToGst(TreeNode* root) {
        nowsum = 0;//Solution对象只创建一次,成员方法可以调用多次
		yzz(root);
		return root;
    }
};