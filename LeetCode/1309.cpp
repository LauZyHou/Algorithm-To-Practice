class Solution {
public:
    string freqAlphabets(string s) {
        int len = s.size();
        char* ans = new char[len];
        int j = 0;
        for(int i=0;i<len;) {
            if(i==len-1) {
                ans[j++] = s[i]-'1'+'a';
                break;
            }
            if(i+2<len && s[i+2]=='#') {
                ans[j++] = (s[i]-'0')*10 + s[i+1]-'0' - 10 + 'j';
                i += 3;
            } else {
                ans[j++] = s[i]-'1'+'a';
                i++;
            }
        }
        ans[j] = '\0';
        return string(ans);
    }
};