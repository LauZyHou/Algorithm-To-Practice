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
	int maxDepth;
	TreeNode* ans;

	void inOrder(TreeNode* t,int depth) {
		//中序遍历(左中右),在最深层接触到的第一个节点肯定就是所求(所以用>而不是>=)
		if(t==nullptr)
			return ;
		inOrder(t->left,depth+1);
		if(depth>maxDepth) {
			maxDepth = depth;
			ans = t;
		}
		inOrder(t->right,depth+1);
	}

    int findBottomLeftValue(TreeNode* root) {
        this->maxDepth = 0;
		ans = nullptr;
		inOrder(root,1);
		return this->ans->val;
    }
};