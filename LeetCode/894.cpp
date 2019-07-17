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
	//记录每个N对应的allPossibleFBT节点们
	unordered_map<int,vector<TreeNode*>> um;//打表

	Solution() {
		//当为1时如果um里没东西会无限递归,所以在这加上
		um[1] = vector<TreeNode*>();
		um[1].push_back(new TreeNode(0));
	}

    vector<TreeNode*> allPossibleFBT(int N) {
        if(um.find(N)!=um.end())//如果找到,说明已经计算过,不重复计算
			return um[N];

		um[N] = vector<TreeNode*>();
		//非0时,至少为3,遍历所有可能的左右子树
		//因为满二叉树节点必须是奇数
		//左子树从1,3,5,7..N-2,相应的右子树从N-2,N-4,...,1
		for(int lft=1;lft<=N-2;lft++) {
			int rgt = N-1-lft;
			for(TreeNode* leftNode : allPossibleFBT(lft)) {
				for(TreeNode* rightNode : allPossibleFBT(rgt)) {
					TreeNode* tt = new TreeNode(0);
					tt->left = leftNode;
					tt->right = rightNode;
					um[N].push_back(tt);
				}
			}
		}
		return um[N];
    }
};