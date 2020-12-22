class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& q) {
        int n = q.size();
        // 因为要求的答案是区间原来所在位置的下标，所以排序了也要保持下标信息，这里直接把下标加入到每个区间元素里
        for (int i = 0; i < n; i ++ ) q[i].emplace_back(i);
        // 将所有的区间按照左端点排序
        sort(q.begin(), q.end());
        vector<int> res(n, -1);
        for (auto& x: q) {
            // 二分寻找比x[1]大的最靠左的一个区间
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (q[mid][0] >= x[1]) r = mid;
                else l = mid + 1;
            }
            if (q[r][0] >= x[1]) res[x[2]] = q[r][2];
        }
        return res;
    }
};