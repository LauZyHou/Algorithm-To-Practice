class Solution {
public:
    int insertBits(int n, int m, int i, int j) {
        int mask = ((1<<j-i+1)-1)<<i;
        return (n&~mask)|(m<<i);
    }
};