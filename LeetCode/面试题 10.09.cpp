class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mp, int t) {
        int m = mp.size();
        if (!m)
            return false;
        int n = mp[0].size();
        if (!n)
            return false;
        
        int x = m - 1, y = 0;
        while (x >= 0 && y < n) {
            int v = mp[x][y];
            if (v == t)
                return true;
            if (v > t)
                x--;
            else
                y++;
        }

        return false;
    }
};