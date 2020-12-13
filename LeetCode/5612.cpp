class Solution {
public:
    int n; // 总个数
    vector<int> s; // 前缀和数组
    
    // 计算把(l, r]区间里的货物运出去所花费的段数
    int cost(int l, int r) {
        // 如果左端点l + 1是起始点的话，那么段数是分界点数
        if (s[l + 1] != s[l])
            return s[r] - s[l];
        // 如果左端点不是分界点的话，那么段数就是分界点数+1
        return s[r] - s[l] + 1;
    }

    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        n = boxes.size();
        s.resize(n + 2);
        // 求前缀和数组
        for (int i = 1; i <= n; i ++ ) {
            s[i] = s[i - 1];
            // 这里要看一下i是不是分界点，每到分界点就+1
            if (i == 1 || boxes[i - 1][0] != boxes[i - 2][0])
                s[i] ++ ;
        }

        // dp的数组
        vector<int> f(n + 1);
        // 双端队列
        deque<int> q;
        q.push_back(0);
        // 从前往后遍历每个位置i
        // j是满足约束能装填货物的最靠前的位置（j-1到i就不能装进去了）
        // w是当前货物的总重量
        for (int i = 1, j = 1, w = 0; i <= n; i ++ ) {
            // 把第i个箱子的重量加进来
            w += boxes[i - 1][1];
            // 因为i往前移动了，如果不满足约束就一直把j往前移动，前面的货物滑动出去
            while (w > maxWeight || i - j + 1 > maxBoxes) {
                w -= boxes[j - 1][1];
                j ++ ;
            }
            // 同时在队列里把滑出队列的删除掉
            while (q.front() < j - 1)
                q.pop_front();
            // 当前的k
            int k = q.front();
            // dp计算，注意要加上回程时候的1
            f[i] = f[k] + cost(k, i) + 1;
            // 单调队列优化，当队尾比队头还差的时候就不停删除队尾
            while (
            q.size() &&
            f[q.back()] >= f[i] + cost(i, i + 1) - cost(q.back(), i + 1)
                  )
                q.pop_back();
            // 将当前的i入队
            q.push_back(i);
        }
        return f[n];
    }
};