class Solution {
public:
    string modifyString(string s) {
        int len = s.size();
        if(!len)
            return s;
        if(len<2) {
            s[0] = s[0] == '?' ? 'a' : s[0];
            return s; 
        }
        if(s[0]=='?') {
            s[0] = s[1] == '?' ? 'a' : (s[1]-'a'+1)%26+'a';
        }
        if(s[len-1]=='?') {
            s[len-1] = s[len-2] == '?' ? 'a' : (s[len-2]-'a'+1)%26+'a';
        }
        for(int i=1;i<len-1;i++) {
            if(s[i]!='?')
                continue;
            if(s[i+1]=='?') {
                s[i] = (s[i-1]-'a'+1)%26+'a';
            }
            else {
                char c1 = (s[i-1]-'a'+1)%26+'a';
                char c2 = (s[i+1]-'a'+1)%26+'a';
                if(c1==s[i-1] || c1==s[i+1])
                    s[i] = c2;
                else
                    s[i] = c1;
            }
        }
        return s;
    }
};