#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define N 100000
int q,k;
int maxr = 0;

int main() {
	scanf("%d%d",&q,&k);
	if(!q)
		return 0;
	int val[N][2];//存q个l和r
	//读取q个l和r
	for(int i=0;i<q;i++) {
		scanf("%d%d",&val[i][0],&val[i][1]);
		maxr = max(maxr,val[i][1]);//记录r的最大值,这样dp只要计算到r就可以了
	}
	
	//[*]maxr还有这样一个作用,当k比maxr还大的时候,从l到r每个都只有一种情况,不需做dp也不需前缀和
	if(k>maxr) {
		for(int i=0;i<q;i++) {
			printf("%d\n",val[i][1]-val[i][0]+1);//r-l+1
		}
		return 0;
	}
	
	//dp[i][0]表示到位置i的方法数,且最后一步是走;dp[i][1]表示到位置i的方法数,且最后一步是跑
	int dp[N][2];
	dp[0][0] = dp[0][1] = 0;
	//从初始位置跑一次(k)也就到了k位置,在这之前都只能走不可能是跑到的
	for(int i=0;i<k;i++) {
		dp[i][0] = 1;
		dp[i][1] = 0;
	}
	//第k位置可能是一步跑到的,也可能是一步步走过来的
	dp[k][0] = 1;
	dp[k][1] = 1;
	//dp[i][0] = 上一步是走+上一步是跑 的方法数
	//dp[i][1] = 上一步是走 的方法数
	for(int i=k+1;i<=maxr;i++) {
		dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD;
		dp[i][1] = dp[i-k][0];
	}
	
	//最终要求的是(dp[i][0]+dp[i][1])使i从l到r求和,因为查询很多次,用前缀和
	//这里为节省空间,不妨都加到dp[i][0]上去
	for(int i=1;i<=maxr;i++) {
		dp[i][0] = (dp[i-1][0] + dp[i][0] + dp[i][1]) % MOD;
	}
	
	//对每个查询输出结果
	for(int i=0;i<q;i++) {
		//利用前缀和sum计算从item(l)加到item(r)的值,为sum(r) - sum(l-1)
		int v = dp[val[i][1]][0]-dp[val[i][0]-1][0];
		if(v>=0)
			printf("%d\n",v);
		else
			printf("%d\n",(v+MOD)%MOD);
	}
	return 0;
}
