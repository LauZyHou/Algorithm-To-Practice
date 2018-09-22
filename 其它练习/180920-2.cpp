#include<iostream>
#include<string>
#include<cctype>//c语言里ctype.h 
using namespace std;
//cctype用在string上的练习 

int main(){
	string s="OK 123\nABC ";
	
	//is alpha number,是字母或数字时返回非0值 
	for(string::iterator it=s.begin();it!=s.end();it++){
		cout<<isalnum(*it)<<" ";//字母都返回1,数字都返回4?? 
	}
	cout<<"\n";
	
	//is alpha,是字母时返回非0值
	for(int i=0;i<s.size();i++){
		cout<<isalpha(s[i])<<" ";
	}
	cout<<"\n";
	
	
	return 0;
}
