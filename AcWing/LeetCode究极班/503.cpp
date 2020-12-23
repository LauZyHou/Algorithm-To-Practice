class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        // 单调栈，里面直接存nums数组的值（对于单调队列有的时候存的是下标，特别是滑动窗口要用下标判断有没有滑出去）
        stack<int> stk;
        vector<int> res(n);
        // 因为是要求后面的第一个满足要求的元素，所以从后往前枚举
        for (int i = n * 2 - 1; i >= 0; i -- ) {
            int x = nums[i];
            while (stk.size() && x >= stk.top()) // 因为要求是比x大，所以<=x的都弹出去
                stk.pop();
            // 只在i在原来数组的0~n-1范围里的时候记录答案
            if (i < n) {
                if (stk.empty()) res[i] = -1;
                else res[i] = stk.top();
            }
            stk.push(x);
        }
        return res;
    }
};