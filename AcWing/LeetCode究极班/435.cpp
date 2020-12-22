class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& q) {
        // 按照区间右端点进行排序
        sort(q.begin(), q.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        if (q.empty()) return 0;
        int res = 1, r = q[0][1]; // res记录能选的不重复区间的数量，r记录上一个选择的区间的右端点
        for (int i = 1; i < q.size(); i ++ ) {
            if (q[i][0] >= r) {
                res ++ ;
                r = q[i][1];
            }
        }
        return q.size() - res;
    }
};