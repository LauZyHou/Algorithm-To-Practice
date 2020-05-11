class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int len = v.size();
        if(!len)
            return 0;
        int dp = v[0];
        int ans = dp;
        for(int i=1;i<len;i++) {
            if(dp > 0) {
                dp = dp + v[i];
            }
            else {
                dp = v[i];
            }
            ans = max(ans, dp);
        }
        return ans;
    }
};