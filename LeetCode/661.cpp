class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ans;
		int xlen = M.size();
		if(!xlen)
			return ans;
		int ylen = M[0].size();
		if(!ylen)
			return ans;
		for(int i=0;i<xlen;i++){
			vector<int> line;
			for(int j=0;j<ylen;j++){
				int cnt = 1;
				int sum = M[i][j];
				if(i>0 && j>0){
					cnt++;
					sum+=M[i-1][j-1];
				}
				if(i>0){
					cnt++;
					sum+=M[i-1][j];
				}
				if(j>0){
					cnt++;
					sum+=M[i][j-1];
				}
				if(i<xlen-1 && j>0){
					cnt++;
					sum+=M[i+1][j-1];
				}
				if(i<xlen-1){
					cnt++;
					sum+=M[i+1][j];
				}
				if(i<xlen-1 && j<ylen-1){
					cnt++;
					sum+=M[i+1][j+1];
				}
				if(j<ylen-1){
					cnt++;
					sum+=M[i][j+1];
				}
				if(i>0 && j<ylen-1){
					cnt++;
					sum+=M[i-1][j+1];
				}
				line.push_back(sum/cnt);
			}
			ans.push_back(line);
		}
		return ans;
    }
};