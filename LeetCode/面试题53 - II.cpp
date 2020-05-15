class Solution {
public:
    int missingNumber(vector<int>& v) {
        int r = v.size() - 1;
        int l = 0;
        // 两端
        if(v[l] > l)
            return l;
        if(v[r] == r) {
            return r+1;
        }
        // 中间
        while(l < r) {
            int m = (l+r)>>1;
            if(v[m] > m) {
                r = m;
            }
            else { // ==
                l = m + 1;
            }
        }
        return l;
    }
};