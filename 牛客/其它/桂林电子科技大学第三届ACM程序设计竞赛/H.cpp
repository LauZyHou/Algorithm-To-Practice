#include<bits/stdc++.h>
using namespace std;

char r[60];

int main() {
	int T;
	scanf("%d",&T);
	getchar();
	char c;
	int i=-1;
	while(T--) {
		while((c=getchar())!='\n') {
			i++;
			if(i&1)
				continue;
			r[i/2]=c;
		}
		r[i/2+1]='\0';
		puts(r);
		i=-1;
	}
	return 0;
}
