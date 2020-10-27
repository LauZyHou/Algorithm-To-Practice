class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> res;
        if (a.empty()) return res;
        
        // 按照区间左端点排序
        sort(a.begin(), a.end());
        int l = a[0][0], r = a[0][1];
        for (int i = 1; i < a.size(); i ++) {
            if (a[i][0] > r) {
                res.push_back({l, r});
                l = a[i][0], r = a[i][1];
            }
            else
                r = max(r, a[i][1]);
        }

        res.push_back({l, r});

        return res;
    }
};