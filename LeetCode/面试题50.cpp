class Solution {
public:
    char firstUniqChar(string s) {
        int ascii[128] = {0};
        for(char c : s) {
            ascii[c]++;
        }
        for(char c : s) {
            if(ascii[c]==1)
                return c;
        }
        return ' ';
    }
};