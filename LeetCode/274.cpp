class Solution {
public:
    int hIndex(vector<int>& v) {
        sort(v.begin(), v.end(), greater<int>());
        int n = v.size();
        int i;
        for (i = 0; i < n; i ++ ) {
            if (v[i] < i + 1)
                break;
        }
        return i;
    }
};