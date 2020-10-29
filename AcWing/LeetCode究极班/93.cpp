class Solution {
public:
    vector<string> ans;

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return ans;
    }

    void dfs(string& s, int u, int k, string path) {
        // 搜到结果
        if (u == s.size()) {
            if (k == 4) {
                // 去掉末尾的'.'
                path.pop_back();
                ans.emplace_back(path);
            }
            return ;
        }
        // 剪枝，如果已经搜完了四个数，但是s没用完就不搜了
        if (k == 4)
            return ;
        // 搜索从u开始的每个数，最多搜三位
        for (int i = u, t = 0; i < min(u + 3, int(s.size())); i ++) {
            if (i > u && s[u] == '0') // 前导0
                break;
            t = t * 10 + s[i] - '0'; // 当前分割出来的数
            if (t <= 255)
                dfs(s, i + 1, k + 1, path + to_string(t) + '.');
            else // 已经大于255了，不用再往后搜了
                break;
        }
    }
};