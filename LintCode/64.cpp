class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        if(n==0)
			return ;
		int i = m-1;
		int j = n-1;
		int idx = m+n-1;
		while(i>=0 && j>=0){
			if(A[i]>B[j])
				A[idx--] = A[i--];
			else
				A[idx--] = B[j--];
		}
		while(i>=0)
			A[idx--] = A[i--];
		while(j>=0)
			A[idx--] = B[j--];
    }
};