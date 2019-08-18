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
	vector<TreeNode*> gen(int a,int b) {
		vector<TreeNode*> v;
		if(a>b) {
			v.push_back(nullptr);
			return v;
		}
		for(int i=a;i<=b;i++) {
			vector<TreeNode*> leftVec = gen(a,i-1);
			vector<TreeNode*> rightVec = gen(i+1,b);
			for(TreeNode* lft : leftVec) {
				for(TreeNode* rgt : rightVec) {
					TreeNode* now = new TreeNode(i);
					now->left = lft;
					now->right = rgt;
					v.push_back(now);
				}
			}
		}
		return v;
	}

    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
			return vector<TreeNode*>();
		return gen(1,n);
    }
};