class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        // 从第3位开始产生到s串里，k记录当前产生的是1还是2
        for (int i = 2, k = 1; s.size() < n; i ++ , k = 3 - k) {
            for (int j = 0; j < s[i] - '0'; j ++ )
                s += to_string(k);
        }
        // 统计一下1出现的个数
        int res = 0;
        for (int i = 0; i < n; i ++ ) res += (s[i] == '1');
        return res;
    }
};