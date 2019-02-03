#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	ll x;
	int a[110],b[110];
	scanf("%d%lld",&n,&x);
	
	for(int i=0;i<n;i++){
		scanf("%d%d",a+i,b+i);
	}
	
//	cout<<x<<endl;
	
	for(int i=n-1;i>=0;i--){
		if(a[i]==3){
			x/=b[i];
		}else if(a[i]==2){
			x+=b[i];
		}else if(a[i]==1){
			x-=b[i];
		}else if(a[i]==4){
			x*=b[i];
		}
	}
	
	printf("%lld",x);
	return 0;
}
