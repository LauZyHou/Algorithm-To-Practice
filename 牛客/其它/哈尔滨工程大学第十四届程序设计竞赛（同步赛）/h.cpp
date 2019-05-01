#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a[100005];
ll b[100005];

ll n;
int K;
int T;
ll ans;

int main(){
	scanf("%d",&T);
	while(T--){
		ans = 0;
		scanf("%lld%d",&n,&K);
		for(int i=1;i<K;i++){
			scanf("%lld",&a[i]);
			b[i] = 0;
		}
		b[1] = n;
		b[K] = 0;
		while(b[K]<n){
			for(int i=K-1;i>=1;i--){
				ll r = min(b[i],a[i]);
				b[i+1] += r;
				b[i] -= r;
			}
			ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
