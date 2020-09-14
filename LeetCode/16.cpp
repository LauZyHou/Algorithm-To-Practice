class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n<3)
            return 0;
        int less = INT_MAX;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i=0;i<n-2;i++) {
            int j = i+1;
            int k = n-1;
            while(j < k) {
                int val = abs(nums[i]+nums[j]+nums[k]-target);
                if(val == 0)
                    return target;
                if(val < less) {
                    less = val;
                    ans = nums[i]+nums[j]+nums[k];
                }
                if(nums[i]+nums[j]+nums[k] > target)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};