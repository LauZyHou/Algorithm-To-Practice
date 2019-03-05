class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        vector<int> m(A.size()+B.size());
		int i=0,j=0,k=0;
		while(k<m.capacity()){
			if(i==A.size()){
				m[k++]=B[j++];
				continue;
			}
			if(j==B.size()){
				m[k++]=A[i++];
				continue;
			}
			if(A[i]<B[j]){
				m[k++]=A[i++];
			}else{
				m[k++]=B[j++];
			}
		}
		return m;
    }
};