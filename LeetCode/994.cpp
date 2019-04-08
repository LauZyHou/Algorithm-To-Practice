class Solution {	
public:
    int orangesRotting(vector<vector<int>>& g) {
        int cnt = 0;
		queue<pair<int,int>> q;
		int xlen = g.size();
		if(!xlen)
			return false;
		int ylen = g[0].size();
		if(!ylen)
			return false;
		for(int i=0;i<xlen;i++){
			for(int j=0;j<ylen;j++){
				if(g[i][j]==1)
					cnt++;
				else if(g[i][j]>1)
					q.push(pair<int,int>(i,j));
			}
		}
		int ans = 0;
		bool change = true;//记录这一分钟有么有橘子腐烂
		while(cnt && change){
			change = false;
			int qlen = q.size();
			while(qlen--){
				pair<int,int> p = q.front();
				q.pop();
				int i = p.first;
				int j = p.second;
				if(i>0 && g[i-1][j]==1){
					change = true;
					cnt--;
					q.push(pair<int,int>(i-1,j));
					g[i-1][j] = 2;
				}
				if(j>0 && g[i][j-1]==1){
					change = true;
					cnt--;
					q.push(pair<int,int>(i,j-1));
					g[i][j-1] = 2;
				}
				if(i<xlen-1 && g[i+1][j]==1){
					change = true;
					cnt--;
					q.push(pair<int,int>(i+1,j));
					g[i+1][j] = 2;
				}
				if(j<ylen-1 && g[i][j+1]==1){
					change = true;
					cnt--;
					q.push(pair<int,int>(i,j+1));
					g[i][j+1] = 2;
				}
				q.push(p);
			}
			ans++;
		}
		return change?ans:-1;//cnt>0?-1:ans
    }
};