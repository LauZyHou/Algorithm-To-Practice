/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        if (root != nullptr)
            q.push(root);
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t == nullptr) {
                ans += ",";
            }
            else {
                ans += to_string(t->val) + ",";
                q.push(t -> left);
                q.push(t -> right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if (!n)
            return nullptr;
        bool pos = true; // 正负
        TreeNode* t = nullptr;
        queue<TreeNode*> q;
        for (char d : data) {
            if (isdigit(d)) {
                if (!t)
                    t = new TreeNode(0);
                t->val = t->val * 10 + d - '0';
            }
            else if (d == '-') {
                pos = false;
            }
            else {
                if (!pos)
                    t -> val = - t -> val;
                q.push(t);
                pos = true;
                t = nullptr;
            }
        }
        TreeNode* ans = q.front();
        q.pop();
        queue<TreeNode*> lev;
        lev.push(ans);
        while (!q.empty()) {
            int len = lev.size();
            for (int i = 0; i < len; i ++) {
                TreeNode* rt = lev.front();
                lev.pop();
                if (!rt)
                    continue;
                TreeNode* l = q.front();
                q.pop();
                TreeNode* r = q.front();
                q.pop();
                rt -> left = l, rt -> right = r;
                lev.push(l), lev.push(r);
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));