class Solution {
public:
    int titleToNumber(string s) {
        long long res = 0;
        for (char c : s) {
            res = res * 26 + c - 'A' + 1;
        }
        return res;
    }
};