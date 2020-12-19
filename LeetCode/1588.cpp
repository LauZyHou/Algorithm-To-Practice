class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        for (int i = 0; i < n; i ++ ) {
            // 左右两侧的偶数数量
            int l0 = i / 2 + 1, r0 = (n - i - 1) / 2 + 1;
            // 左右两侧的奇数数量
            int l1 = (i + 1) / 2, r1 = (n - i) / 2;
            res += arr[i] * (l0 * r0 + l1 * r1);
            // cout << i << '-' << l0 << ' ' << r0 << ' ' << l1 << ' ' << r1 << endl;
        }
        return res;
    }
};