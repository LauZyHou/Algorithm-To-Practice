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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode * root) {
		if(!root)
			return 0;
        queue<TreeNode*> q;
		q.push(root);
		int ans = 0;
		while(!q.empty()){
			int len = q.size();
			while(len--){
				TreeNode* t = q.front();
				q.pop();
				if(t->left)
					q.push(t->left);
				if(t->right)
					q.push(t->right);
			}
			ans++;
		}
		return ans;
    }
};