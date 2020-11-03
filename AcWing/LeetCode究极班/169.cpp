class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a = nums[0], n = 1;
        for (int i = 1; i < nums.size(); i ++ )
            if (nums[i] == a)
                n ++;
            else {
                n --;
                if (n < 0) {
                    a = nums[i];
                    n = 1;
                }
            }
        return a;
    }
};