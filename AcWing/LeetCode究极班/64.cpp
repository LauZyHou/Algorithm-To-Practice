class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        // f[i][j]表示从0,0走到i,j这里所有的路径中和最小的是多少
        int n = g.size();
        if (!n) return 0;
        int m = g[0].size();
        if (!m) return 0;

        // 要求最小值，这里可以初始化为正无穷
        vector<vector<int>> f(n, vector<int>(m, INT_MAX));

        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++) {
                // 起点
                if (!i && !j) f[i][j] = g[i][j];
                else {
                    // 如果i>0，则可以从上面下来
                    if (i) f[i][j] = min(f[i][j], f[i - 1][j] + g[i][j]);
                    // 如果j>0，则可以从左边过来
                    if (j) f[i][j] = min(f[i][j], f[i][j - 1] + g[i][j]);
                }
            }
        
        return f[n - 1][m - 1];
    }
};