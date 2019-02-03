#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100010;

int n;
int a[N],b[N];

int main() {
	cin >> n;
	for(int i=1; i<=n; i++) cin>> a[i];
	sort(a,a+n+1);

	for(int i=0,j=0; j<=n; i++,j+=2) b[j]=a[i];
	for(int i=n,j=1; j<=n; i--,j+=2) b[j]=a[i];

	int res=0;
	for(int i=1; i<=n; i++) res+=(b[i]-b[i-1])*(b[i]-b[i-1]);

	cout<<res<<endl;
	return 0;
}
