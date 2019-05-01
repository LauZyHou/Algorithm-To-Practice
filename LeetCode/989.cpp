class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int i = A.size()-1;
		vector<int> m;
		while(i>=0 || K>0) {
			if(i>=0)
				K+=A[i];
			m.push_back(K%10);
			K/=10;
			i--;
		}
		reverse(m.begin(),m.end());
		return m;
    }
};