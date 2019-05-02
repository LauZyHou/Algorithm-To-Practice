class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
		vector<vector<int>> ans;
		int len = S.size();
		int i=0;
		int j=0;
		while(++j<len){
			if(S[j]==S[i])
				continue;
			if(j-i>2)
				ans.push_back(vector<int>({i,j-1}));
			i=j;
		}
		if(j-i>2)
			ans.push_back(vector<int>({i,j-1}));
		return ans;
    }
};