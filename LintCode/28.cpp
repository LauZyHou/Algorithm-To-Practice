class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &m, int t) {
        int leny = m.size();
		if(!leny)
			return false;
		int lenx = m[0].size();
		if(!lenx)
			return false;
		int i = 0,j = lenx-1;
		while(i<leny && j>=0){
			if(m[i][j]==t)
				return true;
			if(m[i][j]>t)
				j--;
			else
				i++;
		}
		return false;
    }
};