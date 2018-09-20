#include<stdio.h>
#include<stdlib.h>

struct Person{
	int id;
	char* name;
};


int main(){
	struct Person* p=malloc(sizeof(struct Person));
	p->id=1;
	char c[]="nb";
	p->name=c;
//	int a;
//	int* p_a=malloc(sizeof(int));
	printf("%d\n",p->id);
	printf("%s",p->name);
//	system("PAUSE");
	return 0;
}
