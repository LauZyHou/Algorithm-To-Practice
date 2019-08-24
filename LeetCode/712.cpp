class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.size();
		int len2 = s2.size();
		int** dp = new int*[len1+1];
		for(int i=0;i<=len1;i++)
			dp[i] = new int[len2+1];
		//dp[i][j]表示s1从i开始到结尾,s2从j开始到结尾,这样所求的"minimumDeleteSu"
		//一个字符串为空时,所求即为另一个字符串所有加起来
		dp[len1][len2] = 0;
		for(int i=len1-1;i>=0;i--) {
			dp[i][len2] = dp[i+1][len2] + int(s1[i]);
		}
		for(int j=len2-1;j>=0;j--) {
			dp[len1][j] = dp[len1][j+1] + int(s2[j]);
		}
		for(int i=len1-1;i>=0;i--)
			for(int j=len2-1;j>=0;j--) {
				if(s1[i]==s2[j])
					dp[i][j] = dp[i+1][j+1];
				else
					//s1[i]和s2[j]至少要去掉一个
					dp[i][j] = min(dp[i+1][j]+int(s1[i]),dp[i][j+1]+int(s2[j]));
			}
		return dp[0][0];
    }
};