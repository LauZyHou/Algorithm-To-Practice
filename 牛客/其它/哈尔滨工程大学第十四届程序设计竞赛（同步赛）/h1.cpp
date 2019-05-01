#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a[100005];

ll n;
int K;
int T;
ll ans;

ll mina;
int minidx;

int main(){
	scanf("%d",&T);
	while(T--){
		ans = 0;
		scanf("%lld%d",&n,&K);
		for(int i=1;i<K;i++){
			scanf("%lld",&a[i]);
		}
		mina = a[1];
		minidx = 1;
		for(int i=2;i<K;i++)
			if(a[i]<mina){
				mina = a[i];
				minidx = i;
			}
		ans = minidx-1 + max((ll)K-minidx, (n+mina-1)/mina);
		printf("%lld\n",ans);
	}
	return 0;
}
