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
    string tree2str(TreeNode* t) {
		if(t==nullptr)
			return "";
        string ans = "";
		ans += to_string(t->val);
		//左右都空,叶子结点要省略两个括号
		if(!t->left && !t->right)
			return ans;
		ans += "(";
		ans += tree2str(t->left);
		ans += ")";
		//右侧空则省略右侧括号
		if(!(t->right))
			return ans;
		ans +="(";
		ans += tree2str(t->right);
		ans += ")";
		return ans;
    }
};