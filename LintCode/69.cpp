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
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * r){
        vector<vector<int>> ans;
		if(!r)
			return ans;
		queue<TreeNode*> q;
		q.push(r);
		while(!q.empty()){
			int len = q.size();
			vector<int> level;
			while(len--){
				TreeNode* t = q.front();
				q.pop();
				level.push_back(t->val);
				if(t->left)
					q.push(t->left);
				if(t->right)
					q.push(t->right);
			}
			ans.push_back(level);
		}
		return ans;
    }
};