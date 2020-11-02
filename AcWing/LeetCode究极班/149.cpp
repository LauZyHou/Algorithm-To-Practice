class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        typedef long double LD;
        int res = 0;
        for (auto& p: points) {
            int ss = 0, vs = 0; // 重叠的点数、垂直的点数
            unordered_map<LD, int> hash; // 每个斜率的点的数量
            for (auto& q: points) {
                if (p == q) // vector里存简单类型，可以直接用==比较值是不是都相等
                    ss ++;
                else if (p[0] == q[0])
                    vs ++;
                else {
                    LD k = (LD)(p[1] - q[1]) / (p[0] - q[0]);
                    hash[k] ++;
                }
            }
            // 计算以p点为中心点的最多的共线的点的数量
            // 先不加重叠的点，最后再统一加上
            int cnt = vs;
            for (auto& [k, c]: hash)
                cnt = max(cnt, c);
            res = max(res, cnt + ss);
        }
        return res;
    }
};