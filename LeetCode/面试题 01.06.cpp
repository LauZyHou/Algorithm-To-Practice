class Solution {
public:
    string compressString(const string& s) {
        int len = s.size();
        if(!len)
            return s;
        string ans;
        char c = s[0];
        int n = 1;
        for(int i=1;i<len;i++) {
            if(s[i]!=c) {
                ans += c + to_string(n);
                c = s[i];
                n = 1;
                if(ans.size()>=len)
                    break;
            }
            else {
                n++;
            }
        }
        ans += c + to_string(n);
        return ans.size()>=len ? s : ans;
    }
};