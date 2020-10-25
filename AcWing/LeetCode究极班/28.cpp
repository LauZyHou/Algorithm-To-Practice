class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        if (!m) return 0;
        // kmp让它从1开始
        s = ' ' + s, p = ' ' + p;
        // next[i]，p[1~i]中所有相等的前缀和后缀的长度的最大值

        // kmp求next数组
        vector<int> next(m + 1);
        for (int i = 2, j = 0; i <= m; i ++) {
            while (j && p[i] != p[j + 1]) j = next[j];
            if (p[i] == p[j + 1]) j ++;
            next[i] = j;
        }

        for (int i = 1, j = 0; i <= n; i ++) {
            while (j && s[i] != p[j + 1]) j = next[j];
            if (s[i] == p[j + 1]) j ++;
            // 此题匹配完成则返回起始位置
            if (j == m) return i - m;
        }

        return -1;
    }
};