#include<bits/stdc++.h>
using namespace std;
char a[10010];
bool b[4]={false};
int sum=0,i=0;
int main(){
	gets(a);
	int ji=0,ou=0;
	for(i=0;a[i]!='\0';i++){
		sum+=a[i]-'0';
		if(i%2==0)
			ji+=a[i]-'0';
		else
			ou+=a[i]-'0';
	}
	//3
	if(sum%3==0)
		b[0]=true;
	//5
	if(a[i-1]=='0' || a[i-1]=='5')
		b[1]=true;
	//8
	int end3=0;
	if(i>3){
		for(int j=i-3;j<i;j++){
			end3*=10;
			end3+=a[j]-'0';
		}
	}else{
		for(int j=0;j<i;j++){
			end3*=10;
			end3+=a[j]-'0';
		}	
	}
	if(end3%8==0)
		b[2]=true;
	//11
	if(abs(ji-ou)%11==0)
		b[3]=true;
	if(b[0] || b[1] || b[2] || b[3]){
		cout<<"Yes\n";
		bool sp=false;
		if(b[0])
			cout<<"3";
		sp=sp|b[0];
		if(b[1]){
			if(sp)
				cout<<" ";
			cout<<"5";
		}
		sp=sp|b[1];
		if(b[2]){
			if(sp)
				cout<<" ";
			cout<<"8";
		}
		sp=sp|b[2];
		if(b[3]){
			if(sp)
				cout<<" ";
			cout<<"11";
		}
		cout<<endl;
	}else{
		cout<<"No\n";
	}
	return 0;
}
