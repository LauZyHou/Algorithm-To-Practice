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
	int ans = 0;
public:
    int findTilt(TreeNode* root) {
		//在求和过程中计算每个结点的坡度,将其加到ans上
		getSum(root);
		return ans;
    }

	int getSum(TreeNode* r){
		if(!r)
			return 0;
		int lftSum = getSum(r->left);
		int rgtSum = getSum(r->right);
		ans += abs(lftSum-rgtSum);
		return lftSum + r->val + rgtSum;
	}
};