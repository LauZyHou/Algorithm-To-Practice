class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size();
        if (!m) return 0;
        int n = g[0].size();
        if (!n) return 0;
        vector<vector<int>> f(m, vector<int>(n));
        f[0][0] = g[0][0] == 1 ? 0 : 1;
        for (int i = 1; i < m; i ++)
            f[i][0] = g[i][0] == 1 ? 0 : f[i - 1][0];
        for (int j = 1; j < n; j ++)
            f[0][j] = g[0][j] == 1 ? 0 : f[0][j - 1];  
        for (int i = 1; i < m; i ++)
            for (int j = 1; j < n; j ++)
                f[i][j] = g[i][j] == 1 ? 0 : (f[i - 1][j] + f[i][j - 1]);
        return f[m - 1][n - 1];
    }
};