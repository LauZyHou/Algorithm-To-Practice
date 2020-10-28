class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; // k-1及其之前的部分是已经有效的部分
        for (int i = 0; i < nums.size(); i ++) {
            if (k < 2 || nums[i] != nums[k - 1] || nums[i] != nums[k - 2])
                nums[k ++] = nums[i];
        }
        return k;
    }
};