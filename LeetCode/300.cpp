class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return 0;
        vector<int> dp(len, 1);
        dp[0] = 1;
        int ans = 1;
        for(int i=1;i<len;i++) {
            for(int j=0;j<i;j++) {
                if(nums[j]<nums[i] && dp[j]+1>dp[i])
                    dp[i] = dp[j] + 1;
            }
            if(dp[i]>ans)
                ans = dp[i];
        }
        return ans;
    }
};