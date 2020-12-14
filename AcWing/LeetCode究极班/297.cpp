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
    string path;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs_s(root);
        return path;
    }

    void dfs_s(TreeNode* root) {
        if (!root) path += "#,";
        else {
            // 先去遍历根结点
            path += to_string(root->val) + ',';
            // 遍历左右子树
            dfs_s(root->left);
            dfs_s(root->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        // 从0这个位置开始遍历，这里u要传引用，因为在计算的过程中u是一直往前走的，递归到的位置对这一层来说还是有用
        return dfs_ds(data, u);
    }

    TreeNode* dfs_ds(string& data, int& u) {
        // 如果当前位置是井号就返回空
        if (data[u] == '#') {
            u += 2;
            return nullptr;
        }
        // 如果当前子树不是空
        else {
            // 先求一下这棵子树的根点
            int k = u;
            while (data[u] != ',') u ++ ;
            TreeNode* root = new TreeNode(stoi(data.substr(k, u - k)));
            // 求完根结点的值要把u往后移动一位跳过逗号
            u ++ ;
            // 计算左子树
            root->left = dfs_ds(data, u);
            // 左子树计算完退栈到这一层的时候，u的位置就已经摆好了
            // 计算右子树
            root->right = dfs_ds(data, u);
            // 最后返回这个子树
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));