typedef long long ll;

class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int numOfArrays(int n, int m, int k) {
        if (n == 1)
            return 0;
        // dp[i][j][r]表示数组长度i，最大值是j，查找了r次
        // 则所求即为dp[n][j][k] for j in [1..m]
        ll dp[n + 1][m + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        // 边界条件，dp[0][j][r] = dp[i][j][0] = dp[i][0][j] = 0，dp[1][j][1]=1，dp[i][j][>j || >i]=0
        // 其中只有dp[1][j][1]是非0的需要手动赋值一下
        for (int j = 1; j <= m; j ++)
            dp[1][j][1] = 1;
        // 当最后一个数(i位置)是最大值j时，前面一个位置可以是任何不超过j的数当最大值，且次数是r-1
        // dp[i][j][r] = sum(dp[i-1][_j][r-1]) for every _j < j
        // 当最大值j在[0..i-1]位置中时，最后一个数可以是任何<j的数，前一位置次数是r不变
        // dp[i][j][r] = dp[i-1][j][r] * j
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                int bound = min(min(j, i), k);
                for (int r = 1; r <= bound; r ++) {
                    // dp[1][j][1]不用算
                    if (i == 1 && r == 1)
                        continue;
                    // 最后一个数是最大值j的情况
                    for (int _j = 0; _j < j; _j ++)
                        dp[i][j][r] = (dp[i][j][r] + dp[i - 1][_j][r - 1]) % mod;
                    // 最后一个数不是最大值j的情况
                    dp[i][j][r] = (dp[i][j][r] + j * dp[i - 1][j][r]) % mod;
                }
            }
        }
        // 计算所求
        ll ans = 0;
        for (int j = 1; j <= m; j ++)
            ans = (ans + dp[n][j][k]) % mod;
        return ans;
    }
};