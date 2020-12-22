class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i <= 30; i ++ ) { // 正数最高位一定是0所以不用看最高位了
            // 用x表示0的个数，y表示1的个数
            int x = 0, y = 0;
            for (auto v: nums)
                if (v >> i & 1) x ++ ;
                else y ++ ;
            res += x * y;
        }
        return res;
    }
};