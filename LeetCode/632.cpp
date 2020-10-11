class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        // 存每个列表的当前数下标，nums[i][next[i]]即是i号列表的当前数
        // 初始时所有next[i]都=0
        vector<int> next(k, 0);

        // 比较u号列表的当前数和v号列表的当前数
        auto cmp = [&](const int &u, const int &v) {
            return nums[u][next[u]] > nums[v][next[v]]; // 最小堆用>号
        };
        // 最小堆
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        // 结果，即k个数中的最小最大值，目的要让这个区间最小
        int bestL = 0, bestR = INT_MAX;
        // 计算过程中的区间左右值（最小堆只要每次取堆顶，最大值要手动维护）
        int nowL, nowR = INT_MIN;

        // 建堆，存0~k-1一共k个列表号
        for (int i = 0; i < k; i ++) {
            pq.emplace(i);
            nowR = max(nowR, nums[i][next[i]]);
        }

        while (true) {
            int listId = pq.top(); // 当前数最小的列表id
            // 这里pop了也一定还要放回去，这个重放只是为了重新调整堆pq，不然光更新next[listId]没用
            pq.pop();
            // 当前数最小值即为当前区间左端点
            nowL = nums[listId][next[listId]];
            // 当前区间更优
            if (nowR - nowL < bestR - bestL) {
                bestL = nowL;
                bestR = nowR;
            }
            // 接下来要移动这个最小数的列表的当前指针
            // 如果会超出范围，那么就说明已经检查完了
            if (next[listId] == nums[listId].size() - 1) {
                break;
            }
            // 移动
            next[listId] ++;
            // 手动维护最大值
            nowR = max(nowR, nums[listId][next[listId]]);
            // 放回堆里
            pq.push(listId);
        }
        return {bestL, bestR};
    }
};