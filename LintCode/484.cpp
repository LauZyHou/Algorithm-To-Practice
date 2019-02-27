class Solution {
public:
    /**
     * @param A: An integer array
     * @param index1: the first index
     * @param index2: the second index
     * @return: nothing
     */
    void swapIntegers(vector<int> &A, int a, int b) {
        int c = A[a];
		A[a] = A[b];
		A[b] = c;
    }
};