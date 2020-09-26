class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mp, int t) {
        int m = mp.size();
        if (!m)
            return false;
        int n = mp[0].size();
        if (!n)
            return false;

        int l = 0, r = m - 1;
        while (l < r) {
            int mid = l+r >> 1;
            if (mp[mid][n-1] >= t)
                r = mid;
            else 
                l = mid + 1;
        }
        
        int row = l;
        l = 0, r = n - 1;
        while (l < r) {
            int mid = l+r >> 1;
            if (mp[row][mid] >= t)
                r = mid;
            else
                l = mid + 1;
        }
    
        return mp[row][r] == t;
    }
};