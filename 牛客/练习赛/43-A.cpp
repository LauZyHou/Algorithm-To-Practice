#include<bits/stdc++.h>
using namespace std;

int s[100],a[100];
class Node
{
public:
	int a;
	int b;
	int i;
	Node* next=nullptr;
};

int main(){
	int n;
	map<int,Node*> mp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		Node *nd=new Node();
		scanf("%d%d",&nd->a,&nd->b);
		a[i] = nd->a;
		s[i] = nd->a + nd->b;
		nd->i = i;
		if(!mp[s[i]])
			mp[s[i]] = nd;
		else{
			nd->next = mp[s[i]];
			mp[s[i]] = nd;
		}
	}
	for(int i=0;i<n;i++){
		if(!mp[a[i]])
			continue;
		Node* p;
		for(p=mp[a[i]];p!=nullptr;p=p->next){
			if(i!=p->i && s[i]==p->a){
				printf("YE5");
				goto BYE;
			}
		}
	}
	printf("N0");
	BYE:
	return 0;
}