#include<bits/stdc++.h>
using namespace std;
//D

int n;
int a[5010];
bool b[5010]= {false}; //searched

//c->d->e
bool hasTri(int c) {
	b[c]=true;

	int d=a[c];
	if(b[d])
		return false;
//	b[d]=true;

	int e=a[d];
	if(b[e])
		return false;
//	b[e]=true;

	return a[e]==c;
}


int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	for(int i=1; i<=n; i++) {
		if(hasTri(i)) {
			printf("YES\n");
			goto BYE;
		}
	}
	printf("NO\n");
BYE:
	return 0;
}
