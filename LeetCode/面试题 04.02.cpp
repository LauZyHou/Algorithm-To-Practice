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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursive(nums, 0, nums.size());
    }

    TreeNode* recursive(vector<int>& nums, int a, int b) {
        if(a==b)
            return nullptr;
        int center = (a+b)>>1;
        TreeNode* t = new TreeNode(nums[center]);
        t->left = recursive(nums, a, center);
        t->right = recursive(nums, center+1, b);
        return t;
    }
};