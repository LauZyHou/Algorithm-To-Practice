class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int len = A.size();
		vector<int> dp(len);
		dp[0] = A[0];
		for(int i=1;i<len;i++) {
			int nowmax = A[i];
			int nowmaxsum = dp[i-1] + A[i];
			for(int j=1;j<K;j++) {
				if(i-j<0)
					break;
				if(nowmax<A[i-j])
					nowmax = A[i-j];
				nowmaxsum = max(nowmaxsum,nowmax*(j+1)+(i-j-1<0?0:dp[i-j-1]));
			}
			dp[i] = nowmaxsum;
		}
		return dp[len-1];
    }
};