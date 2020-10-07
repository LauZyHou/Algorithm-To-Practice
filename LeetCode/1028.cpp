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
    TreeNode* recoverFromPreorder(string s) {
        stack<TreeNode*> path;
        int len = s.size();
        int i = 0;
        while (i < len) {
            int lev = 0;
            while (s[i] == '-')
                lev ++, i ++;
            int val = 0;
            while (i < len && isdigit(s[i]))
                val = val * 10 + s[i] - '0', i ++;
            
            TreeNode* node = new TreeNode(val);
            node -> left = node -> right = nullptr;
            if (lev == path.size()) {
                if (!path.empty()) // 插入第一个节点时这里lev = 0，且path为空
                    path.top() -> left = node;
            }
            else {
                while (lev < path.size())
                    path.pop();
                path.top() -> right = node;
            }
            
            path.push(node);
        }
        
        while (path.size() > 1)
            path.pop();
        return path.top();
    }
};