class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<bool> rs(n);
        vector<bool> cs(m);
        for(auto p:indices) {
            rs[p[0]] = !rs[p[0]];
            cs[p[1]] = !cs[p[1]];
        }
        int rnum = 0;
        int cnum = 0;
        for(int i=0;i<n;i++)
            if(rs[i])
                rnum++;
        for(int i=0;i<m;i++)
            if(cs[i])
                cnum++;
        return rnum*m + cnum*n - rnum*cnum*2;
    }
};