class Solution {
public:
    int getMoneyAmount(int n) {
        // 区间dp
        vector<vector<int>> f(n + 2, vector<int>(n + 2));
        // 枚举区间长度，如果len=1的话直接就能猜对，所以代价是0
        for (int len = 2; len <= n; len ++ ) {
            // 枚举区间左端点
            for (int i = 1; i + len - 1 <= n; i ++ ) {
                // 区间右端点
                int j = i + len - 1;
                // 要计算的f[i][j]由于是最小值（最坏情况的最小值），所以这里初始化为正无穷
                f[i][j] = INT_MAX;
                // 枚举猜的数字k
                for (int k = i; k <= j; k ++ )
                    f[i][j] = min(f[i][j], max(f[i][k - 1], f[k + 1][j]) + k);
            }
        }
        // 答案就是从1到n这个区间里的最坏情况下的最小值
        return f[1][n];
    }
};