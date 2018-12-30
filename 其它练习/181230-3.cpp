#include<bits/stdc++.h>
using namespace std;
//I

int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		//space
		for(int j=0;j<i;j++)
			printf(" ");
		//*
		for(int j=0;j<n;j++)
			printf("*");
		printf("\n");
	}
	for(int i=n-2;i>=0;i--){
		//space
		for(int j=0;j<i;j++)
			printf(" ");
		//*
		for(int j=0;j<n;j++)
			printf("*");
		printf("\n");
	}	
	return 0;
}
