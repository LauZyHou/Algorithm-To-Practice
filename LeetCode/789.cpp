class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& g, vector<int>& t) {
        int len = g.size();
		int path = abs(t[0]) + abs(t[1]);
		for(int i=0;i<len;i++) {
			if(abs(g[i][0]-t[0])+abs(g[i][1]-t[1])<=path)
				return false;
		}
		return true;
    }
};