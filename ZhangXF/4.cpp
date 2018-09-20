#include<stdio.h>

/*
void swap(int* a,int* b){
	int t=*a;
	*a=*b;
	*b=t;
}
*/

void swap(int& a,int& b){
	int t=a;
	a=b;
	b=t;
}


int main(){
	int m=4,n=3;
	swap(m,n);
	printf("%d\t%d",m,n);
	return 0;
}
