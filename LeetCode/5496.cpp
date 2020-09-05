class Solution {
public:
    int maxCoins(vector<int>& v) {
        sort(v.begin(), v.end());
        int len = v.size();
        int cnt = len/3;
        int ans = 0;
        for(int i=len-2;cnt;i-=2) {
            cnt--;
            ans += v[i];
        }
        return ans;
    }
};