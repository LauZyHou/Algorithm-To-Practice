class Solution {
public:
    int maxProfit(vector<int> &v) {
        int len = v.size();
        int dp = 0;
        int ans = 0;
        for(int i=1;i<len;i++) {
            if(dp<0)
                dp = v[i] - v[i-1];
            else
                dp = dp + v[i] - v[i-1];
            if(dp > ans)
                ans = dp;
        }
        return ans;
    }
};