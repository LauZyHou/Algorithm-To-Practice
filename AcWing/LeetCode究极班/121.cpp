class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        if (prices.empty()) return res;
        for (int i = 1, minp = prices[0]; i < prices.size(); i ++ ) {
            res = max(res, prices[i] - minp);
            minp = min(minp, prices[i]);
        }
        return res;
    }
};