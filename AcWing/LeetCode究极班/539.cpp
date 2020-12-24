class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;
        vector<int> q;
        for (auto& t: timePoints) {
            int h, m; // 小时和分钟
            sscanf(t.c_str(), "%d:%d", &h, &m); // 注意这个用法
            q.push_back(60 * h + m);
        }
        sort(q.begin(), q.end());
        // 从小到达枚举不跨天的时间间隔
        for (int i = 1; i < q.size(); i ++ ) res = min(res, q[i] - q[i - 1]);
        // 再计算一下最后一个时刻和第一个时刻的间隔
        res = min(res, 24 * 60 - q.back() + q[0]);
        return res;
    }
};