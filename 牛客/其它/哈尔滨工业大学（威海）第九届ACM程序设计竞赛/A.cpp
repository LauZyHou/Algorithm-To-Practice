#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	getchar();
	char c;
	map<char,int> mp;
	while((c=getchar())!='\n'){
		mp[c]+=1;
	}
	int mx=0;
	for(char i='a';i<='z';i++){
		if(mp[i]>mx)
			mx=mp[i];
	}
	printf("%d",n-mx);
	return 0;
}
