#include<bits/stdc++.h>
using namespace std;
int a[10]={1};
int b[105];
int main(){
	int maxi=-1;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",b+i);
		if(b[i]>maxi)
			maxi=b[i];
	}
	for(int i=1;i<maxi;i++){
		a[i]=a[i-1]*(i+1);
	}
	long long ans = 0;
	for(int i=0;i<n;i++){
		ans += a[b[i]-1];
	}
	printf("%lld",ans);
	return 0;
}
