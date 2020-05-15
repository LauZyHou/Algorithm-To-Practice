class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& vv) {
        int ans = 0;
        int val[100] = {0};
        for(vector<int>& v : vv) {
            int a = v[0];
            int b = v[1];
            if(a > b) {
                ans += val[a*10+b]++;
            }
            else {
                ans += val[b*10+a]++;
            }
        }
        return ans;
    }
};