#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,d,x;
ll cnt=1;
ll now=n,sum=n;
ll i,j,r;

//false:<,true:>=
bool check(ll k) {
	return (2*n+(k-1)*d)*k/2>=m;
}

int main() {
	scanf("%lld%lld%lld%lld",&n,&m,&d,&x);
	//第一天特判 
	if(n>=m){
		printf("%d",1);
		goto bye;
	}
	//二分
	i=1;
	j=x;
	while(i<j) {
		r=(i+j)/2;
		if(check(r)) {
			j=r;
		} else {
			i=r;
		}
		if(i==j-1)
			break;
	}
	printf("%lld",j);
bye:
	return 0;
}
