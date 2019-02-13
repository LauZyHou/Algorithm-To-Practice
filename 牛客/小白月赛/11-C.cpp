#include<bits/stdc++.h>
using namespace std;

int n,m,T;
int a[100010];
int b[100010];
int k;

int main() {
	scanf("%d%d%d",&n,&m,&T);
	for(k=1; k<=T; k++) {
		scanf("%d%d",a+k,b+k);
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<m; j++) {
			//find
			for(k=T; k>=1; k--) {
				if(a[k]==1 && b[k]==i || a[k]==2 && b[k]==j) {
					printf("%d ",k);
					break;
				}
			}
			if(k==0)
				printf("0 ");
		}
		//j==m
		for(k=T; k>=1; k--) {
			if(a[k]==1 && b[k]==i || a[k]==2 && b[k]==m) {
				printf("%d",k);
				break;
			}
		}
		if(k==0)
			printf("0");
		printf("\n");
	}
	return 0;
}
