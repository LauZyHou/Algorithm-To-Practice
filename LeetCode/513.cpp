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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
		q.push(root);
		TreeNode* ans;
		while(!q.empty()) {
			int len = q.size();
			ans = q.front();//每一层最左侧的节点
			while(len--) {
				TreeNode* t = q.front();
				q.pop();
				if(t->left)
					q.push(t->left);
				if(t->right)
					q.push(t->right);
			}
		}
		return ans->val;
    }
};