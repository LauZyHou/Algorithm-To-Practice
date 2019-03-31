/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> ans;
		if(!root)
			return ans;
		stack<TreeNode*> s;
		s.push(root);
		while(!s.empty()){
			TreeNode* t = s.top();
			ans.push_back(t->val);
			s.pop();
			if(t->right)
				s.push(t->right);
			if(t->left)
				s.push(t->left);
		}
		return ans;
    }
};