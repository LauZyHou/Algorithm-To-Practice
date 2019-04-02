class Solution {
public:
    int maxProfit(vector<int>& p) {
		//DP: dp[i] = max(dp[i-1],p[i]-minp)
        //记录目前为止最小的数字
		int minp = INT_MAX;
		//记录目前为止最大的收益
		int dp = 0;//没有交易完成时就是最大的收益为0,不会亏
		for(auto u:p){
			minp = min(minp,u);
			dp = max(dp,u-minp);
		}
		return dp;
    }
};