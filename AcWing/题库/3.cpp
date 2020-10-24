#include<bits/stdc++.h>
using namespace std;

#define N 10010

int v[N],w[N];
int n,V;
int dp[N][N];


int main(){
	cin>>n>>V;
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=V;j++){
			dp[i][j]=dp[i-1][j];
			int k=j/v[i];
			for(int r=0;r<=k;r++)
				dp[i][j]=max(dp[i][j],dp[i-1][j-r*v[i]]+r*w[i]);
		}
	cout<<dp[n][V];
    return 0;
}
