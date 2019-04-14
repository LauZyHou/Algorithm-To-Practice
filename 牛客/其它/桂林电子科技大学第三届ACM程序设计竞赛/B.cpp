#include<bits/stdc++.h>
using namespace std;

char k[100010];
int r,t;
set<string> s;

int main(){
	int N,M;
	//int py[26];
	char c;
	/*
	for(int i=0;i<26;i++){
		py[i]=(1<<i);
	}
	scanf("%d%d",&N,&M);
	getchar();
	set<int> s;
	for(int i=0;i<N;i++){
		int t=0;
		while((c=getchar())!='\n'){
			t |= py[c-'a'];
		}
		s.insert(t);
	}
	printf("%d",s.size());
	*/
	
	scanf("%d%d",&N,&M);
	getchar();
	for(int i=0;i<N;i++){
		r=t=0;
		while((c=getchar())!='\n'){
			if(t&(1<<(c-'a')))
				continue;
			k[r++] = c;
			t |= 1<<(c-'a');
		}
		k[r]='\0';
		s.insert(string(k));
	}
	printf("%d",s.size());
	return 0;
}
