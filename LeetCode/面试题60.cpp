class Solution {
public:
    vector<double> twoSum(int n) {
        if(!n)
            return vector<double>();
        // n..6n共5n+1个元素
        int anslen = 5*n+1;
        vector<double> ans(anslen);
        int **dp = new int*[n+1];
        for(int i=0;i<n+1;i++) {
            dp[i] = new int[6*n+1];
            for(int j=0;j<6*n+1;j++)
                dp[i][j] = 0;
        }

        for(int j=1;j<=6;j++)
            dp[1][j] = 1;
        
        for(int i=2;i<=n;i++) { // i个骰子
            for(int j=i;j<=6*i;j++) { // 点数为j
                for(int k=1;k<=6;k++) { // 当前投出数值k
                    if(j-k >= i-1) { // 前n-1个投出j-k的点数
                        dp[i][j] += dp[i-1][j-k];
                    }
                }
            }
        }
        double base = pow(1.0/6,n);
        for(int j=n;j<=6*n;j++) {
            ans[j-n] = dp[n][j] * base;
        }
        return ans;
    }
};