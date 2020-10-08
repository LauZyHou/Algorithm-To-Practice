class Solution {
public:
    int minNumberOperations(vector<int>& v) {
        int n = v.size();
        if (!n) return 0;

        // dp[i]表示[0..i]子问题的操作次数
        vector<int> dp(n, 0);
        dp[0] = v[0];
        for (int i = 1; i < n; i ++) {
            // v[i]不超过v[i-1]时，i-1位置拿出v[i]次操作带上i位置
            if (v[i] <= v[i - 1]) {
                dp[i] = dp[i - 1];
            }
            // v[i]超过v[i-1]时，i-1位置拿出v[i-1]次操作带上i位置
            // i位置剩下的v[i]-v[i-1]次操作只能自己做
            else {
                dp[i] = dp[i - 1] + v[i] - v[i-1];
            }
        }

        return dp[n - 1];
    }
};