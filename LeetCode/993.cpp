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
    bool isCousins(TreeNode* root, int x, int y) {
        bool findx=false,findy=false;
		TreeNode* father=nullptr;//x或者y(先找到的那个的父亲)
		//层序遍历,同层找到x和y判断一下父亲就行了
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			int levlen = q.size();
			while(levlen--){
				TreeNode* t = q.front();
				q.pop();
				TreeNode* lft = t->left;
				TreeNode* rgt = t->right;
				if(lft && lft->val==x || rgt && rgt->val==x){
					findx = true;
					if(findy && t!=father)//找到x时候t就是父亲
						return true;
					else if(findy)
						return false;
					father = t;
				}else if(lft && lft->val==y || rgt && rgt->val==y){
					findy = true;
					if(findx && t!=father)
						return true;
					else if(findx)
						return false;
					father = t;
				}
				if(lft)
					q.push(lft);
				if(rgt)
					q.push(rgt);
			}
			if(father)//等价于findx || findy
				return false;
		}
		return false;
	}
};