class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> f(k + 1, vector<int>(n));
        f[0][0] = 1;
        for (int i = 0; i < k; i ++ )
            for (auto& p: relation)
                f[i + 1][p[1]] += f[i][p[0]];
        return f[k][n - 1];
    }
};