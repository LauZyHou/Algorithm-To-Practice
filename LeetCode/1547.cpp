class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // m个切割点，前补0后补n
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        // DP数组，dp[l][r]
        vector<vector<int> > dp(m + 2, vector<int>(m + 2, 0));
        // 因为计算dp时要保证小的都计算过了，所以这里遍历顺序是cuts的区间长度k递增
        // k<=1时不用切，所以从2开始
        for (int k = 2; k <= m + 1; k ++) {
            // 区间是[l-1, r+1]，所以l-1+k == r+1
            for (int l = 1; l <= m; l ++) {
                // 区间长度k固定时，r位置计算出来
                int r = l - 1 + k - 1;
                if (r > m)
                    break;
                // 遍历每个切割位置c
                dp[l][r] = INT_MAX;
                for (int c = l; c <= r; c ++) {
                    dp[l][r] = min(dp[l][r], dp[l][c - 1] + dp[c + 1][r]);
                }
                dp[l][r] += cuts[r + 1] - cuts[l - 1];
            }
        }
        return dp[1][m];
    }
};