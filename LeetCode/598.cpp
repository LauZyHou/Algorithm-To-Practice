class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mina = INT_MAX;
		int minb = INT_MAX;
		for(auto k : ops){
			if(k[0]<mina)
				mina = k[0];
			if(k[1]<minb)
				minb = k[1];
		}
		return min(mina,m) * min(minb,n);
    }
};