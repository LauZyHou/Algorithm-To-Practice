class Solution {
public:
    int massage(vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return 0;
        if(len==1)
            return nums[0];
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];        
        for(int i=2;i<len;i++) {
            dp[i] = dp[i-1] > nums[i] + dp[i-2] ? dp[i-1] : nums[i] + dp[i-2];
        }
        return dp[len-1];
    }
};