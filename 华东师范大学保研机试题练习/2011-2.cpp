#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int T;
double s,t,e;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%lf%lf%lf",&s,&t,&e);
        if(fabs(s-t)<=e)
            cout<<"Accept"<<endl;
        else
            cout<<"Wrong Answer"<<endl;
    }
    return 0;
}
