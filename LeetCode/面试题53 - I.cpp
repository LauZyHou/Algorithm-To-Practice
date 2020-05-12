class Solution {
public:
    int search(vector<int>& nums, int t) {
        int len = nums.size();
        int l = 0;
        int r = len-1;
        while(l < r) {
            int m = (l+r)/2;
            if(nums[m]<t) {
                l = m+1;
            }
            else if(nums[m]>t) {
                r = m-1;
            }
            else { // ==
                r = m;
            }
        }
        int ans = 0;
        while(l<len && nums[l++]==t)
            ans++;
        return ans;
    }
};