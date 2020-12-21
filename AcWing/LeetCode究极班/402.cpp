class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k > num.size()) return "0";
        string res;
        for (auto c: num) {
            // 当还可以删的时候，并且比答案里的最后一位要小，那就把它删除掉
            while (k && res.size() && res.back() > c) {
                k -- ;
                res.pop_back();
            }
            res += c;
        }
        // 如果还没删完，就从后往前删
        while (k -- ) res.pop_back();
        // 去除前导0
        k = 0;
        while (k < res.size() && res[k] == '0') k ++ ;
        res = res.substr(k);
        if (res.empty()) return "0";
        return res;
    }
};