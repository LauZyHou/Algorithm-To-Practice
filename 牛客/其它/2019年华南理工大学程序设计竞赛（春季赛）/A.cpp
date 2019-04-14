#include<bits/stdc++.h>
using namespace std;

char a[10];

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",a);
		if(a[0]=='S')
			puts("Rock");
		else if(a[0]=='R')
			puts("Paper");
		else
			puts("Scissors");
	}
	return 0;
}
