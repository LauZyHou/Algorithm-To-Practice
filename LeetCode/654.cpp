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
	TreeNode* recursion(vector<int> &v,int b,int e) {
		if(b>e)
			return nullptr;
		//找最大值所在位置
		int maxidx = b;
		for(int i=b+1;i<=e;i++) {
			if(v[i]>v[maxidx])
				maxidx = i;
		}
		TreeNode* ans = new TreeNode(v[maxidx]);
		ans->left = recursion(v,b,maxidx-1);
		ans->right = recursion(v,maxidx+1,e);
		return ans;
	}

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return recursion(nums,0,nums.size()-1);
    }
};