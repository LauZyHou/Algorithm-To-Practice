#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> sortArrayByParityII(vector<int>& A) {
			int i=0;
			int j=1;
			while(i<A.size() && j<A.size()) {
				while(j<A.size() && (A[j]&1)==1) {
					j+=2;
				}
				while(i<A.size() && (A[i]&1)==0) {
					i+=2;
				}
				if(i>=A.size() || j>=A.size())
					break;
				int t=A[i];
				A[i]=A[j];
				A[j]=t;
				i+=2;
				j+=2;
			}
			return A;
		}
};                                          
