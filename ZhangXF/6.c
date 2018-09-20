#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++){
		for(j=0;j<n-i;j++)
			printf(" ");
		for(j=0;j<i;j++)
			if(j==i-1)
				printf("*");
			else
				printf("* ");
		printf("\n");
	}
	return 0;
}
