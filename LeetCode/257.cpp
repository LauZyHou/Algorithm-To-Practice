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
private:
	vector<string> ans;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string tmp;
		dfs(root,tmp);
		return ans;
    }

	void dfs(TreeNode* nd,string tmp){
		if(nd==nullptr)
			return;
		string nums = to_string(nd->val);
		tmp+=nums;
		if(nd->left==nullptr && nd->right==nullptr){
			ans.push_back(tmp);
			return;
		}
		tmp+="->";
		if(nd->left)
			dfs(nd->left,tmp);
		if(nd->right)
			dfs(nd->right,tmp);
	}
};