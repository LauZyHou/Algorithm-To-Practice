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
	vector<int> v;
public:
	void inOrder(TreeNode* p){
		if(p==nullptr)
			return;
		inOrder(p->left);
		v.push_back(p->val);
		inOrder(p->right);
	}

    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
		int len = v.size();
		int ans = abs(v[0]-v[1]);
		if(len==2)
			return ans;
		for(int i=2;i<len;i++){
			int tmp = abs(v[i]-v[i-1]);
			if(tmp<ans)
				ans = tmp;
		}
		return ans;
    }
};