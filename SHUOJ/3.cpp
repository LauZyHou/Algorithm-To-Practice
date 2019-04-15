#include<bits/stdc++.h>
using namespace std;

int dp[2015]={0,0,1,3};//1~2013 is enough

int main(int argc, char const *argv[])
{
	int t;
	int n;
	int now = 3;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<=1){
			printf("Mission Complete!\n");
			continue;
		}
		if(n<=now){
			if(dp[n]==1)//1 special
				printf("Needs at least 1 ATP!\n");
			else
				printf("Needs at least %d ATPs!\n", dp[n]);
			continue;
		}
		for(int i=now+1;i<=n;i++){
			//cal dp[i]
			int r = i/2;
			dp[i] = i-1 + dp[i-1];//1*(i-1) + dp[1] + dp[i-1]
			for(int j=2;j<=r;j++){
				int nowmin = j*(i-j) + dp[j] + dp[i-j];
				if(nowmin<dp[i])
					dp[i] = nowmin;
			}
		}
		now = n;
		printf("Needs at least %d ATPs!\n", dp[n]);
	}
	return 0;
}