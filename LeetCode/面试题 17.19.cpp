class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        int sum = 0;
        for (int x : nums)
            sum += x;
        int twosum = (1 + n) * n / 2 - sum;
        int mid = twosum >> 1;
        // 两数不相等，一个>=mid，一个<=mid，计算小于mid的数
        int val = 0;
        for (int x : nums)
            if (x <= mid)
                val += x;
        int x1 = (1 + mid) * mid / 2 - val;
        return {x1, twosum - x1};
    }
};