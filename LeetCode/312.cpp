class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
		nums.push_back(1);//1,...,1
		int n = nums.size();
		
		vector<vector<int>> dp(n,vector<int>(n));
		//所求是nums[0][n-1]
		//dp[i][j]中j=i+len,表示从i+1到j-1之间能获得的金币最大值
		//dp[i][j] = 存在k使得 dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j] 最大
		for(int len=2;len<n;len++) {
			for(int i=0;i+len<n;i++) {
				int j = i+len;
				for(int k=i+1;k<j;k++)
					dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
			}
		}
		return dp[0][n-1];
    }
};