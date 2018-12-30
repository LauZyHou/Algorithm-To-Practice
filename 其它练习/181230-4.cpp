#include<bits/stdc++.h>
using namespace std;
//L

//a/b + c/d=(ad+bc)/bd
//a/b - c/d=(ad-bc)/bd

int gcd(int a,int b) {
	if(a%b==0)  return b;
	else    return gcd(b,a%b);
}

int lcm(int a,int b) {
	return a*b/gcd(a,b);
}

int t,op;
int a,b,c,d;
int ad,bc,bd;
int zi;
bool tong;
int gc; 

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d",&op,&a,&b,&c,&d);
		ad=a*d;
		bc=b*c;
		bd=b*d;
		if(op>0){
			zi=ad+bc;
		}else{
			zi=ad-bc;
		}
		if(zi*bd>=0){//Í¬ºÅ 
			tong=true;	
		}else{
			tong=false;
		}
		zi=abs(zi);
		bd=abs(bd);
		if(!tong)
			printf("-");
		gc=gcd(zi,bd);
		printf("%d",zi/gc);
		printf("/%d\n",bd/gc);
	}
	return 0;
}
