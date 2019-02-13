#include<bits/stdc++.h>
using namespace std;
/*
 输入一个有符号整数，输出该整数的反转值。
*/
int main(){
	string a;
	cin>>a;
	int k=0;
	if(a[0]=='+'||a[0]=='-'){
		k=1;
		cout<<a[0];
	}
	bool weav=true;
	for(int i=a.length()-1;i>=k;i--){
		if(a[i]=='0'&&weav==true&&i!=k)
			continue;
		else
			weav=false;
		cout<<a[i];
	}
	return 0;
}
