#include<iostream>
using namespace std;

#define N 10010

int v[N],w[N],dp[N];
int n,V;

int main(){
	cin>>n>>V;
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
	for(int i=1;i<=n;i++)
		for(int j=V;j;j--)
			if(j>=v[i])//只考虑装得下,装不下时dp[i][j]=dp[i-1][j]在一维里就是不变
				dp[j]=max(dp[j-v[i]]+w[i],dp[j]);
	cout<<dp[V];
	return 0;
}