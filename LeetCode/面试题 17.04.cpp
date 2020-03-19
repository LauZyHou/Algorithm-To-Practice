class Solution {
public:
    int missingNumber(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        for(auto& x:v) {
            ans ^= x;
        }
        for(int i=0;i<=n;i++)
            ans ^= i;
        return ans;
    }
};