class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        // 枚举中心点
        for (int i = 0; i < s.size(); i ++) {
            // 奇数的
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) // 枚举中心点
                l--, r ++;
            int n = (r - 1) - (l + 1) + 1; // 当前回文字符串长度
            if (res.size() < n)
                res = s.substr(l + 1, n);
            
            // 偶数的
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r])
                l--, r ++;
            n = (r - 1) - (l + 1) + 1;
            if (res.size() < n)
                res = s.substr(l + 1, n);
        }
        return res;
    }
};