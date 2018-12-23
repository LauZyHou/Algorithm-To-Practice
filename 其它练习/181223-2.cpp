//n^2-n+2
#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		if(n==0){
			cout<<1<<endl;
			continue;
		}
		cout<<n*n-n+2<<endl;
	}
	return 0;
} 
