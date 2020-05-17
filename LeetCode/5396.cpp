class Solution {
public:
    int maxPower(string s) {
        int len = s.size();
        if(!len)
            return 0;
        int ans = 1;
        int t = 1;
        char c = s[0];
        for(int i=1;i<len;i++) {
            if(s[i]==c) {
                t++;
                if(t > ans)
                    ans = t;
            }
            else {
                c = s[i];
                t = 1;
            }
        }
        return ans;
    }
};