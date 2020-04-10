class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int len = v.size();
        int dp = 0;
        int ans = INT_MIN;
        for(int i=0;i<len;i++) {
            dp = dp>0? dp+v[i] : v[i];
            if(dp > ans)
                ans = dp;
        }
        return ans;
    }
};