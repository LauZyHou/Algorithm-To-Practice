const int MOD = 1e9 + 7;

class Solution {
public:
    int findPaths(int n, int m, int N, int x, int y) {
        if (!N) return 0;
        vector<vector<vector<int>>> f(n, vector<vector<int>>(m, vector<int>(N + 1)));
        // 边界
        for (int j = 0; j < m; j ++ ) {
            f[0][j][1] ++ ;
            f[n - 1][j][1] ++ ;
        }
        for (int i = 0; i < n; i ++ ) {
            f[i][0][1] ++ ;
            f[i][m - 1][1] ++ ;
        }
        // 方向
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        // 先枚举路径长度k
        for (int k = 1; k <= N; k ++ )
            for (int i = 0; i < n; i ++ )
                for (int j = 0; j < m; j ++ )
                    for (int u = 0; u < 4; u ++ ) { // 四个方向
                        int a = i + dx[u], b = j + dy[u];
                        if (a >= 0 && a < n && b >= 0 && b < m)
                            (f[i][j][k] += f[a][b][k - 1]) %= MOD; // 注意这里的写法技巧
                    }
        // 计算答案
        int res = 0;
        for (int k = 1; k <= N; k ++ )
            (res += f[x][y][k]) %= MOD; // 注意这里的写法技巧
        return res;
    }
};