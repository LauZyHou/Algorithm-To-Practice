class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 找>=target的最小位置，当所有元素都比target小时，要在最后插入，所以r从len位置而不是len-1位置
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};