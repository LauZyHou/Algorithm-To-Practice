class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& cs, int t) {
        // 先排序，这样一样的数就连在一起了
        sort(cs.begin(), cs.end());
        dfs(cs, 0, t);
        return ans;
    }

    void dfs(vector<int>& cs, int u, int t) {
        if (t == 0) {
            ans.emplace_back(path);
            return ;
        }
        if (u == cs.size())
            return ;
        // 找这个数有几个
        int k = u + 1;
        while (k < cs.size() && cs[k] == cs[u])
            k ++;
        int cnt = k - u;

        // 对于0~cnt的所有出现次数向下dfs
        for (int i = 0; cs[u] * i <= t && i <= cnt; i ++) {
            dfs(cs, k, t - cs[u] * i); // 下一个数的位置在k
            path.emplace_back(cs[u]);
        }

        // 恢复现场
        for (int i = 0; cs[u] * i <= t && i <= cnt; i ++)
            path.pop_back();
    }
};