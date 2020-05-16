class Solution {
public:
    string minWindow(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        if(!slen || !tlen)
            return "";

        int left = 0;
        int right = 0;
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        for(char c:t)
            need[c]++;
        int valid = 0; // 满足need的字符数
        int needlen = need.size(); // need中的不同字符数

        int ans_left = 0;
        int ans_right = INT_MAX;

        while(right < slen) {
            // 右扩
            char c = s[right];
            right++;
            if(need.count(c)) {
                window[c]++;
                if(window[c]==need[c])
                    valid++;
            }

            // 左缩
            while(valid == needlen) {
                // 判断结果
                if(right-left < ans_right-ans_left) {
                    ans_left = left;
                    ans_right = right;
                }

                char d = s[left];
                left++;
                if(window.count(d)) {
                    window[d]--;
                    if(window[d] < need[d])
                        valid--;
                }
            }
        }

        return ans_right==INT_MAX ? "" : s.substr(ans_left, ans_right-ans_left);
    }
};