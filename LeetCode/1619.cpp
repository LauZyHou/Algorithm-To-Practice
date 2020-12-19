class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int d = n / 20;
        double res = 0;
        for (int i = d; i < n - d; i ++ )
            res += arr[i];
        return res / (n - (d << 1));
    }
};