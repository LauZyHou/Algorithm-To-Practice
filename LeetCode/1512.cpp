class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int val[101] = {0};
        for(int n:nums) {
            val[n]++;
        }
        int ans = 0;
        for(int i=1;i<=100;i++) {
            ans += val[i]*(val[i]-1)/2;
        }
        return ans;
    }
};