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
	int cnt = 0;
public:
	//记录以root为根的树中加和为sum的路径总数
    int pathSum(TreeNode* root, int sum) {
        if(!root)
			return 0;
		addPath(root,sum);
		//左右子树,这里不使用返回值,因为在addPath中已经记录了路径,这里再加上去就会重复
		pathSum(root->left,sum);
		pathSum(root->right,sum);
		return cnt;
    }

	//记录以root为起始节点的加和为sum的路径总数
	void addPath(TreeNode* root,int sum){
		if(!root)
			return ;
		if(sum==root->val)
			cnt += 1;
		addPath(root->left,sum-root->val);
		addPath(root->right,sum-root->val);
	}
};