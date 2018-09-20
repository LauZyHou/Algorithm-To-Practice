#include<stdio.h>
#include<stdlib.h>

int n;
int* a;
int i;

int main(){
//	char a[]="14423";
//	int b[]={1,2,3,4,5,6,7};
	scanf("%d",&n);
	a=malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",a+i);
		printf("%d\t",*(a+i));
	}
		
//	int i;
//	for(i=0;a[i]!='\0';i++);
//	printf("%d",i);
//	printf("%d",sizeof(b)/sizeof(int));
	return 0;
}
