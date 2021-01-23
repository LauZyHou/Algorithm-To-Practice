class Solution {
public:
    // 为了方便用结构体来存每个点
    struct Cell {
        int h, x, y;
        // 由于要放到堆里所以这里要重载一下小于号
        bool operator< (const Cell& t) const {
            // 默认是大根堆，这里要用小根堆所以要变一下符号
            return h > t.h;
        }
    };
    
    int trapRainWater(vector<vector<int>>& h) {
        if (h.empty() || h[0].empty()) return 0;
        int n = h.size(), m = h[0].size();
        // 小根堆
        priority_queue<Cell> heap;
        // 为了避免格子被重复搜索，这里用一个判重的数组
        vector<vector<bool>> st(n, vector<bool>(m));
        // 初始化，只放边界
        for (int i = 0; i < n; i ++ ) { // 左右两列
            st[i][0] = st[i][m - 1] = true;
            heap.push({h[i][0], i, 0});
            heap.push({h[i][m - 1], i, m - 1});
        }
        for (int j = 1; j + 1 < m; j ++ ) { // 上下两行，注意不要重复放
            st[0][j] = st[n - 1][j] = true;
            heap.push({h[0][j], 0, j});
            heap.push({h[n - 1][j], n - 1, j});
        }
        // 总共能接下的雨水数量
        int res = 0;
        // 四个方向
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        // 只要堆里有元素，就是有还没记录完高度的
        while (heap.size()) {
            // 每次取出堆顶元素，也就是接完水高度最小的一个
            auto t = heap.top();
            heap.pop();
            // 答案加上一个它的最终高度和初始高度的差
            res += t.h - h[t.x][t.y];
            // 枚举四个方向的相邻点
            for (int i = 0; i < 4; i ++ ) {
                int x = t.x + dx[i], y = t.y + dy[i];
                // 在范围内，而且没计算过
                if (x >= 0 && x < n && y >= 0 && y < m && !st[x][y]) {
                    heap.push({
                        max(h[x][y], t.h),
                        x,
                        y
                    });
                    // 标记一下计算了
                    st[x][y] = true;
                }
            }
        }

        return res;
    }
};