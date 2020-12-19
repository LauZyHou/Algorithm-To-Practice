class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        for (int i = 0; i <= n - m * k; i ++ ) {
            int j;
            for (j = 0; j < m * k; j ++ ) {
                if (arr[i + j % m] != arr[i + j])
                    break;
            }
            if (j == m * k)
                return true;
        }
        return false;
    }
};