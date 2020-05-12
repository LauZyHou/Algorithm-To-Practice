class Solution {
public:
    int convertInteger(int A, int B) {
        unsigned int t = A ^ B;
        int ans = 0;
        while(t) {
            t &= t-1;
            ans++;
        }
        return ans;
    }
};