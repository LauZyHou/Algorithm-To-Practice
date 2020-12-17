class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        typedef long long LL;
        LL x = 1; // 当前所能表示的区间的右边界，语义是[0, x)
        int i = 0, res = 0; // i从0开始枚举，res表示加入的数的个数
        while (x <= n) {
            // 如果当前待加入的数是再能表示的区间范围内的，那么实际上区间上每个数加nums[i]就都能表示了
            if (i < nums.size() && nums[i] <= x) x += nums[i ++ ]; // 由于这个数用过了，所以i ++
            // 如果当前待加入的数y是大于[0, x)这个区间范围的，那么加入后还是会导致[x, y)是留空的，所以加入一个数x
            else {
                x += x;
                res ++ ;
            }
        }
        return res;
    }
};