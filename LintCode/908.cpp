class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int minE = *min_element(A.begin(),A.end());
		int maxE = *max_element(A.begin(),A.end());
		return maxE-minE>2*K?maxE-minE-2*K:0;
    }
};