class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int a[2];
        a[0] = a[1] = 0;
        for (int i = 1; i < nums.size(); i ++ )
            a[i & 1] += nums[i];
        int res = 0;
        if (a[0] == a[1]) res ++ ;
        for (int i = 1; i < nums.size(); i ++ ) {
            a[i & 1] -= nums[i];
            a[i & 1] += nums[i - 1];
            if (a[0] == a[1]) res ++ ;
        }
        return res;
    }
};