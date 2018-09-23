#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

//小写变大写输出

char str[100];
size_t len;


int main(){
//    freopen("input.txt","r",stdin);
    while(gets(str)){
        len=strlen(str);
        for(int i=0;i<len;i++)
            if('a'<=str[i] && 'z'>=str[i])
                printf("%c",str[i]-'a'+'A');
            else
                printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}
