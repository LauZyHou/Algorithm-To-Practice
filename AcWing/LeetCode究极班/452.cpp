class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        if (!n) return 0;
        int res = 1, r = points[0][1];
        for (int i = 1; i < n; i ++ ) {
            if (points[i][0] > r) {
                res ++ ;
                r = points[i][1];
            }
        }
        return res;
    }
};