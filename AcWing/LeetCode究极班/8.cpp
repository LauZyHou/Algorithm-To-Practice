class Solution {
public:
    int myAtoi(string s) {
        // 去掉头空格
        int k = 0;
        while (k < s.size() && s[k] == ' ')
            k ++;
        if (k == s.size())
            return 0;
        int res = 0;
        int minus = 1;
        if (s[k] == '-')
            minus = -1, k ++;
        else if (s[k] == '+')
            k ++;
        while (k < s.size() && s[k] <= '9' && s[k] >= '0') {
            int x = s[k] - '0';
            if (minus > 0 && res > (INT_MAX - x) / 10)
                return INT_MAX;
            if (minus < 0 && -res < (INT_MIN + x) / 10)
                return INT_MIN;
            // 因为INT_MIN比INT_MAX多一个1，所以这个数正数存不下，要特判一下
            if (minus < 0 && -res * 10 - x == INT_MIN)
                return INT_MIN;
            res = res * 10 + x;
            k ++;
        }
        return minus * res;
    }
};