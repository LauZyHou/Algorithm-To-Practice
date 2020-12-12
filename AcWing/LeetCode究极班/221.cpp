class Solution {
public:
    int maximalSquare(vector<vector<char>>& g) {
        int n = g.size();
        if (!n) return 0;
        int m = g[0].size();
        // 用f[i][j]表示以i,j结尾的最大全1正方形的变长
        auto f = vector<vector<int>>(n + 1, vector<int>(m + 1));
        int res = 0;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ ) {
                if (g[i - 1][j - 1] == '0')
                    f[i][j] = 0;
                else
                    f[i][j] = min(min(f[i - 1][j - 1], f[i][j - 1]), f[i - 1][j]) + 1;
                res = max(res, f[i][j]);
            }
        return res * res;
    }
};