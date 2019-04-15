#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(a<b){
		int t = a;
		a = b;
		b = t;
	}
	int c = a%b;
	if(!c) return b;
	else return gcd(b,c);
}

int main(int argc, char const *argv[])
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int ans = 1;
		for(int i=0;i<b;i++){
			int t=gcd(a,b);
			if(t==1)
				break;
			ans *= t;
			a /= t;
		}
		printf("%d\n", ans);
	}
	return 0;
}