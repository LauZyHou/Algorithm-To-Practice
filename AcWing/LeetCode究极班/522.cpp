class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int res = -1;
        // 判断每个字符串是不是其它字符串的子序列
        for (int i = 0; i < strs.size(); i ++ ) {
            bool is_sub = false;
            for (int j = 0; j < strs.size(); j ++ ) {
                if (i != j && check(strs[i], strs[j])) {
                    is_sub = true;
                    break;
                }
            }
            // 如果当前序列不是其它序列的子序列，那么就找到了一个满足要求的
            if (!is_sub) res = max(res, (int)strs[i].size());
        }
        return res;
    }

    // 判断a是否是b的子序列
    bool check(string& a, string& b) {
        // 用一个指针从a开始走，枚举b里的每一个字符
        int k = 0;
        for (auto c: b) {
            if (k < a.size() && c == a[k]) k ++ ;
        }
        return k == a.size();
    }
};