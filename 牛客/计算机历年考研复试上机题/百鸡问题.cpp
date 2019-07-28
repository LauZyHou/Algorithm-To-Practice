#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	for(int x=0;x<=n/5;x++) {
		for(int y=0;y<=min(n/3,100-x);y++) {
			int z = 100-x-y;
			if(x*3*5+y*3*3+z<=3*n)
				printf("x=%d,y=%d,z=%d\n",x,y,z);
		}
	}
	return 0;
}
