class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        // 存一下匹配完每个s1之后是匹配了s2的多少个字符
        // 这里不对s2.size()取模，是为了能计算一共匹配到了s2的哪个位置
        vector<int> cnt;
        // 哈希表快速判断余数有没有出现过
        unordered_map<int, int> hash;
        // i枚举匹配每个s1，k是在s2里转的指针
        for (int i = 0, k = 0; i < n1; i ++ ) {
            // j枚举s1的每个字符
            for (int j = 0; j < s1.size(); j ++ )
                if (s1[j] == s2[k % s2.size()]) // 如果匹配上了
                     k ++ ; // 在s2里匹配的指针就往后走
            cnt.push_back(k); // 每次匹配完一个s1，就把s2的指针位置k存下来
            // 如果余数k对应的指针位置之前已经出现过了，就说明出现循环节了
            if (hash.count(k % s2.size())) {
                // 计算一下循环节里一共有多少个s1，也就是当前和上次是第几个s1之间的差
                int a = i - hash[k % s2.size()];
                // 计算一下循环节里能匹配多少个s2中的字符
                int b = k - cnt[hash[k % s2.size()]];
                // 还剩多少个循环节=后面剩下的s1的个数/循环节里的s1的个数
                // 剩下的循环节个数还要乘以每个循环节能匹配的s2中的字符数，就是剩下的循环节能匹配s2中的字符数
                int res = (n1 - i - 1) / a * b;
                // 还要把最后不完整的循环节模拟一遍，找出它能匹配多少字符
                // 先遍历不完整循环节的s1个数
                for (int u = 0; u < (n1 - i - 1) % a; u ++ )
                    // 再遍历每个s1
                    for (int j = 0; j < s1.size(); j ++ )
                        // 如果能和s2当前位置匹配
                        if (s1[j] == s2[k % s2.size()])
                            k ++ ;
                res += k; // 答案加上k，这里k既包含循环节出现之前匹配的字符，也包含最后的不完整的循环节
                // 返回的是匹配的字符数 除以 s2长度 除以n2，也就是能匹配的大S2的数量
                return res / s2.size() / n2;
            }
            // 如果没有出现循环节，标记s2的余数位置k对应的是循环节的第几个s1
            // 这里也是要取余，不然没法判断出现循环节（判断是s2的同一位置）
            hash[k % s2.size()] = i;
        }
        // 没有出现循环节
        // 如果一个字符都匹配不了，那么cnt是空的，直接返回0
        if (cnt.empty()) return 0;
        // 返回最后匹配了s2多少个字符，除以s2的长度就是匹配了多少个s2
        // 再除以n2就是匹配了多少个大S2
        return cnt.back() / s2.size() / n2;
    }
};