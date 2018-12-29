#include<bits/stdc++.h>
using namespace std;

int n;
char c[65535];

int main(){
    scanf("%d",&n);
    getchar();
    while(n--){
        gets(c);
        if(!strcmp(c,"E"))
            printf("Excellent\n");
        else if(!strcmp(c,"C"))
            printf("Cheer\n");
        //...Ê¡ÂÔ
    }
    return 0;
}
