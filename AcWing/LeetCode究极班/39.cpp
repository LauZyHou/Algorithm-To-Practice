class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& cs, int t) {
        dfs(cs, 0, t);
        return ans;
    }

    void dfs(vector<int>& cs, int u, int t) {
        if (t == 0) {
            ans.emplace_back(path);
            return;
        }
        if (u == cs.size())
            return;
        for (int k = 0; k * cs[u] <= t; k ++) {
            dfs(cs, u + 1, t - k * cs[u]);
            path.emplace_back(cs[u]); // 选k个就要放k个到path里，这里每次k加1就放一个就行了
        }
        // 恢复现场
        for (int k = 0; k * cs[u] <= t; k ++)
            path.pop_back();
    }
};