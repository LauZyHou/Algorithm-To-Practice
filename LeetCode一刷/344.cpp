//#define TEST

#ifdef TEST

#include<bits/stdc++.h>
using namespace std;

#endif

class Solution {
public:
    string reverseString(string s) {
    	int len=s.length();
    	char* c=new char[len+1];
        for(int i=len-1;i>=0;i--)
        	c[len-1-i]=s[i];
        c[len]='\0';
//        string s_c(c);
        return string(c);
    }
};


#ifdef TEST

int main(){
	Solution* s=new Solution();
	string s_c=s->reverseString(string("123 abc"));
	cout<<s_c;
	return 0;
}

#endif

