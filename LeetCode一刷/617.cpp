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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(nullptr==t1 && nullptr==t2)
        	return nullptr;
        
		//root
		int val;
		if(nullptr==t1)
			val=t2->val;
		else if(nullptr==t2)
			val=t1->val;
		else
			val=t1->val+t2->val;
		TreeNode* root=new TreeNode(val);
        //left
        root->left=mergeTrees(t1!=nullptr?t1->left:nullptr,t2!=nullptr?t2->left:nullptr);
        //right
        root->right=mergeTrees(t1!=nullptr?t1->right:nullptr,t2!=nullptr?t2->right:nullptr);
        
        return root;
    }
};
