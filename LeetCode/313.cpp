class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int plen = primes.size();
		vector<int> dp(n,INT_MAX);
		vector<int> idx(plen,0);
		dp[0] = 1;
		for(int i=1;i<n;i++) {
			/*
			int changeJ;
			for(int j=0;j<plen;j++) {
				if(idx[j]<n && dp[i]>primes[j]*dp[idx[j]]) {
					changeJ =  j;
					dp[i] = primes[j]*dp[idx[j]];
				}
			}
			idx[changeJ]++;//使用了的那个质数,下次就要乘下一个小的dp了,而不能再乘这个
			*/

			//因为可能多种乘方式得到同一个超级丑数
			//比如2*2*7和7*2*2
			//所以要判断每一个dp[i] == primes[j]*dp[idx[j]]
			//要将他们的j++
			for(int j=0;j<plen;j++) {
				if(idx[j]<n && dp[i]>primes[j]*dp[idx[j]])//这里idx[j]<n防止溢出
					dp[i] = primes[j]*dp[idx[j]];
			}
			for(int j=0;j<plen;j++) {
				if(idx[j]<n && dp[i]==primes[j]*dp[idx[j]])
					idx[j]++;
			}
		}
		return dp[n-1];
    }
};