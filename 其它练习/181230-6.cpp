#include<bits/stdc++.h>
using namespace std;
//K

int t;
int a[3][4];
int tp,bt;//2 special
int cnt=0;

int main() {
	scanf("%d",&t);
	while(t--) {
		tp=bt=0;
		for(int i=0; i<4; i++) {
			scanf("%d",&a[0][i]);
			if(a[0][i]!=0)
				tp=a[0][i];
		}
		for(int i=0; i<4; i++) {
			scanf("%d",&a[1][i]);
		}
		for(int i=0; i<4; i++) {
			scanf("%d",&a[2][i]);
			if(a[2][i]!=0)
				bt=a[2][i];
		}
		if(tp==bt && a[1][0]==a[1][2] && a[1][1]==a[1][3])
			printf("Yes!\n");
		else
			printf("No!\n");
		cnt++;
		if(cnt%50==0)
			printf("\n");
	}
	return 0;
}

