class Solution {
public:
    int minDistance(string w1, string w2) {
        int n1 = w1.size();
        int n2 = w2.size();
        
        int dp[n1 + 1][n2 + 1];

        for (int i = 0; i <= n1; i ++) {
            for (int j = 0; j <= n2; j ++) {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else {
                    dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
                    if (w1[i - 1] == w2[j -1])
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    else
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }

        return dp[n1][n2];
    }
};