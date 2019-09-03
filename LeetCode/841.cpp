class Solution {
public:
	bool* isok = nullptr;
	int len;

	void dfs(int m,vector<vector<int>>& rooms) {
		for(auto a:rooms[m]) {
			if(!isok[a]) {
				isok[a] = true;
				dfs(a,rooms);
			}
		}
	}

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        len = rooms.size();
		if(len<2)
			return true;
		isok = new bool[len];
		for(int i=0;i<len;i++)
			isok[i] = false;
		isok[0] = true;
		dfs(0,rooms);
		for(int i=0;i<len;i++)
			if(isok[i]==false)
				return false;
		return true;
    }
};