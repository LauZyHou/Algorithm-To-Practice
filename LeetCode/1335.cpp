class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        // 由于每天至少要完成一个任务，所以n>=d
        if (n < d) return -1;
        // dp[i][j]表示[0..i]号任务在[0..j]天完成的最小费用
        vector<vector<int>> dp(n, vector<int>(d, INT_MAX / 3));
        // 初始化，j=0时，即只有一天，完成的费用就是[0..i]里最大的job[i]
        int val = INT_MIN;
        for (int i = 0; i < n; i ++)
            val = max(val, jobDifficulty[i]), dp[i][0] = val;
        // 遍历每个天数j = 1到d-1
        for (int j = 1; j < d; j ++) {
            // 遍历每个job数i = j到n-1
            for (int i = j; i < n; i ++) {
                // 现在要计算dp[i][j]
                // job数的切分点k，[0..k]给[0..j-1]天做，剩下的[k+1..i]给j天做
                // 这里k反着遍历就方便计算[k+1..i]的最大job
                val = INT_MIN;
                for (int k = i - 1; k >= j - 1; k --) {
                    val = max(val, jobDifficulty[k + 1]);
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + val);
                }
            }
        }
        return dp[n - 1][d - 1];
    }
};