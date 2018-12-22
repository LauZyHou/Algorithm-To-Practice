#include<bits/stdc++.h>
using namespace std;
int a[5]= {0,-2,2,-2,2};
int b[5]= {0,2,-2,-2,2};
int n,m,x,y,i,j;
int mp[5][10];
long long tripnum[5][10];
int main() {
	memset(tripnum,0,sizeof(tripnum));
	scanf("%d%d%d%d",&x,&y,&n,&m);
	for(i=0; i<5; i++)
		for(j=0; j<10; j++)
			mp[i][j]=1;
	for(i=0; i<=4; i++)
		if(x+a[i]<5 && x+a[i]>=0 && y+b[i]<5 && y+b[i]>=0)
			mp[x+a[i]][y+b[i]]=0;
	for(j=0; j<10; j++)
		if(mp[0][j]==1)
			tripnum[0][j]=1;
		else
			break;
	for(i=0; i<5; i++)
		if(mp[i][0]==1)
			tripnum[i][0]=1;
		else
			break;
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			if(mp[i][j]==1)
				tripnum[i][j]=tripnum[i-1][j]*mp[i-1][j]+tripnum[i][j-1]*mp[i][j-1];
	printf("%lld",tripnum[n][m]);
	return 0;
}
