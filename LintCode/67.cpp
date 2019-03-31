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
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * r) {
        vector<int> ans;
		if(!r)
			return ans;
		stack<TreeNode*> s;
		while(r || !s.empty()){
			//往左走到底
			while(r){
				s.push(r);
				r = r->left;
			}
			//出一个节点,也就是最左下的节点
			//注意!只出一个!所以这里是if不是while
			if(!s.empty()){
				TreeNode* t = s.top();
				ans.push_back(t->val);
				s.pop();
				//右子树
				r = t->right;
			}
		}
		return ans;
    }
};