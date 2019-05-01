#include<bits/stdc++.h>
using namespace std;

int t;
//vector<int> a(1001, 0);
//vector<int> b(1001, 0);
int n;
int k;

int a[1001],b[1001],v1[1001],v2[1001];
/*
template<typename T> std::vector<int> argsort(const std::vector<T>& array, int len)
{
	std::vector<int> array_index(len, 0);
	for (int i = 0; i < len; ++i)
		array_index[i] = i;

	std::sort(0, len, [&array](int pos1, int pos2) {return (array[pos1] < array[pos2]);});
	return array_index;
}
*/

void argsort(int* p,int len,int* r){
	for(int i=0;i<len;i++)
		r[i] = i;
	sort(r,r+len,[&p](int pos1, int pos2) {return (p[pos1] < p[pos2]);});
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&k);
			a[i] = k;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&k);
			b[i] = k;
		}
//		vector<int> v1 = argsort(a, n);
//		vector<int> v2 = argsort(b, n);
		argsort(a,n,v1);
		argsort(b,n,v2);
		for(int i=n-1;i>=0;i--)
			printf("%d %d ",v1[i]+1,v2[i]+1);
		printf("\n");
	}
	return 0;
}
