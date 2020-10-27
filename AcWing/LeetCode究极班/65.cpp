class Solution {
public:
    bool isNumber(string s) {
        // 检查并去掉去掉左右空格
        int l = 0, r = s.size() - 1;
        while (l <= r && s[l] == ' ') l ++;
        while (l <= r && s[r] == ' ') r --;
        if (l > r) return false;
        s = s.substr(l, r - l + 1);
        // 检查并去掉开头的正负号
        if (s[0] == '+' || s[0] == '-') s = s.substr(1);
        // 如果只有正负号那么就不行
        if (s.empty()) return false;

        // 如果是'.'开头的，不能是仅一个'.'，或者'.e'或'.E'这种
        if (s[0] == '.' && (s.size() == 1 || s[1] == 'e' || s[1] == 'E'))
            return false;
        
        // 计数'.'和'e'/'E'的数量，它们都只能有一次
        int dot = 0, e = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '.') {
                // '.'只能有一次，'e'/'E'不能在'.'前面，负数时'.'不能在结尾
                if (dot > 0 || e > 0)
                    return false;
                dot ++;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                // 'e'/'E'不能在开头，不能在结尾，不能出现多次
                if (!i || i + 1 == s.size() || e > 0)
                    return false;
                // 'e'/'E'后面如果跟着'+'/'-'号，后面不能是空的
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    if (i + 2 == s.size())
                        return false;
                    // '+'/'-'号跳过
                    i ++;
                }
                e ++;
            }
            // 其它的只能是数字，不是数字就不行
            else if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }

        return true;
    }
};