class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mt) {
        int m = mt.size();
		if(!m)
			return true;
		int n = mt[0].size();
		if(!n)
			return true;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(i<m-1 && j<n-1 && mt[i][j]!=mt[i+1][j+1])
					return false;
		return true;
	}
};