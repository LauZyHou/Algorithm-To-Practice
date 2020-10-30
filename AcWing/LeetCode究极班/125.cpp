class Solution {
public:
    bool check(char c) {
        return c >= 'a' && c <='z' || c >= '0' && c <= '9' || c >= 'A' && c <= 'Z';
    }

    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i ++ , j --) {
            while (i < j && !check(s[i])) i ++;
            while (i < j && !check(s[j])) j --;
            if (i < j && tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;
    }
};