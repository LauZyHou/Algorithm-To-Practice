class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 记录双指针移动过程中字符出现次数
        unordered_map<char, int> hash;
        int res = 0;
        // 双指针，i在j后面
        for (int i = 0, j = 0; i < s.size(); i ++) {
            hash[s[i]] ++;
            while (hash[s[i]] > 1) // 因为只有i后移了，所以有重复一定是s[i]的重复
                hash[s[j]] --, j ++;
            res = max(res, i - j + 1);
        }
        return res;
    }
};