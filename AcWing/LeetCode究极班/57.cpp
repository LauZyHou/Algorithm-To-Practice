class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        int n = a.size();
        int k = 0;
        vector<vector<int>> res;

        while (k < n && a[k][1] < b[0]) {
            res.emplace_back(a[k]);
            k ++;
        }

        if (k < n) {
            b[0] = min(b[0], a[k][0]);
            while (k < n && a[k][0] <= b[1]) {
                b[1] = max(b[1], a[k][1]);
                k ++;
            }
        }
        res.emplace_back(b);

        while (k < n) {
            res.emplace_back(a[k]);
            k ++;
        }

        return res;
    }
};