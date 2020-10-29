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
    bool ans = true; // 左右子树高度差的最大值不超过1
    
    bool isBalanced(TreeNode* root) {
        fake_height(root);
        return ans;
    }

    int fake_height(TreeNode* root) {
        if (!root) return 0;
        if (!ans) return 0; // 剪枝，如果已经不满足了，直接返回任意一个数，因为结果不是真的要求高度
        int l = fake_height(root->left);
        int r = fake_height(root->right);
        if (l - r > 1 || l - r < - 1) // 不满足相差1时记录
            ans = false;
        return max(l, r) + 1;
    }
};