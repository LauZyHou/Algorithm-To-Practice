class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n);
        if (k == 0) return res;
        for (int i = 0; i < n; i ++ ) {
            if (k > 0) {
                for (int j = 1; j <= k; j ++ ) {
                    res[i] += code[(i + j) % n];
                }
            }
            else {
                for (int j = 1; j <= abs(k); j ++ ) {
                    res[i] += code[(i - j + n) % n];
                }
            }
        }
        return res;
    }
};