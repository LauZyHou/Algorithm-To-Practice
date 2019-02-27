class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        int a=0;
		for(int i=0;i<A.size();i++)
			a=a^A[i];
		return a;
    }
};