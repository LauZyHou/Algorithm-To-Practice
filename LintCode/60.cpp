class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
    int searchInsert(vector<int> &A, int t) {
        int len = A.size();
		if(!len)
			return 0;
		if(len==1)
			return A[0]>=t?0:1;
		int i = 0;
		int j = len-1;
		int mid;
		while(i<=j){
			mid = (i+j)/2;
			if(t==A[mid])
				return mid;
			if(t>A[mid])
				i = mid+1;
			else
				j = mid-1;
		}
		if(t>A[mid])
			return mid+1;
		return mid;
    }
};