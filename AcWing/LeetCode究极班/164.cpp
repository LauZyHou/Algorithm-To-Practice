class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // 定义区间，每个区间只要存最小值和最大值，还要记录区间有没有被用
        struct Range {
            int min, max;
            bool used;
            Range() : min(INT_MAX), max(INT_MIN), used(false) {}
        };
        int n = nums.size();
        // 计算nums里最小和最大的数
        int Min = INT_MAX, Max = INT_MIN;
        for (auto v: nums) {
            Min = min(Min, v);
            Max = max(Max, v);
        }
        // 如果只有一个数或者所有数都一样，就之间返回0
        if (n < 2 || Min == Max)
            return 0;
        // 定义所有的区间，Min不用存，极端情况就是其它数每个数独占一个区间
        vector<Range> r(n - 1);
        // 计算区间的长度（分析里的x）
        int len = (Max - Min + n - 2) / (n - 1);
        // 对每个数存到区间里
        for (auto v: nums) {
            if (v == Min)
                continue;
            // 计算数v所在区间的下标
            int k = (v - Min - 1) / len;
            // 更新一下这个区间的记录
            r[k].used = true;
            r[k].min = min(r[k].min, v);
            r[k].max = max(r[k].max, v);
        }
        // 扫描一下每个区间，其最小值和上一个区间的最大值做差
        // last记录上一个区间的最大值
        int res = 0;
        for (int i = 0, last = Min; i < n - 1; i ++ ) {
            if (r[i].used) {
                res = max(res, r[i].min - last);
                last = r[i].max;
            }
        }
        return res;
    }
};