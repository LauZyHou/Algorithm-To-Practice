#include<bits/stdc++.h>
using namespace std;

#define N 111
char c[N];

int Cmp(char a,char b){
    if(a=='C' || a=='M' && b=='Y')
        return true;
    return false;
}

int main(){
    while(gets(c)){
        sort(c,c+strlen(c),Cmp);//ÇÉÓÃsort
        puts(c);
    }
    return 0;
}
