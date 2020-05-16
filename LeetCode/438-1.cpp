class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int slen = s.size();
        int plen = p.size();
        if(!slen || !plen)
            return ans;
        
        int left = 0;
        int right = 0;
        unordered_map<char,int> window;
        unordered_map<char,int> need;
        for(char c:p)
            need[c]++;
        int needlen = need.size();
        int valid = 0;

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
            while(needlen==valid) {
                if(right-left == plen)
                    ans.push_back(left);
                char d = s[left];
                left++;
                if(window.count(d)) {
                    window[d]--;
                    if(window[d] < need[d])
                        valid--;
                }
            }
        }
        return ans;
    }
};