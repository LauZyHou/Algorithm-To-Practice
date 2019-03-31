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
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * r) {
        //对于每个节点，都压入两遍，在循环体中，每次弹出一个节点赋给p
		//如果p仍然等于栈的头结点，说明p的孩子们还没有被操作过，应该把它的孩子们加入栈中
		//否则，访问p。也就是说，第一次弹出，将p的孩子压入栈中，第二次弹出，访问p
		vector<int> ans;
		if(!r)
			return ans;
		stack<TreeNode*> s;
		s.push(r);
		s.push(r);
		TreeNode* t;
		while(!s.empty()){
			t = s.top();
			s.pop();
			//连续两个,就把子孩子入栈
			if(!s.empty() && t==s.top()){
				if(t->right){
					s.push(t->right);
					s.push(t->right);
				}
				if(t->left){
					s.push(t->left);
					s.push(t->left);
				}
			}
			else{
				ans.push_back(t->val);
			}
		}
		return ans;
    }
};