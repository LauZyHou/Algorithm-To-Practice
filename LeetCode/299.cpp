class Solution {
public:
    string getHint(string s, string g) {
        int ns[10] = {0};
        int ng[10] = {0};
        int a = 0;
        int len = s.size();
        for(int i=0;i<len;i++) {
            ns[s[i]-'0']++;
            ng[g[i]-'0']++;
            if(s[i]==g[i])
                a++;
        }
        int b = -a;
        for(int i=0;i<10;i++)
            b += min(ns[i], ng[i]);
        return to_string(a) + "A" + to_string(b) + "B";
    }
};