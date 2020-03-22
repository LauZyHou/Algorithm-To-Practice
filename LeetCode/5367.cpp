class Solution {
public:
    string longestPrefix(string s) {
        int len = s.size();
        string_view pre = s;
        string_view suf = s;
        for(int i=1;i<len;i++) {
            pre.remove_suffix(1);
            suf.remove_prefix(1);
            if(pre==suf)
                return (string)pre;
        }
        return "";
    }
};