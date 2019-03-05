class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
		int leny = A.size();
		int lenx = A[0].size();
		vector<vector<int>> v(lenx);
		for(int j=0;j<lenx;j++)
			for(int i=0;i<leny;i++)
				v[j].push_back(A[i][j]);
		return v;
    }
};