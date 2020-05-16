class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int slen = s.size();
        if(!slen)
            return 0;
        int left = 0;
        int right = 0;
        unordered_map<char,int> window;

        int ans = 0;

        while(right < slen) {
            // 右扩
            char c = s[right];
            right++;
            window[c]++;
            // 左缩
            while(window[c] > 1) {
                char d = s[left];
                left++;
                window[d]--;
            }
            ans = max(ans, right-left);
        }
        return ans;
    }
};