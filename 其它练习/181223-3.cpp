#include<bits/stdc++.h>
using namespace std;
//B题区间面包
int t,n;
int a[1010];
int i,j,maxi;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		i=j=0;//i+1,j+1是题目区间
		maxi=0;
		while(i<n && j<n){
			if(a[i]<=i){//题意需要a[i]>=(i+1) 
				i+=1;
				continue;
			}
			if(j<i){//j提前 
				j=i;
			}
			if(){
				// FIXME
			}
			
			
		}
	}
	
	return 0;
}
