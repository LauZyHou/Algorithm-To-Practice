#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 10000019
//A

//quick pow with mode
ll qp(ll a, ll b, ll mode) {
	ll sum = 1;
	while (b) {
		if (b & 1) {
			sum = (sum * a) % mode;
			b--;
		}
		b /= 2;
		a = a * a % mode;
	}
	return sum;
}

ll a[100002];
int n;
ll sum=0;

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",a+i);
		sum+=qp(a[i],i+1,M);
	}
	printf("%lld",sum%M);
	return 0;
}
