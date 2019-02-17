#include<bits/stdc++.h>
using namespace std;


class Solution {
	public:
		vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
			int ans=0;
			vector<int> res(queries.size());
			for(int i=0; i<A.size(); i++){
				ans+=(A[i]&1)==0?A[i]:0;
//				printf("%d\n",A[i]);
			}			
			for(int i=0; i<queries.size(); i++) {
				int s=queries[i][0];
				int index=queries[i][1];
				//odd->even
				if((A[index]&1)==1 && (s&1)==1) {
					ans+=A[index]+s;
				}
				//even->even
				else if((A[index]&1)==0 && (s&1)==0) {
					ans+=s;
				}
				//even->odd
				else if((A[index]&1)==0 && (s&1)==1) {
					ans-=A[index];
				}
				res[i]=ans;
				A[index]+=s;
			}
			return res;
		}
};

int main() {
	Solution s;
	vector<int> A({1,2,3,4});
	vector<vector<int>> Q({{1,0},{-3,1},{-4,0},{2,3}});
	vector<int> R=s.sumEvenAfterQueries(A,Q);
	system("pause");
	return 0;
}

