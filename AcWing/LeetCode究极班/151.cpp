class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int k = 0; // 写入的开始位置
        for (int i = 0; i < n; i ++ ) {
            if (s[i] == ' ')
                continue;
            int t = k; // 写入位置
            int j = i; // 读取位置
            while (j < n && s[j] != ' ')
                s[t ++] = s[j ++];
            reverse(s.begin() + k, s.begin() + t);
            s[t ++] = ' ';
            k = t; // 更新写入的开头位置
            i = j; // 更新读取的开头位置
        }
        // 只要不是空串，那么末尾就会多一个空格
        if (k) k --;
        s.erase(s.begin() + k, s.end());
        // 翻转整个字符串
        reverse(s.begin(), s.end());
        return s;
    }
};