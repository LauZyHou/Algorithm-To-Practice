class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0; // 累计的l减去r的数目
        int ans = 0;
        for(char c:s) {
            if(c=='L')
                cnt++;
            else
                cnt--;
            if(cnt==0)
                ans++;
        }
        return ans;
    }
};