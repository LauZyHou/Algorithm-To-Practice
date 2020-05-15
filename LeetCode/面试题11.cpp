class Solution {
public:
    int minArray(vector<int>& v) {
        if(v.empty())
            return 0;
        int l = 0;
        int r = v.size() - 1;
        while(l < r) {
            int m = (l+r)/2;
            if(v[m] < v[r]) {
                r = m;
            }
            else if(v[m] > v[r]) {
                l = m + 1;
            }
            else {
                r--;
            }
        }
        return v[l];
    }
};