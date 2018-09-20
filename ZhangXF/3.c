#include<stdio.h>
#include<stdlib.h>


int main(){
	int a=77;
	int* b=&a;
	int** c=&b;
	
	printf("%d\n",a);
	printf("%d\n",*b);
	printf("%d\n",**c);
	
	return 0;
}
