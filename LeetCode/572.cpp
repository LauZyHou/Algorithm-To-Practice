class Solution {
public:
	//前序遍历
	bool order(TreeNode* r,TreeNode* t){
		if(!r)
			return false;
		//中
		if(isSame(r,t))
			return true;
		//左右
		return order(r->left,t) || order(r->right,t);
	}
	
	bool isSame(TreeNode* r, TreeNode* t){
		if(!r && !t)
			return true;
		if(!r || !t)
			return false;
		return r->val==t->val && isSame(r->left,t->left) && isSame(r->right,t->right);
	}

    bool isSubtree(TreeNode* s, TreeNode* t) {
        return order(s, t);
    }
};