/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef pair<double, double> PDD;

class Solution {
private:
    // 子树所有节点执行时间和（全串行），子树最大并行时间
    PDD dfs(TreeNode* root) {
        PDD ans({0.0, 0.0}); 
        if (root == nullptr) {
            return ans;
        }
        PDD l = dfs(root->left);
        PDD r = dfs(root->right);
        if (l.first < r.first) {
            swap(l, r);
        }
        ans.first = l.first + r.first + root->val;
        // 判断left进行足够的并行之后，r是不是就能和l并行走完了
        if (l.first - 2 * l.second <= r.first) {
            ans.second = (l.first + r.first) / 2;
        }
        else {
            ans.second = l.second + r.first;
        }
        return ans;
    }
public:
    double minimalExecTime(TreeNode* root) {
        PDD ans = dfs(root);
        return ans.first - ans.second;
    }
};