class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        typedef long long LL;
        int n = a.size();
        // 这样定义f[i][j]使用效果和二维数组一样，但是空间小很多
        vector<unordered_map<LL, int>> f(n);
        int res = 0;
        for (int i = 0; i < n; i ++ ) // 枚举序列结尾数
            for (int k = 0; k < i; k ++ ) { // 枚举前一个数
                LL j = (LL)a[i] - a[k]; // 计算一下公差j
                auto it = f[k].find(j); // 看一下f[k][j]算过没有
                int t = 0; // 这一类方案数，如果f[k][j]不存在那就是0，这里是常数优化一下，防止直接调用f[k][j]导致插多余的元素到哈希表里去，同时也能减少哈希表的查找操作次数
                if (it != f[k].end()) { // 如果已经存在了
                    t = it->second; // 那么方案数就是f[k][j]的数值
                    res += t; // 答案里加上这个f[k][j]
                }
                f[i][j] += t + 1; // 更新f[i][j] = f[k][j] + 1
            }
        return res;
    }
};