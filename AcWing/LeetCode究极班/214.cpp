class Solution {
public:
    string shortestPalindrome(string s) {
        string t(s.rbegin(), s.rend());
        int n = s.size();
        s = ' ' + s + '#' + t;
        vector<int> ne(n * 2 + 2);
        // kmp求next数组模板
        for (int i = 2, j = 0; i <= n * 2 + 1; i ++ ) {
            while (j && s[i] != s[j + 1]) j = ne[j];
            if (s[i] == s[j + 1]) j ++ ;
            ne[i] = j;
        }

        // 构造题目要求的串
        int len = ne[n * 2 + 1];
        string left = s.substr(1, len);
        string right = s.substr(len + 1, n - len);
        return string(right.rbegin(), right.rend()) + left + right;
    }
};