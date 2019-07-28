#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b;
	int sum = 0;
	scanf("%d",&a);
	for(int i=1;i<=5;i++) {
		scanf("%d",&b);
		if(b<a)
			sum += b;
	}
	printf("%d\n",sum);
	return 0;
}
