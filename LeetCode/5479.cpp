class Solution {
public:
    string thousandSeparator(int n) {
        string ns = to_string(n);
        int len = ns.size();
        int newlen = len + (len/3) - (len%3==0);
        char* cs = new char[newlen+1];
        cs[newlen] = '\0';
        int cnt = 0;
        int j = newlen-1;
        for(int i=len-1;i>=0;i--) {
            cnt++;
            cs[j--] = ns[i];
            if(cnt == 3 && i>0) {
                cnt = 0;
                cs[j--] = '.';
            }
        }
        return string(cs);
    }
};