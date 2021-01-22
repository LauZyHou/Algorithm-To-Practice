class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& r) {
        // 存每个点出现的次数
        map<pair<int, int>, int> cnt;
        typedef long long LL;
        // 小矩形的面积和
        LL sum = 0;
        for (auto &x : r) {
            // 左上角是(a, b)右下角是(c, d)
            int a = x[0], b = x[1], c = x[2], d = x[3];
            ++ cnt[{a, b}], ++ cnt[{a, d}], ++ cnt[{c, b}], ++ cnt[{c, d}];
            // 计算总面积，可能爆int所以用long long来存
            sum += (LL)(c - a) * (d - b);
        }
        // 计算一下每个点出现的次数，记录一下只出现一次的点
        vector<vector<int>> ones;
        for (auto &[p, c]: cnt)
            if (c == 1) ones.push_back({p.first, p.second});
            else if (c == 3) return false; // 如果有点出现三次就不是
        // 出现一次的点必须是四个
        if (ones.size() != 4) return false;
        sort(ones.begin(), ones.end());
        LL sum2 = (LL)(ones[3][1] - ones[0][1]) * (ones[3][0] - ones[0][0]);
        return sum == sum2;
    }
};