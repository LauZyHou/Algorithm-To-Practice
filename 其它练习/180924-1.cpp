#include<bits/stdc++.h>
using namespace std;

//华师最终练习

int main(){
/*
    int a[]={2,4,5,1,5,2,6,2,1,4,1,6,2};
    sort(a,a+sizeof(a)/sizeof(int));
    int *ed=unique(a,a+sizeof(a)/sizeof(int));//unique把重复的移到后面,返回新的结束位置地址
    for(int* i=a;i<ed;i++){
        cout<<*i<<" ";
    }
*/
    __int64 a,b;
    while(scanf("%llX%llX",&a,&b)!=EOF){
        printf("%llx\n",a+b);//x是小写16进制,X是大写
    }
    return 0;
}
