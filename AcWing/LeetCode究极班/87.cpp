class Solution {
public:
    bool isScramble(string s1, string s2) {
        // 递归出口
        if (s1 == s2) return true;
        // 判断字符数量一不一样，不一样直接就false了
        if (s1.size() != s2.size()) return false;
        unordered_map<char, int> mp;
        for (char c : s1) mp[c] ++;
        for (char c : s2) mp[c] --;
        for (auto& item : mp)
            if (item.second)
                return false;
        // 枚举每个分解位置，i是左半部分的字符数量
        int n = s1.size();
        for (int i = 1; i <= n - 1; i ++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i)))
                return true;
        }
        return false;
    }
};