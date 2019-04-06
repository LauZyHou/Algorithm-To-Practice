class Solution {
public:
    bool isMonotonic(vector<int>& A) {
		int len = A.size();
		if(len<2)
			return true;
		bool t;
		int i;
		for(i=1;i<len;i++){
			if(A[i]>A[i-1]){
				t = true;
				break;
			}else if(A[i]<A[i-1]){
				t = false;
				break;
			}
		}
		i++;
		for(;i<len;i++){
			if(t && A[i]<A[i-1])
				return false;
			if(!t && A[i]>A[i-1])
				return false;
		}
		return true;
    }
};