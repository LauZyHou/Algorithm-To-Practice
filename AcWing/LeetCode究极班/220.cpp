class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        typedef long long LL;
        multiset<LL> S;
        // 为了保证一定能找到，加入正无穷和负无穷，这样就不用特殊处理了
        S.insert(1e18), S.insert(-1e18);
        // 遍历数组，i表示右侧的指针，j表示左侧的指针
        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            // 如果当前右侧指针的移动已经让区间里的数字的数量超出k了
            if (i - j > k)
                S.erase(S.find(nums[j ++ ])); // 那么就滑出去一个nums[j]
            // 当前滑进来的nums[i]
            int x = nums[i];
            // 在滑动窗口里求一下大于等于x的最小值
            auto it = S.lower_bound(x);
            // 判断大于等于x的最小值和x的差值是不是满足要求的
            if (*it - x <= t) return true;
            // 判断小于x的最大值和x的差值是不是满足要求的
            it --;
            if (x - *it <= t) return true;
            // 将这轮遇到的nums[i]滑入窗口
            S.insert(x);
        }
        return false;
    }
};