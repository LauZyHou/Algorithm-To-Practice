class Solution {
public:
    bool canPermutePalindrome(string s) {
        char ch[128] = {0};
        for(char c : s) {
            ch[c]++;
        }
        int odd = 0;
        for(int i=0;i<128;i++) {
            if(ch[i]&1)
                odd++;
            if(odd>1)
                return false;
        }
        return true;
    }
};