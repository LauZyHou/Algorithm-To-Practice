class Solution {
public:
    int distanceBetweenBusStops(vector<int>& v, int s, int d) {
        int len = v.size();
        int ans = 0;
        for(int i=s%len;i%len!=d%len;i++) {
            ans += v[i%len];
        }
        return min(ans, accumulate(v.begin(), v.end(), 0)-ans);
    }
};