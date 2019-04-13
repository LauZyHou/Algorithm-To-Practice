#include<bits/stdc++.h>
using namespace std;

int a[5000010];
int b[5000010];
int s[5000010];

int main(){
	int n;
	scanf("%d",&n);
	if(n<=1){
		printf("0");
		return 0;
	}
	scanf("%d",s);
	a[0]=s[0];
	for(int i=1;i<n;i++){
		scanf("%d",s+i);
		a[i]=s[i] | a[i-1];
	}
	b[n-1]=s[n-1];
	for(int i=n-2;i>=0;i--)
		b[i]=s[i] | b[i+1];
	int ans=max(b[1],a[n-2]);
	for(int i=1;i<=n-2;i++)
		if((a[i-1]|b[i+1])>ans)
			ans=(a[i-1]|b[i+1]);
	printf("%d",ans);
	return 0;
}
