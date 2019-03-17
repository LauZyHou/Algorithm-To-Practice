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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
		vector<double> ans;
		if(root==nullptr)
			return ans;
		q.push(root);
		while(!q.empty()){
			int len = q.size();
			long long level_sum = 0;
			for(int i=0;i<len;i++){
				TreeNode* now = q.front();
				level_sum += now->val;
				q.pop();
				if(now->left)
					q.push(now->left);
				if(now->right)
					q.push(now->right);
			}
			ans.push_back(level_sum*1.0/len);
		}
		return ans;
    }
};