class Solution {
public:
    int countOdds(int low, int high) {
        int n = high - low + 1;
        if ((low & 1) && (high & 1)) return n / 2 + 1;
        return n / 2;
    }
};