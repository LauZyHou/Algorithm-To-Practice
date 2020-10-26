class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;

        // 先二分分界点
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0])
                l = mid;
            else 
                r = mid - 1;
        }

        // 再根据target和nums[0]的关系看它在哪个区间
        if (target >= nums[0])
            l = 0;
        else
            l = r + 1, r = nums.size() - 1;
        
        // 然后在这个单调区间里找target
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }

        if (nums[r] == target)
            return r;
        return -1;
    }
};