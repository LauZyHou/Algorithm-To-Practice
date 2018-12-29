#include<bits/stdc++.h>
using namespace std;

//¿ÕÆ¿»»Æ¡¾Æ

int e,f,c,sum,cnt;

int main(){
    while(scanf("%d%d%d",&e,&f,&c)!=EOF){
        sum=e+f;
        while(sum>=c){
            cnt+=sum/c;
            sum=sum/c+sum%c;
        }
        printf("%d\n",cnt);
        cnt=0;
    }
    return 0;
}
