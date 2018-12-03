#include<bits/stdc++.h>
using namespace std;
char c[33];
int a[4],sum;
int n;
int main() {
	scanf("%d",&n);
	getchar();
	while(n--) {
		gets(c);
		for(int i=0; i<4; i++) {
			sum=0;
			for(int j=0; j<8; j++) {
				sum*=2;
				if(c[i*8+j]=='1') {
					sum+=1;
				}
			}
			a[i]=sum;
		}
		for(int i=0; i<3; i++)
			printf("%d.",a[i]);
		printf("%d\n",a[3]);
	}
	return 0;
}
