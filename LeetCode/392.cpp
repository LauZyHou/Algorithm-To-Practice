class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.size();
        if(!slen)
            return true;
        int tlen = t.size();
        if(tlen < slen)
            return false;
        int j=0;
        for(int i=0;i<tlen;i++) {
            if(t[i]==s[j])
                j++;
            if(j==slen)
                return true;
        }
        return false;
    }
};