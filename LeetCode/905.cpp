/*
#include<bits/stdc++.h>
using namespace std;
*/

class Solution {
	public:
		void swap(int& i,int& j) {
			int t=i;
			i=j;
			j=t;
		}

		vector<int> sortArrayByParity(vector<int>& A) {
			int i=0;
			int j=A.size()-1;
			int end=j;
			while(i<j) {
				while(i!=end && (A[i]&1)==0) {
					i++;
				}

				if(i==end) {
					break;
				}

				while(j!=0 && (A[j]&1)==1) {
					j--;
				}

				if(j==0) {
					break;
				}

				if(i<j) {
					swap(A[i],A[j]);
					i++;
					j--;
				}
			}
			return A;
		}
};

/*
int main() {
	vector<int> obj;
	obj.push_back(0);
	obj.push_back(1);
	obj.push_back(2);
	Solution* s=new Solution();
	vector<int> newObj=s->sortArrayByParity(obj);
	for(int i=0; i<obj.size(); i++) {
		cout<<obj[i]<<",";
	}
	return 0;
}
*/
