#include<iostream>
using namespace std;

#define ll long long

int main(){
	ll x,y,a;
	while(~scanf("%I64d%I64d%I64d",&x,&y,&a)){
		ll n=x/a+(x%a?1:0);
		ll m=y/a+(y%a?1:0);
		printf("%I64d\n",n*m);
	}
	return 0;
}
