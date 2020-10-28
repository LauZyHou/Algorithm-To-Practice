class Solution {
public:
    bool searchMatrix(vector<vector<int>>& g, int t) {
        if (g.empty() || g[0].empty()) return false;

        int n = g.size(), m = g[0].size();
        
        int l = 0, r = n * m - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (g[mid / m][mid % m] >= t)
                r = mid;
            else
                l = mid + 1;
        }

        return g[l / m][l % m] == t;
    }
};