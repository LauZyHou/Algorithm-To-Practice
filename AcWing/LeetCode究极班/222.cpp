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
    int countNodes(TreeNode* root) {
        // 1. 左右均是满二叉树，两部分都用满二叉树的算法来计算
        // 2. 左右存在不是满二叉树的情况（可能在左边也可能在右边），两边都递归计算

        // 如果没有结点，就返回0
        if (!root) return 0;

        // 左侧往左走，右侧往右走，来计算走了多少步
        auto l = root->left, r = root->right;
        int x = 1, y = 1;
        while (l) l = l -> left, x ++ ;
        while (r) r = r -> right, y ++ ;
        // 如果走的步数相等则一定是情况1
        if (x == y) return (1 << x) - 1;
        // 否则是情况2
        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};