typedef vector<int> VI;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        if (a.empty() || b.empty()) return {};
        int n = a.size(), m = b.size();
        // 小根堆，用来做多路归并
        priority_queue<VI, vector<VI>, greater<VI>> heap;
        // 把m个求和序列的第一个数先加入到堆里
        for (int i = 0; i < m; i ++ ) heap.push({b[i] + a[0], 0, i}); // 第i个序列的第一个和，用的是a序列的第0个数和b序列的第i个数
        vector<VI> res;
        while (k -- && heap.size()) {
            // 每次取出堆顶元素
            auto t = heap.top();
            heap.pop();
            // 将这个拿出来的元素插入到答案里
            int ia = t[1], ib = t[2]; // t[1]是a的下标，t[2]是b的下标
            res.push_back({a[ia], b[ib]});
            // 当前就是第ib个序列中的第ia个数，序列里一共有n个数，如果序列里还有下一个数就把它加入到堆中
            if (ia + 1 < n) heap.push({b[ib] + a[ia + 1], ia + 1, ib});
        }
        return res;
    }
};