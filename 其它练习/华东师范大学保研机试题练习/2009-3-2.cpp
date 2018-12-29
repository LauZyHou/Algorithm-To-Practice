#include<bits/stdc++.h>
using namespace std;

//素数对,正解

int n,t,cnt,i;

bool isSu(int n){
    if(n<2)
        return false;
    if(n<4)
        return true;
    for(int i=2;i*i<=n;i++){
        if(!(n%i))
            return false;
    }
    return true;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=2;2*i<n+1;i++){
            if(isSu(i) && isSu(n+1-i))
                cnt+=2;
        }
        if(n+1==2*i && isSu(i))
            cnt+=1;
        printf("%d\n",cnt);
        cnt=0;
    }
    return 0;
}
