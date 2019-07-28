/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        st = stack<TreeNode*>();
		if(!root)
			return ;
		while(root) {
			st.push(root);
			root = root->left;
		}
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* t = st.top();
		st.pop();
		int val = t->val;
		t = t->right;
		while(t) {
			st.push(t);
			t = t->left;
		}
		return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */