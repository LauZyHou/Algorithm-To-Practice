#include<stdio.h>

char c[65535];

int getLen(char* c){
	int i;
	for(i=0;c[i]!='\0';i++)
		;
	return i;
}


int main(){
	 while(scanf("%s",c)!=EOF){
	 	int len=getLen(c);
//	 	printf("%d\n",len);
//	 	printf("\n-1-\n");
		int i=0,j=len-1;
		while(i<j){
			if(c[i]!=c[j])
				break;
			i++;
			j--;
		}
		if(i<j)
			printf("--------------no\n");
		else
			printf("--------------yes\n");
	 }
	return 0;
}
