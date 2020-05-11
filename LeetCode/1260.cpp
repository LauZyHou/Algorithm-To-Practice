class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& vv, int k) {
        int m = vv.size();
        if(!m) vv; 
        int n = vv[0].size();
        if(!n) vv;
        k = k % (m*n);
        while(k--) {
            vector<int> sp_col(m); // 特殊列
            for(int i=1;i<=m;i++)
                sp_col[i%m] = vv[i-1][n-1];
            for(int i=0;i<m;i++) {
                for(int j=n-1;j>=1;j--) {
                    vv[i][j] = vv[i][j-1];
                }
            }
            for(int i=0;i<m;i++) {
                vv[i][0] = sp_col[i];
            }
        }
        return vv;
    }
};