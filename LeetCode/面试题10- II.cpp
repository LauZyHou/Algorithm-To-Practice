class Solution {
private:
    const int m = 1e9+7;
public:
    int numWays(int n) {
        int v[2] = {1,1};
        if(n<2)
            return v[n];
        for(int i=2;i<=n;i++) {
            int t = (v[0]+v[1]) % m;
            v[0] = v[1];
            v[1] = t;
        }
        return v[1];
    }
};