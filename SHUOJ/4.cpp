#include<bits/stdc++.h>
using namespace std;

int a[105][105];
bool b[105][105];
int x,y;

void dfs(int i,int j){
	b[i][j]=true;
	if(i>0 && a[i-1][j]=='@' && !b[i-1][j]) dfs(i-1,j);
	if(j>0 && a[i][j-1]=='@' && !b[i][j-1]) dfs(i,j-1);
	if(i<x-1 && a[i+1][j]=='@' && !b[i+1][j]) dfs(i+1,j);
	if(j<y-1 && a[i][j+1]=='@' && !b[i][j+1]) dfs(i,j+1);

	if(i>0 && j>0 && a[i-1][j-1]=='@' && !b[i-1][j-1]) dfs(i-1,j-1);
	if(i>0 && j<y-1 && a[i-1][j+1]=='@' && !b[i-1][j+1]) dfs(i-1,j+1);
	if(i<x-1 && j>0 && a[i+1][j-1]=='@' && !b[i+1][j-1]) dfs(i+1,j-1);
	if(i<x-1 && j<y-1 && a[i+1][j+1]=='@' && !b[i+1][j+1]) dfs(i+1,j+1);
}

int main(int argc, char const *argv[])
{
	while(scanf("%d%d",&x,&y)!=EOF){
		if(x==0 && y==0)
			break;
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++) {
				scanf(" %c",&a[i][j]);
				b[i][j]=false;
			}
		int ans = 0;
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++){
				if(a[i][j]=='@' && !b[i][j]){
					ans++;
					dfs(i,j);
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}