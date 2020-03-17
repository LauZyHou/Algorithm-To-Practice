class Solution {
public:
    int exchangeBits(int num) {
        // (1010)8次得到偶数位，(0101)8次得到奇数位
        return (0xaaaaaaaa & num)>>1 | (0x55555555 & num)<<1;
    }
};