class Solution {
public:
    string sortString(string s) {
        int len = s.size();
        if(!len)
            return "";
        int n[26] = {0};
        for(auto x:s)
            n[x-'a']++;
        int j = 0; // anslen
        char* ans = new char[len+1];
        while(j!=len) {
            for(int i=0;i<26;i++) {
                if(n[i]) {
                    ans[j++] = i+'a';
                    n[i]--;
                }
            }
            for(int i=25;i>=0;i--) {
                if(n[i]) {
                    ans[j++] = i+'a';
                    n[i]--;
                }
            }
        }
        ans[len] = '\0';
        return string(ans);
    }
};