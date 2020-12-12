class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> points; // 所有的点
        multiset<int> heights; // 所有的高度
        // 枚举所有建筑物的点
        for (auto& b: buildings) {
            // 加入左端点，其中高度用负数
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }
        // 将加入的所有点pair排序
        sort(points.begin(), points.end());

        // 由于题目中最后的x轴的点算入了答案中，所以可以认为x轴这个也是一个楼
        // 所以这里把x轴也加入到高度里面，也就是在高度的multiset里加入0
        heights.insert(0);
        // 从前往后枚举所有的点
        for (auto& p: points) {
            // 拿到这个点的横坐标和高度
            int x = p.first, h = abs(p.second);
            // 如果是左端点
            if (p.second < 0) {
                // 如果当前点的高度是高度集合里的最大值
                if (h > *heights.rbegin())
                    res.push_back({x, h}); // 就把这个点加入到答案里面
                // 将当前这个楼房的高度加入到高度里面
                heights.insert(h);
            }
            else { // 如果是右端点
                // 将当前这个楼房的高度删除掉
                heights.erase(heights.find(h)); // 这里要用find才能在multiset里只删除一个，如果直接删会把所有等于h的都删除
                // 如果删除的这个高度h是大于剩下所有数的最大值的
                if (h > *heights.rbegin())
                    res.push_back({x, *heights.rbegin()}); // 说明这个右端点下面有一个伪的左端点，把它加入到答案里
            }
        }
        return res;
    }
};