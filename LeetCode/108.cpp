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
	TreeNode* buildTree(vector<int>& v,int a,int b){
		if(a==b)
			return new TreeNode(v[a]);
		if(b<a)
			return nullptr;
		int mid = (a+b)/2;
		TreeNode* p = new TreeNode(v[mid]);
		p->left = buildTree(v,a,mid-1);
		p->right = buildTree(v,mid+1,b);
		return p;
	}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
		int len = nums.size();
		if(len==0)
			return nullptr;
		return buildTree(nums,0,len-1);
    }
};