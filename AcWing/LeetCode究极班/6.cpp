class Solution {
public:
    string convert(string s, int n) {
        // 特判n=1时公差是0防止死循环，n=1时原来的就是结果
        if (n == 1)
            return s;
        string res;
        for (int i = 0; i < n; i ++) {
            if (i == 0 || i == n - 1) {
                for (int j = i; j < s.size(); j += 2 * n - 2)
                    res += s[j];
            }
            else {
                for (int j = i, k = 2 * n - 2 - i; j < s.size() || k < s.size(); j += 2 *n - 2, k += 2 * n - 2) {
                    if (j < s.size())
                        res += s[j];
                    if (k < s.size())
                        res += s[k];
                }
            }
        }
        return res;
    }
};