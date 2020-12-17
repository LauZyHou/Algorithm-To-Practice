class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int INF = 1e8;
        int n = prices.size(); // 天数
        vector<vector<int>> f(n, vector<int>(3, -INF)); // 状态
        // 第一天买入的情况
        f[0][1] = -prices[0];
        // 第一天不买入的情况
        f[0][0] = 0;
        // 从第一天开始枚举
        for (int i = 1; i < n; i ++ ) {
            // 冷冻期状态
            f[i][0] = max(f[i - 1][0], f[i - 1][2]);
            // 已买入状态
            f[i][1] = max(f[i - 1][0] - prices[i], f[i - 1][1]);
            // 卖出状态
            f[i][2] = f[i - 1][1] + prices[i];
        }
        return max(f[n - 1][0], max(f[n - 1][1], f[n - 1][2]));
    }
};