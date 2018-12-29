#include<bits/stdc++.h> 
using namespace std;
typedef unsigned long long ull;
#define F 61
int main() {

	ull a[F];
	int i,j,r;
	a[0]=2;
	for(i=1; i<F; i++) {
		a[i]=2*a[i-1];
	}

	ull b[65535];
	r=0;

	for(i=0; i<F; i++)
		for(j=i; j<F; j++)
			b[r++]=a[i]+a[j];


	int t;
	scanf("%d",&t);


	while(t--) {
		ull n;
		scanf("%lld",&n);

		for(i=0; i<r; i++) {
//			cout<<b[i]<<" ";
			if(b[i]==n) {
				printf("YES\n");
				goto BYE;
			}
		}
		printf("NO\n");

BYE:
		;
	}
	return 0;
}

