class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n + 2);
        for (auto& x: nums) {
            s[min(n, x)] ++ ;
        }
        for (int i = n; i; i -- ) {
            s[i] += s[i + 1];
            if (s[i] == i)
                return i;
        }
        return -1;
    }
};