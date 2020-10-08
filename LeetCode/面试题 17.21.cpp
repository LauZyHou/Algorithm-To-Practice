class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (!len)
            return 0;
        int l = 0;
        int r = len - 1;
        int lmax = height[l];
        int rmax = height[r];
        int ans = 0;
        while (l < r) {
            if (lmax > rmax) {
                ans += rmax - height[r];
                r --;
                rmax = max(rmax, height[r]);
            }
            else {
                ans += lmax - height[l];
                l ++;
                lmax = max(lmax, height[l]);
            }
        }
        return ans;
    }
};