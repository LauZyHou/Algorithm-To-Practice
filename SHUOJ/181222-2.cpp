#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
int main() {
	cin>>n;
	if(n>2) {
		ll a=1;
		ll b=2;
		ll t=0;
		while(n>2) {
			t=b%10000000007L;
			b=(b+a)%10000000007L;
			a=t;
			n--;
		}
		cout<<(2*b+a-2)%10000000007L;
	} else {
		if(n==2)
			cout<<3;
		else if(n==1)
			cout<<1;
		else
			cout<<0;
	}
//	cout<<"\n"<<(1&7);
	return 0;
}
