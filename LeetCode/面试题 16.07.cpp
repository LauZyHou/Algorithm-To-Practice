#define ull uint64_t

class Solution {
public:
    int maximum(int a, int b) {
        // 看看减完是正是负，就看最高位是1还是0，防止溢出变成ull
        ull diff = ull(a) - ull(b);
        int fu = diff >> (sizeof(ull)*8-1);
        return a*(fu^1) + b*fu;
    }
};