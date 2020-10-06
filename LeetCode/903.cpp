class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int numPermsDISequence(string s) {
        int n = s.size();
        // dp[i][j]表示范围[0,i]的子问题，末尾数字p[j]=j的情况的答案
        vector<vector<int> > dp(n + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j_next = 0; j_next <= i; j_next ++) {
                if (s[i - 1] == 'D') { // 要减少
                    // <=j_pre的所有j_next都可以放末尾（可以让所有>=j_next的数都加1）
                    // 所以这里遍历的是所有满足j_next <= j_pre的j_pre
                    for (int j_pre = j_next; j_pre <= i - 1; j_pre ++) {
                        dp[i][j_next] = (dp[i][j_next] + dp[i - 1][j_pre]) % mod;
                    }
                }
                else { // 要增加
                    // >j_pre的所有j_next都可以放在末尾（可以让所有>=j_next的数都加1）
                    // 所以这里遍历的是所有满足j_next > j_pre的j_pre
                    for (int j_pre = 0; j_pre < j_next; j_pre ++) {
                        dp[i][j_next] = (dp[i][j_next] + dp[i - 1][j_pre]) % mod;
                    }
                }
            }
        }
        // 结果是所有可能的0~n之间的数字j的dp[n][j]的和
        int ans = 0;
        for (int j = 0; j <= n; j ++)
            ans = (ans +dp[n][j]) % mod;
        return ans;
    }
};