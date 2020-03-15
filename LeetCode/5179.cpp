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
    vector<TreeNode*> v;
public:
    void inorder(TreeNode* t) {
        if(t) {
            inorder(t->left);
            v.push_back(t);
            inorder(t->right);
        }
    }

    TreeNode* construct(int begin, int end) {
        if(begin>=end)
            return nullptr;
        int mid = (begin+end)/2;
        TreeNode* ret = v[mid];
        ret->left = construct(begin, mid);
        ret->right = construct(mid+1,end);
        return ret;
    }

    TreeNode* balanceBST(TreeNode* root) {
        v.clear();

        inorder(root);

        int len = v.size();
        return construct(0, len);
    }
};