#include<bits/stdc++.h>
using namespace std;

long long n,sx,sy,ex,ey;


int main(){
	cin>>n>>sx>>sy>>ex>>ey;
	long long a=abs(ex-sx);
	long long b=abs(ey-sy);
	cout<<max(a,b);
	return 0;
}
