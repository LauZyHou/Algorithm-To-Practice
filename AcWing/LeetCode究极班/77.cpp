class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }

    void dfs(int n, int k, int start) {
        if (!k) {
            ans.emplace_back(path);
            return ;
        }

        for (int i = start; i <= n; i ++) {
            // 优化，从start开始选最多能选n-start+1个数，如果都不足k个，就没法选
            if (n - start + 1 < k)
                break;
            // 选这个数，然后继续往下
            path.emplace_back(i);
            dfs(n, k - 1, i + 1);
            path.pop_back(); // 恢复现场
        }
    }
};