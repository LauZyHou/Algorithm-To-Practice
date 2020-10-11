class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        int n = houses.size();
        
        // 计算rec数组，rec[i][j]表示[i..j]范围内放一个邮筒距离和
        int rec[n][n];
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                rec[i][j] = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                int zws = i + j >> 1; // 中位数
                for (int r = i; r <= j; r ++)
                    rec[i][j] += abs(houses[r] - houses[zws]);
            }
        }

        // dp[i][j]表示[0..i]这些房子，j个邮箱，最好结果
        // dp[i][j] = min(dp[r][j-1] + rec[r+1][i]) 即 第j个邮箱负责[r+1..i]的部分
        // 所求即是dp[n-1][k]
        int dp[n][k+1];
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < k + 1; j ++)
                dp[i][j] = 2e9;
        for (int i = 0; i < n; i ++)
            dp[i][1] = rec[0][i];
        // 计算dp数组
        for (int i = 0; i < n; i ++) {
            for (int j = 2; j <= min(k, i + 1); j ++) {
                if (i == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                for (int r = j - 2; r < i; r ++)
                    dp[i][j] = min(dp[i][j], dp[r][j-1] + rec[r+1][i]);
            }
        }
        return dp[n-1][k];
    }
};