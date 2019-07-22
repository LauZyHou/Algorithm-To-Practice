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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
		vector<int> ans;
		
		if(!root)
			return ans;

		st.push(root);
		while(false==st.empty()) {
			TreeNode* tmp = st.top();
			st.pop();
			ans.push_back(tmp->val);
			if(tmp->left)
				st.push(tmp->left);
			if(tmp->right)
				st.push(tmp->right);
		}
		//得到的是中右左的顺序,翻转过来就是左右中的顺序了
		reverse(ans.begin(),ans.end());
		return ans;
    }
};