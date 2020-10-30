class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (!n) return 0;
        // 0..i里买卖一次的代价
        vector<int> f(n);
        for (int i = 1, minp = prices[0]; i < n; i ++ ) {
            f[i] = max(f[i - 1], prices[i] - minp); // 根据是否在i位置卖出分
            minp = min(minp, prices[i]);
        }

        int res = 0;
        // 从后往前枚举第二段的买入时机
        for (int i = n - 1, maxp = prices[n - 1]; i >= 1; i -- ) {
            res = max(res, f[i] + maxp - prices[i]);
            maxp = max(maxp, prices[i]);
        }

        return res;
    }
};