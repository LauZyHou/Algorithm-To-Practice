#include<bits/stdc++.h>
using namespace std;
bool Ns[100005]= {false};
int T,N,M;

struct node {
	int a;
	int b;
};

bool compareAsc(const node &v1,const node &v2) {
	return v1.a > v2.a;
}

int main() {
	while(cin>>T) {
		cin>>N>>M;
		struct node Nds[M];
		for(int i=0; i<M; i++) {
			cin>>Nds[i].a>>Nds[i].b;
		}
	}
	return 0;
}
