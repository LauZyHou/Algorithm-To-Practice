class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        m--,n--;
        while(m>=0 && n>=0) {
            if(A[m] >= B[n]) {
                A[m+n+1] = A[m];
                m--;
            }
            else {
                A[m+n+1] = B[n];
                n--;
            }
        }
        while(n>=0) {
            A[m+n+1] = B[n];
            n--;
        }
    }
};