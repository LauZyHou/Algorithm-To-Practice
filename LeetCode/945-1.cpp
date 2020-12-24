class Solution {
public:
    int minIncrementForUnique(vector<int>& a) {
        sort(a.begin(), a.end());
        int res = 0;
        int mx = INT_MIN;
        for (auto& x: a) {
            if (x <= mx) {
                res += mx + 1 - x;
                x = mx + 1;
            }
            mx = max(mx, x);
        }
        return res;
    }
};