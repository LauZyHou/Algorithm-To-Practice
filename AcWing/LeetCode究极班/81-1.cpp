class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int R = nums.size() - 1;
        while (R >= 0 && nums[R] == nums[0]) R --;
        if (R < 0) return nums[0] == target;
        // 至此就转化成了题I，先二分找分界点，再二分找答案
        int l = 0, r = R;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) 
                l = mid;
            else
                r = mid - 1;
        }
        // 根据target和nums[0]的关系知道在哪边找
        if (target >= nums[0])
            r = l, l = 0;
        else
            l ++, r = R; // 因为这里l++了，可能不在范围里，所以下面二分结束用r
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return nums[r] == target;
    }
};