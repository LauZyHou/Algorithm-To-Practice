class Solution {
public:
    string reformat(string s) {
        int letter = 0;
        int number = 0;
        for(char c:s) {
            if(c<='9' && c>='0')
                number++;
            else
                letter++;
        }
        if(abs(number-letter)>1)
            return "";
        int l=0, n=0;
        if(letter<=number)
            l = 1;
        else
            n = 1;
        string ans(s.size(), '\0');
        for(char c:s) {
            if(c<='9' && c>='0') {
                ans[n] = c;
                n += 2;
            }
            else{
                ans[l] = c;
                l += 2;
            }
        }
        return ans;
    }
};