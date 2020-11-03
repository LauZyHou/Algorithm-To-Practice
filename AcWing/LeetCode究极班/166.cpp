class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        typedef long long LL;
        LL x = numerator, y = denominator;
        // 如果是整数直接返回这个整数就可以了
        if (x % y == 0) return to_string(x / y);
        string res;
        // 判断是负数
        if ((x < 0) ^ (y < 0)) res += '-';
        x = abs(x), y = abs(y);
        // 整数部分
        res += to_string(x / y) + '.', x %= y;
        // 如果余数是0就除尽了
        // 用一个哈希表记录所有出现过的余数
        unordered_map<LL, int> hash;
        while (x) {
            // 计算这一位的效数和余数    
            x *= 10;
            res += to_string(x / y);
            x %= y;
            // 如果余数已经出现过就不用算了
            if (hash.count(x)) {
                string left = res.substr(0, hash[x]);
                string right = res.substr(hash[x]);
                res = left + '(' + right + ')';
                break;
            }
            // 记录一下余数对应的应该是res里的第几位
            hash[x] = res.size();
        }
        return res;
    }
};