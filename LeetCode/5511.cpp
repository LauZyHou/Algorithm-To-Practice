class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rlen = mat.size();
        if(!rlen)
            return 0;
        int clen = mat[0].size();
        if(!clen)
            return 0;
        vector<int> rows(rlen, 0);
        vector<int> cols(clen, 0);
        for(int i=0;i<rlen;i++) {
            for(int j=0;j<clen;j++) {
                if(mat[i][j]) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<rlen;i++) {
            for(int j=0;j<clen;j++) {
                if(mat[i][j] && rows[i]==1 && cols[j]==1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};