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
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
        	return 0;
        else
        	return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};

int max(const int& a,const int& b){
	return a>b?a:b;	
}
