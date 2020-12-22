/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        del(root, key);
        return root;
    }

    // 这里传一个引用，那么在修改root的指向的时候就都是同步变化的了
    void del(TreeNode* &root, int key) {
        if (!root) return ; // 根节点是空
        if (key == root->val) {
            // 当前是叶子结点
            if (!root->left && !root->right) root = nullptr; // 这里就能看出用引用的好处，因为root可能是父结点左或者右儿子，但是这里都能直接改
            // 如果没有左儿子，那么就只有右儿子，直接拿右子树盖过来就行
            else if (!root->left) root = root->right;
            // 如果没有右儿子，那么就只有左儿子，直接拿左子树盖过来就行
            else if (!root->right) root = root->left;
            // 左右儿子都存在
            else {
                // 先找到当前结点的后继
                auto p = root->right;
                while (p->left) p = p->left;
                // 把后继的值放到当前结点，然后把后继结点删掉
                root->val = p->val;
                // 这里删除p的时候要写root->right，不能写p，不然就不是root的一个域了，就没法通过传引用自动接在root上了
                del(root->right, p->val);
            }
        }
        else if (key < root->val) del(root->left, key);
        else del(root->right, key);
    }
};