class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(!len1 || !len2)
            return false;

        int left = 0;
        int right = 0;
        unordered_map<char,int> need;
        unordered_map<char,int> window;
        for(char c:s1)
            need[c]++;
        int needlen = need.size();
        int valid = 0;

        while(right < len2) {
            // 右扩
            char c = s2[right];
            right++;
            if(need.count(c)) {
                window[c]++;
                if(window[c]==need[c])
                    valid++;
            }

            // 左缩
            while(valid == needlen) {
                if(right-left == len1)
                    return true;
                char d = s2[left];
                left++;
                if(window.count(d)) {
                    window[d]--;
                    if(window[d] < need[d])
                        valid--; // (其实就是break)
                }
            }
        }
        return false;
    }
};