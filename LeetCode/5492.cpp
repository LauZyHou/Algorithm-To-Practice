class Solution {
public:
    int numWays(string s) {
        const int mod = 1e9+7;
        long long len = s.size();
        int cnt = 0;
        for(int i=0;i<len;i++) {
            if(s[i]=='1')
                cnt++;
        }
        if(cnt%3!=0 || len<3) {
            return 0;
        }
        if(cnt == 0) { // C(len-1, 2)
            return (len-1) * (len-2) / 2 % mod;
        }
        int val = cnt/3;
        int start = 0;
        int end = len-1;

        int c = 0;
        for(start=0;c<val;start++) {
            if(s[start]=='1')
                c++;
        }
        c = 0;
        for(end=len-1;c<val;end--) {
            if(s[end]=='1')
                c++;
        }
        long long left = 0;
        while(s[start++]=='0')
            left++;
        long long right = 0;
        while(s[end--]=='0')
            right++;
        return (left+1)*(right+1) % mod;
    }
};