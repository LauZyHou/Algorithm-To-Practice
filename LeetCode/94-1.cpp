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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
		TreeNode* cur = root;
		stack<TreeNode*> st;

		while(cur!=nullptr || false==st.empty()) {
			//一直向左,走到最左
			while(cur!=nullptr) {
				st.push(cur);
				cur = cur->left;
			}
			//取出栈顶,就是当前遍历到的元素,其左侧是没有元素的
			TreeNode* now = st.top();
			ans.push_back(now->val);
			st.pop();
			//接下来要遍历这个元素右子树
			cur = now->right;
		}
		return ans;
    }
};