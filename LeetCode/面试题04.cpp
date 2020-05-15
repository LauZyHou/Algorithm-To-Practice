class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& vv, int t) {
        int m = vv.size();
        if(!m)
            return false;
        int n = vv[0].size();
        if(!n)
            return false;
        int i = 0;
        int j = n-1;
        while(0<=i && i<m && 0<=j && j<n) {
            if(vv[i][j] == t)
                return true;
            else if(vv[i][j] < t)
                i++;
            else 
                j--;
        }
        return false;
    }
};