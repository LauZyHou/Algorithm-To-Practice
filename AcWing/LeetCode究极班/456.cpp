class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int right = INT_MIN; // 满足要求的ak最大值
        // 从后往前枚举ai，同时也是作为aj的一种选择
        for (int i = nums.size() - 1; i >= 0; i -- ) {
            // 作为ai时，判断当前最大的满足要求的ak是不是也满足ai<ak
            if (nums[i] < right) return true;
            // 作为aj时，要去更新满足ak<aj要求的最大ak
            while (stk.size() && stk.top() < nums[i]) {
                right = max(right, stk.top()); // 更新ak
                stk.pop(); // 从单调栈里删除
            }
            // 当前的数要加入到单调栈里
            stk.push(nums[i]);
        }
        return false;
    }
};