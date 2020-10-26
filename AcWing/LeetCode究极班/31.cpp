class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 从后往前找到要变动的位置k-1
        int k = nums.size() - 1;
        while (k > 0 && nums[k - 1] >= nums[k])
            k --;
        // 至此，nums[k] > nums[k - 1]
        if (k == 0) // 这样说明完全是一个从大到小的数组，下一个就轮回到字典序的第一个（从小到大）
            reverse(nums.begin(), nums.end());
        else {
            // 接下来要在后面找一个刚好>nums[k - 1]的位置t，和这里交换
            int t = nums.size() - 1;
            while (t > 0 && nums[t] <= nums[k - 1]) // 只要不是大于就一直往左
                t --;
            swap(nums[t], nums[k - 1]);
            // 交换好了之后，后面的部分要变成升序，现在一定还是降序，所以直接reverse
            reverse(nums.begin() + k, nums.end());
        }
    }
};