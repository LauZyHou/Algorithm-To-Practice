#include<bits/stdc++.h>
using namespace std;

int n,a,b,cnt;

int main() {
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        if(a>2){
            cnt=a/b;
            int add=cnt/5*2+(cnt-cnt/5*5)/3;
            cnt+=add;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
