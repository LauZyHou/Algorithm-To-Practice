class Solution {
public:
    bool searchMatrix(vector<vector<int>>& g, int t) {
        int n = g.size();
        if (!n) return false;
        int m = g[0].size();
        if (!m) return false;
        int x = 0, y = m - 1;
        while (x < n && 0 <= y) {
            if (g[x][y] < t)
                x ++ ;
            else if (g[x][y] > t)
                y -- ;
            else
                return true;
        }
        return false;
    }
};