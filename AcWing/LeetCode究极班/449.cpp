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
       string res;
       dfs_s(root, res);
       return res;
    }

    void dfs_s(TreeNode* root, string& s) {
        if (!root) return ;
        s += to_string(root->val) + ' ';
        dfs_s(root->left, s), dfs_s(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        vector<int> data;
        stringstream ssin(s);
        int x, u = 0; // u表示子树的开始位置
        while (ssin >> x) data.emplace_back(x);
        return dfs_ds(data, u, INT_MIN, INT_MAX); // 最开始合法的区间是在负无穷到正无穷
    }

    TreeNode* dfs_ds(vector<int>& data, int& u, int minv, int maxv) {
        if (u == data.size() || data[u] < minv || data[u] > maxv) return nullptr;
        auto root = new TreeNode(data[u ++ ]);
        root->left = dfs_ds(data, u, minv, root->val);
        root->right = dfs_ds(data, u, root->val, maxv);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;