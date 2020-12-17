class Solution {
public:
    string removeDuplicateLetters(string s) {
        string stk; // 答案字符串
        unordered_map<char, bool> ins; // 记录每个字母是不是在栈中出现过in stack
        unordered_map<char, int> last; // 记录每个字母最后一次出现的位置，用来判断当前字母是不是最后一次出现的
        // 先计算一下每个字母最后一次出现的位置
        for (int i = 0; i < s.size(); i ++ ) last[s[i]] = i;

        // 从前往后枚举每个字母
        for (int i = 0; i < s.size(); i ++ ) {
            auto c = s[i];
            // 如果当前字母已经在字符串里了，那就直接跳过
            if (ins[c]) continue;
            // 只要栈顶是比当前字母字典序大的，并且是可以删去的（不是最后一次出现），那么就把它删除掉
            while (stk.size() && stk.back() > c && last[stk.back()] > i) {
                // 删去的字母标记为在stk里不存在
                ins[stk.back()] = false;
                stk.pop_back();
            }
            stk += c;
            ins[c] = true;
        }

        return stk;
    }
};