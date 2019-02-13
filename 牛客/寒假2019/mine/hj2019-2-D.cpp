#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		if(a<60)
			cnt+=400;
	}
	printf("%d",cnt);
	return 0;
}
