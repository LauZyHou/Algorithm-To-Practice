#include<bits/stdc++.h>
using namespace std;

#define N 30002

//并查集森林
int a[N];
int n,m;
int t;
int p,q;

//find root
int find(int x){
	int r = x;
	while(a[r]!=r){
		r = a[r];
	}
	int t = x;
	while(t!=r){//dump
		int k  = a[t];
		a[t] = r;
		t = k;
	}
	return r;
}

//join two points
void join(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx==fy)
		return ;
	a[fy] = fx;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			a[i] = i;//初始化每个节点自己一棵树
		for(int i=0;i<m;i++){
			scanf("%d%d",&p,&q);
			join(p,q);
		}
		int ans = 0;
		for(int i=1;i<=n;i++){
			//只记录根节点,也就得到了有多少个
			if(a[i]==i)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}