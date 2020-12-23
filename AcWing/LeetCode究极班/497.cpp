class Solution {
public:
    int n;
    vector<vector<int>> rects;
    vector<int> s; // 矩形面积的前缀和数组

    Solution(vector<vector<int>>& _rects) {
        rects = _rects;
        n = rects.size();
        // 计算前缀和
        s.push_back(0);
        for (auto& r: rects) {
            int dx = r[2] - r[0] + 1, dy = r[3] - r[1] + 1; // 从a到b应该是有b-a+1个点
            s.push_back(s.back() + dx * dy); // 加上前一个矩形的面积
        }
    }
    
    vector<int> pick() {
        int k = rand() % s.back() + 1; // 随机一个数出来，+1是能保证在[1, 面积总和]里面
        // 在前缀和数组里面二分找一下>=这个数的最小的一个下标，也就知道了它是落在哪个矩形里了
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (s[mid] >= k) r = mid;
            else l = mid + 1;
        }
        // 因为二分出来的是从1开始的，所以减少1就是矩形的下标
        auto& t = rects[r - 1];
        // 计算横纵坐标差，然后随机一个点出来
        int dx = t[2] - t[0] + 1, dy = t[3] - t[1] + 1;
        return {rand() % dx + t[0], rand() % dy + t[1]};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */