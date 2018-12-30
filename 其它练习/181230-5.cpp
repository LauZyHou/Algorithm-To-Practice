#include<bits/stdc++.h>
using namespace std;
//F

int a[100010];
int n;
int l_mx_i=0,r_mx_i=1;
int mx;//goal
int nowmx;

void findRMax(int c){
	r_mx_i=c+1;
	for(int i=c+1;i<n;i++){
		if(a[i]>a[r_mx_i])
			r_mx_i=i;
	}
}

int main(){
	scanf("%d",&n);
	
	scanf("%d",a);
	for(int i=1;i<n;i++){
		scanf("%d",a+i);
		if(a[i]>a[r_mx_i]){
			r_mx_i=i;
		}
	}
	
	mx=abs(a[l_mx_i]-a[r_mx_i]);
	for(int i=1;i<=n-2;i++){
		//left
		if(a[i]>a[l_mx_i])
			l_mx_i=i;
		
		//right
		if(r_mx_i==i){
			findRMax(i);//new rmax 
		}
		
		nowmx=abs(a[l_mx_i]-a[r_mx_i]);
		if(nowmx>mx)
			mx=nowmx;
	}
	printf("%d",mx);
	return 0;
}
