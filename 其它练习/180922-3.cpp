#include<iostream>
#include<cstdio>
using namespace std;

//ACM输入测试 

int a,b;

int main(){
	
	//1.读入若干行
/*	
	while(cin>>a>>b){
		cout<<a+b<<endl;
	} 
*/
	//2.把从控制台的输入改成从键盘写入
	//这样可以方便输入测试,提交时注释掉它 
	freopen("input.txt","r",stdin);
	cin>>a>>b;
	cout<<a+b<<endl;
	
	return 0;
}
