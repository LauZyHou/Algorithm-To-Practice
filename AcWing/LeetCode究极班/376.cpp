class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // 删除所有连续的重复元素
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        if (nums.size() <= 2) return nums.size();
        // 先将首尾元素选上
        int res = 2;
        for (int i = 1; i + 1 < nums.size(); i ++ ) {
            int a = nums[i - 1], b = nums[i], c = nums[i + 1]; // 前一个、当前和后一个元素
            if (b > a && b > c || b < a && b < c) res ++ ;
        }
        return res;
    }
};