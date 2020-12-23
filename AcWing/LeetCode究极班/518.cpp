class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> f(amount + 1);
        f[0] = 1; // 最开始背包里没有东西，它的容量也是0，这是一种方案，所以记录1
        for (auto x: coins) { // 枚举所有物品
            for (int i = x; i <= amount; i ++ ) { // 完全背包从小到大枚举体积
                f[i] += f[i - x]; // 当前方案数要加上选了x这么大的物品之后的方案数
            }
        }
        return f[amount];
    }
};