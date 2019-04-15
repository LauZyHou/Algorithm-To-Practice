#include<bits/stdc++.h>
using namespace std;

int t;
int n,m;
char c;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		int a[105] = {0};
		int b[105] = {0};
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++) {
				/*
				A directive composed of white-space character(s) is executed 
				by reading input up to the first non-white-space character 
				(which remains unread), 
				or until no more characters can be read.
				*/
				scanf(" %c",&c);
				if(c=='.'){
					a[i]++;
					b[j]++;
				}
			}
		//注意max_element返回指针
		int maxiIndex = max_element(a,a+n) - a;
		int maxjIndex = max_element(b,b+m) - b;
		//取最大的行或者列的吃掉的草数量
		int t = max(a[maxiIndex],b[maxjIndex]);
		printf("%d %d %d\n",t/2,maxiIndex+1,maxjIndex+1);
	}
	return 0;
}