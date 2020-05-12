class Solution {
private:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,1,-1,0};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& vv, int sr, int sc, int newColor) {
        int row = vv.size();
        if(!row)
            return vv;
        int col = vv[0].size();
        if(!col)
            return vv;
        int oldColor = vv[sr][sc];
        if(oldColor == newColor)
            return vv;
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        while(!q.empty()) {
            int len = q.size();
            for(int i=0;i<len;i++) {
                pair<int,int> &p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                vv[x][y] = newColor;
                for(int j=0;j<4;j++) {
                    int _x = x + dx[j];
                    int _y = y + dy[j];
                    if(_x<0 || _y<0 || _x>=row || _y>=col || vv[_x][_y]!=oldColor)
                        continue;
                    q.push(make_pair(_x,_y));
                }
            }
        }
        return vv;
    }
};