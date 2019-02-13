#include<bits/stdc++.h>
using namespace std;

double l1,l2,l3;
int t;
int x,y;

int main(){
	scanf("%lf%lf",&l1,&l2);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		l3=sqrt(x*x+y*y);
		if(l1+l2>l3 && l2+l3>l1 && l3+l1>l2){
			printf("0\n");
		}
		else{
			double a[3];
			a[0]=l1;
			a[1]=l2;
			a[2]=l3;
			sort(a,a+3);
			printf("%.8lf\n",a[2]-a[1]-a[0]);
		}
	}
	return 0;
}
