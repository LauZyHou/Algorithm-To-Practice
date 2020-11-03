class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if (nums[l] <= nums[r]) return nums[0]; // 这里用<=是考虑到只有一个元素的情况
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[0])
                r = mid;
            else 
                l = mid + 1;
        }
        return nums[l];
    }
};