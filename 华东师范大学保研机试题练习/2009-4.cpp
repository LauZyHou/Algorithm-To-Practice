#include<bits/stdc++.h>
using namespace std;

//求GCD和LCD,读入a和b满足a>=b

//m<=n
int gcd(int m,int n){
    if(m==0)
        return n;
    while(n%m!=0){
        int t=m;
        m=n%m;
        n=t;
    }
    return m;
}

//m<=n
int lcm(int m,int n){
    return n/gcd(m,n)*m;
}

int a,b,t;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        printf("%d %d\n",gcd(a,b),lcm(a,b));
    }
    return 0;
}
