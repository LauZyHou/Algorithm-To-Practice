class Solution {
public:
    int vsum(int a) {
        int ret = 0;
        while(a) {
            ret += a%10;
            a /= 10;
        }
        return ret;
    }

    int countLargestGroup(int n) {
        map<int,int> mp;
        int max = 0;
        int ans = 0;
        for(int i=1;i<=n;i++) {
            int v = vsum(i);
            mp[v]++;
            if(mp[v]>max) {
                max = mp[v];
                ans = 1;
            }
            else if(mp[v]==max) {
                ans++;
            }
        }
        return ans;
    }
};