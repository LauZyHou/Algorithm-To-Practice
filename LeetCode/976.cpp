class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int len = A.size();
		if(len<3)
			return 0;
		sort(A.begin(),A.end());
		for(int i=len-1;i>=2;i--)
			if(A[i]<A[i-1]+A[i-2])
				return A[i]+A[i-1]+A[i-2];
		return 0;
    }
};