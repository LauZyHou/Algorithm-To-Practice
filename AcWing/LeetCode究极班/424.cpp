class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int res = 0;
        for (char c = 'A'; c <= 'Z'; c ++ ) {
            // 双指针，cnt维护当前窗口里面c出现的次数
            for (int i = 0, j = 0, cnt = 0; i < n; i ++ ) {
                // 每次判断新加入的字符
                if (s[i] == c) cnt ++ ;
                // 当窗口里其它字符出现次数超过k的时候，就要一直移动j指针，同时维护出现次数
                while (i - j + 1 - cnt > k) {
                    if (s[j] == c) cnt -- ;
                    j ++ ;
                }
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};