class Solution {
public:
    int countTriplets(vector<int>& v) {
        int mem[(1 << 16) + 10] = {0};
        int mask = (1 << 16) - 1;
        for (int val : v) {
            int mk = mask ^ val;
            int i = mk;
            while (i) {
                mem[i] ++;
                i = (i - 1) & mk; // mk中的各个1变成0的所有可能
            }
            mem[0] ++; // 全0的情况
        }
        // 两个数相与得到i就有mem[i]种第三个数的可能
        int ans = 0;
        for (int v1 : v) {
            for (int v2 : v) {
                ans += mem[v1 & v2];
            }
        }
        return ans;
    }
};