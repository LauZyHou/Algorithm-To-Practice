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
	TreeNode* build(vector<int>& in,int a1,int b1,vector<int>& po,int a2,int b2) {
		int len = b1-a1;
		if(len!=b2-a2)
			return nullptr;
		if(len==0)
			return nullptr;
		if(len==1)
			return new TreeNode(in[a1]);
		int end = po[b2-1];
		//find position
		int pos = a1;
		for(;pos<b1;pos++)
			if(in[pos]==end)
				break;
		//build now Node
		TreeNode* ans = new TreeNode(end);
		ans->left = build(in,a1,pos,po,a2,a2+pos-a1);
		ans->right = build(in,pos+1,b1,po,a2+pos-a1,b2-1);
		return ans;

	}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int len = inorder.size();
		int plen = postorder.size();
		if(len!=plen)
			return nullptr;
		return build(inorder,0,len,postorder,0,len);
    }
};