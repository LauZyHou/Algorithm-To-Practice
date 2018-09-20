#include<bits/stdc++.h>
using namespace std;

int howManyTransfer(int m,int n){
	int k=m^n;//异或结果中将不同为标记成了1
	//计算异或结果中1的个数
	int count=0;
	while(k){
		k=k&(k-1);
		count++;
	} 
	return count;
}

int main(){
	cout<<howManyTransfer(8,9)<<endl;
	cout<<howManyTransfer(13,10)<<endl;
	cout<<howManyTransfer(11,-1)<<endl;
	return 0;
}
