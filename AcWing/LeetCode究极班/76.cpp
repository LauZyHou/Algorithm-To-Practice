class Solution {
public:
    string minWindow(string s, string t) {
        // hs：窗口里字符出现次数，ht：t里字符出现次数
        unordered_map<char, int> hs, ht;
        for (auto c : t) ht[c] ++;
        string res; // 答案
        int cnt = 0; // 判断哈希表hs覆盖哈希表ht
        // 滑动窗口
        for (int i = 0, j = 0; i < s.size(); i ++) {
            hs[s[i]] ++; // 记录这个字符出现
            // 如果确实为ht里的目标做贡献了，cnt里记录一下
            if (hs[s[i]] <= ht[s[i]])
                cnt ++;
            // 去掉开头多余的s[j]
            while (hs[s[j]] > ht[s[j]])
                hs[s[j]] --, j ++;
            // 至此，i和j都移动完毕，判断是不是有效的解
            if (cnt == t.size() && (res.empty() || i - j + 1 < res.size()))
                res = s.substr(j, i - j + 1);
        }
        return res;
    }
};