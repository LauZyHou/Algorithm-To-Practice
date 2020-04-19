class Solution {
public:
    int cal(vector<int>& nums, int a, int b) {
        int dpi = nums[a];
        int dpj = max(nums[a+1], nums[a]);
        for(int k=a+2 ; k<=b ; k++) {
            int val = max(dpj, dpi+nums[k]);
            dpi = dpj;
            dpj = val;
        }
        return dpj;
    }

    int rob(vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return 0;
        if(len==1)
            return nums[0];
        if(len==2)
            return max(nums[0], nums[1]);
        return max(cal(nums, 0, len-2), cal(nums, 1, len-1));
    }
};