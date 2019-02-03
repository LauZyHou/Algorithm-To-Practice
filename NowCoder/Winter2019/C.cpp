#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 30010;

int n;
int p[N];

int main() {
	cin>> n;
	for(int i=0; i<n; i++)
		cin>>p[i];
	if(n==1)
		cout<<(p[0]?p[0]:-1)<<endl;
	else if(p[0]<=p[n-1])
		cout<<-1<<endl;
	else {
		vector<int> sets;
		//过滤,找到在第一个数和最后一个数之间的数放到集合里
		for(int i=1; i<n-1; i++) {
			if(p[i]<p[0] && p[i]>p[n-1]) {
				sets.push_back(p[i]);
			}
		}

		if(sets.size()) { //集合不为空
			for(int i=14,k=0; i>=0; i--) {

				//把当前这一位是1的换到前面去(第k位置)
				for(int j=k; j<sets.size(); j++) {
					if(sets[j]>>i & 1) {
						swap(sets[j],sets[k]);
						break;//只要一个就行了
					}
				}

				//当前这一位找到了1
				if(sets[k]>>i & 1) {
					//把后面的数的这一位都弄成0
					for(int j=k+1; j<sets.size(); j++) {
						if(sets[j]>>i & 1)
							sets[j]^=sets[k];
					}
					k++;
				}

			}
		}

		int res=p[0]^p[n-1];
		//从最高位开始,看看每一位有没有可能是1,如果可能是1就把它变成1
		if(sets.size()) {
			for(int i=14,k=0; i>=0; i--) {
				if(sets[k]>>i & 1) {
					//已经计算得的结果这一位如果不是1,就异或一下它以变成1
					if(!(res>>i & 1))
						res^=sets[k];
					k++;
				}
			}
		}

		if(!res)
			res=-1;
		cout<<res<<endl;

	}

	return 0;
}
