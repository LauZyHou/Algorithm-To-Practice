#include<bits/stdc++.h>
using namespace std;

long long mp[1010][1010];

int main() {
	int n,m;
	long long k;
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			scanf("%lld",&mp[i][j]);
		}
	}
	int i=0,j=m-1;
	while(i<n && j>=0) {
		if(mp[i][j]==k) {
			printf("Yes\n");
			return 0;
		} else if(mp[i][j]<k)
			i++;
		else
			j--;
	}
	printf("No\n");
	return 0;
}