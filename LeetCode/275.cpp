class Solution {
public:
    int hIndex(vector<int>& v) {
        int n = v.size();
        for (int i = 0; i < n; i ++ ) {
            if (v[i] >= n - i)
                return n - i;
        }
        return 0;
    }
};