#include<iostream>
using namespace std;

#define N 110

int s[N],v[N],w[N];
int n,V;
int dp[N][N]={0};

int main()
{
	cin>>n>>V;
	for(int i=1;i<=n;i++)
		cin>>v[i]>>w[i]>>s[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=V;j++)
		{
			dp[i][j]=dp[i-1][j];
			int r=min(s[i],j/v[i]);
			for(int k=1;k<=r;k++)
				dp[i][j]=max(dp[i][j],dp[i-1][j-k*v[i]]+k*w[i]);
		}
	}
	cout<<dp[n][V];
	return 0;
}
