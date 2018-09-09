#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int len=0,blank=0;
        char c;
        while((c=str[len])!='\0'){
            if(' '==c)
                ++blank;
            ++len;
        }
        int newlen=len+2*blank;
        str[newlen]='\0';
        --len;
        int i=newlen-1;
        for(;i>=0;--i){
            if(' '==str[len]){
                str[i]='0';
                --i;
                str[i]='2';
                --i;
                str[i]='%';
            }else{
                str[i]=str[len];
            }
            --len;
        }  
	}
};
