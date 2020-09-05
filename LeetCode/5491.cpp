class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int len = mat.size();
        for(int i=0;i<len;i++) {
            ans += mat[i][i];
        }
        for(int i=0;i<len;i++) {
            ans += mat[i][len-1-i];
        }
        if(len&1) {
            ans -= mat[len/2][len/2];
        }
        return ans;
    }
};