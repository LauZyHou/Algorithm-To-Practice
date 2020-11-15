class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int val = 0;
        int i = n - 1;
        while (i >= 0 && val < x) {
            val += nums[i];
            i --;
        }
        if (i == -1)
            return val == x ? n : -1;
        i ++;
        int j = n;
        int res = INT_MAX;
        if (val == x)
            res = n - i;
        while (j < n * 2 && i <= n) {  
            if (val > x)
                val -= nums[i % n], i ++;
            else if (val < x)
                val += nums[j % n], j ++;
            // cout << i << ',' << j << endl;
            if (val == x) {
                val += nums[j % n], j ++;
                res = min(res, j - i - 1);
                // cout << i << '|' << j << endl;
            }
                
        }
        return res == INT_MAX ? -1 : res;
    }
};