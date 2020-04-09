class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0) {
            return 0;
        }
        int j = s.size()-1;
        int i = 0;
        while(i<j) {
            if(s[i]!=s[j])
                return 2;
            i++,j--;
        }
        return 1;
    }
};