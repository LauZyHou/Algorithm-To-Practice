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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
		if(!root)
			return ans;
		queue<TreeNode*> q;
		stack<vector<int>> s;
		q.push(root);
		while(!q.empty()){
			int levelNum = q.size();
			vector<int> levVec;
			for(int i=0;i<levelNum;i++){
				TreeNode* nd = q.front();
				q.pop();
				//childern
				if(nd->left)
					q.push(nd->left);
				if(nd->right)
					q.push(nd->right);
				levVec.push_back(nd->val);
			}
			s.push(levVec);//not to ans
		}
		//reverse
		while(!s.empty()){
			vector<int> levVec = s.top();
			ans.push_back(levVec);
			s.pop();
		}
		return ans;
    }
};