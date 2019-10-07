/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int maxSum = INT_MIN;
        int lev = 0;
        int maxLev = 0;
        while (q.empty() == false)
        {
            lev += 1;
            int len = q.size();
            int sum = 0;
            for (int i = 0; i < len; i++)
            {
                TreeNode *t = q.front();
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                sum += t->val;
            }
            if (sum > maxSum)
            {
                maxSum = sum;
                maxLev = lev;
            }
        }
        return maxLev;
    }
};