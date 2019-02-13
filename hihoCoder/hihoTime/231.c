#include<stdio.h>
//https://hihocoder.com/discuss/question/5626
int gcd(int a,int b) {
	if(b==0)
		return a;
	if(a<b) {
		int c=a;
		a=b;
		b=c;
	}
	return gcd(b,a%b);
}

int T,L,F,D,G;

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&L,&F,&D);
		G=gcd(L,D);
		if(F>G)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
