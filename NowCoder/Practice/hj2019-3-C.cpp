#include<bits/stdc++.h>
using namespace std;

int n;


int main(){
	scanf("%d",&n);
	int cnt=0,a,t=n;

	while(--n){
		scanf("%d",&a);
		if(a>++cnt){
			printf("%d",cnt);
			break;
		}
	}
	
	if(n==0){
		printf("%d",t);
	}

	return 0;
}
