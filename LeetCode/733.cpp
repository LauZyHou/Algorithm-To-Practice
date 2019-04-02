class Solution {
private:
	vector<vector<int>> v;
	int ilen,jlen;
	int nc;
	int origin;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		ilen = image.size();
		if(!ilen)
			return v;
		jlen = image[0].size();
		if(!jlen)
			return v;
		nc = newColor;
		v = std::move(image);
		origin = v[sr][sc];//记录原始的颜色,用于在递归时填色之后也判断
		if(v[sr][sc]!=nc)//相等的时候填充颜色也是一样的
			dfs(sr,sc);
		return v;
    }
	
	void dfs(int x,int y){
		v[x][y] = nc;
		if(x>0 && v[x-1][y]==origin)
			dfs(x-1,y);
		if(y>0 && v[x][y-1]==origin)
			dfs(x,y-1);
		if(x<ilen-1 && v[x+1][y]==origin)
			dfs(x+1,y);
		if(y<jlen-1 && v[x][y+1]==origin)
			dfs(x,y+1);
	}
};