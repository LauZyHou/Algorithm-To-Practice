class Solution {
public:
    int maxScore(string s) {
        int len = s.size();
        if(!len)
            return 0;
        int zero = 0;
        int one = 0;
        for(char c : s) {
            if(c=='1')
                one++;
        }
        int ans = s[0]=='0' ? one+(++zero) : --one;
        for(int i=1;i<len-1;i++) {
            if(s[i]=='0')
                zero++;
            else
                one--;
            ans = max(ans, zero+one);
        }
        return ans;
    }
};